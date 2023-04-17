#include "Arduino.h"
#include "soc/soc.h"           // Disable brownour problems
#include "soc/rtc_cntl_reg.h"  // Disable brownour problems
#include "driver/rtc_io.h"
#include <WiFi.h>
#include <esp_now.h>
#include "FS.h"                // SD Card ESP32
#include "SD_MMC.h"            // SD Card ESP32
#include "esp_camera.h"
#include <esp_wifi.h>

esp_now_peer_info_t slave;

#define fileDatainMessage 240.0
#define CHANNEL 1
#define PRINTSCANRESULTS 0
#define DELETEBEFOREPAIR 0

// for esp now connect
unsigned long lastConnectNowAttempt;
unsigned long nextConnectNowGap = 1000;
bool isPaired = 0;
bool isConnected = 0;

// for photo name
byte takeNextPhotoFlag = 0;
byte recognizeFaceFlag = 0;
int pictureNumber = 1;

// for photo transmit
int currentTransmitCurrentPosition = 0;
int currentTransmitTotalPackages = 0;
byte sendNextPackageFlag = 0;
byte byteTransmitFlag = 0;
uint8_t lastRecognizeID = 200;

String fileName = "";

uint64_t ss;
uint64_t lastCaptureTime = 0;
uint64_t recognizeTime = 0;

// WARNING!!! Make sure that you have either selected ESP32 Wrover Module,
//            or another board which has PSRAM enabled
//

// Select camera model
//#define CAMERA_MODEL_WROVER_KIT
//#define CAMERA_MODEL_ESP_EYE
//#define CAMERA_MODEL_M5STACK_PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE
#define CAMERA_MODEL_AI_THINKER

#include "camera_pins.h"

const char* ssid = "admin";
const char* password = "1234567890";

const char* ap_ssid = "FaceRecognitionLock";
const char* ap_password = "123456789";

void startCameraServer();
int detect();
int recognizeFace();
uint8_t doorReturn();
void taskDelay(uint64_t timeDelay);
bool is_streaming();

int door_return = 0;

void InitESPNow() {
  WiFi.disconnect();
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESPNow Init Success");
  }
  else {
    Serial.println("ESPNow Init Failed");
    // Retry InitESPNow, add a counte and then restart?
    // InitESPNow();
    // or Simply Restart
    //ESP.restart();
  }
}


// Check if the slave is already paired with the master.
// If not, pair the slave with master
bool manageSlave() {
  if (slave.channel == CHANNEL) {
    if (DELETEBEFOREPAIR) {
      deletePeer();
    }

    Serial.print("Slave Status: ");
    // check if the peer exists
    bool exists = esp_now_is_peer_exist(slave.peer_addr);
    if ( exists) {
      // Slave already paired.
      Serial.println("Already Paired");
      return true;
    } else {
      // Slave not paired, attempt pair
      esp_err_t addStatus = esp_now_add_peer(&slave);
      if (addStatus == ESP_OK) {
        // Pair success
        Serial.println("Pair success");
        return true;
      } else if (addStatus == ESP_ERR_ESPNOW_NOT_INIT) {
        // How did we get so far!!
        Serial.println("ESPNOW Not Init");
        return false;
      } else if (addStatus == ESP_ERR_ESPNOW_ARG) {
        Serial.println("Invalid Argument");
        return false;
      } else if (addStatus == ESP_ERR_ESPNOW_FULL) {
        Serial.println("Peer list full");
        return false;
      } else if (addStatus == ESP_ERR_ESPNOW_NO_MEM) {
        Serial.println("Out of memory");
        return false;
      } else if (addStatus == ESP_ERR_ESPNOW_EXIST) {
        Serial.println("Peer Exists");
        return true;
      } else {
        Serial.println("Not sure what happened");
        return false;
      }
    }
  } else {
    // No slave found to process
    Serial.println("No Slave found to process");
    return false;
  }
}

void deletePeer() {
  esp_err_t delStatus = esp_now_del_peer(slave.peer_addr);
  Serial.print("Slave Delete Status: ");
  if (delStatus == ESP_OK) {
    // Delete success
    Serial.println("Success");
  } else if (delStatus == ESP_ERR_ESPNOW_NOT_INIT) {
    // How did we get so far!!
    Serial.println("ESPNOW Not Init");
  } else if (delStatus == ESP_ERR_ESPNOW_ARG) {
    Serial.println("Invalid Argument");
  } else if (delStatus == ESP_ERR_ESPNOW_NOT_FOUND) {
    Serial.println("Peer not found.");
  } else {
    Serial.println("Not sure what happened");
  }
}

// Scan for slaves in AP mode
void ScanForSlave() {
  int8_t scanResults = WiFi.scanNetworks();
  // reset on each scan
  bool slaveFound = 0;
  memset(&slave, 0, sizeof(slave));

  Serial.println("");
  if (scanResults == 0) {
    Serial.println("No WiFi devices in AP Mode found");
  } else {
    Serial.print("Found "); Serial.print(scanResults); Serial.println(" devices ");
    for (int i = 0; i < scanResults; ++i) {
      // Print SSID and RSSI for each device found
      String SSID = WiFi.SSID(i);
      int32_t RSSI = WiFi.RSSI(i);
      String BSSIDstr = WiFi.BSSIDstr(i);

      if (PRINTSCANRESULTS) {
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(SSID);
        Serial.print(" (");
        Serial.print(RSSI);
        Serial.print(")");
        Serial.println("");
      }
      delay(10);
      // Check if the current device starts with `Slave`
      if (SSID.indexOf("Slave") == 0) {
        // SSID of interest
        Serial.println("Found a Slave.");
        Serial.print(i + 1); Serial.print(": "); Serial.print(SSID); Serial.print(" ["); Serial.print(BSSIDstr); Serial.print("]"); Serial.print(" ("); Serial.print(RSSI); Serial.print(")"); Serial.println("");
        // Get BSSID => Mac Address of the Slave
        int mac[6];
        if ( 6 == sscanf(BSSIDstr.c_str(), "%x:%x:%x:%x:%x:%x",  &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5] ) ) {
          for (int ii = 0; ii < 6; ++ii ) {
            slave.peer_addr[ii] = (uint8_t) mac[ii];
          }
        }

        slave.channel = CHANNEL; // pick a channel
        slave.encrypt = 0; // no encryption

        slaveFound = 1;
        // we are planning to have only one slave in this example;
        // Hence, break after we find one, to be a bit efficient
        break;
      }
    }
  }

  if (slaveFound) {
 Serial.println("Slave Found, processing..");
    if (slave.channel == CHANNEL) { // check if slave channel is defined
      // `slave` is defined
      // Add slave as peer if it has not been added already
      isPaired = manageSlave();
      if (isPaired) {
        Serial.println("Slave pair success!");
      } else {
        // slave pair failed
        Serial.println("Slave pair failed!");
      }
    }
  } else {
    Serial.println("Slave Not Found, trying again.");
  }

  // clean up ram
  WiFi.scanDelete();
}



/* ***************************************************************** */
/* START TRASMIT                                                     */
/* ***************************************************************** */
void startTransmit()
{
  Serial.println("Starting transmit");
  fs::FS &fs = SD_MMC;
  File file = fs.open(fileName.c_str(), FILE_READ);
  if (!file) {
    Serial.println("Failed to open file in writing mode");
    return;
  }
  Serial.println(file.size());
  int fileSize = file.size();
  file.close();
  currentTransmitCurrentPosition = 0;
  currentTransmitTotalPackages = ceil(fileSize / fileDatainMessage);
  Serial.println(currentTransmitTotalPackages);
  uint8_t message[] = {0x01, currentTransmitTotalPackages >> 8, (byte) currentTransmitTotalPackages};
  sendData(message, sizeof(message));
}

/* ***************************************************************** */
/* SEND NEXT PACKAGE                                                 */
/* ***************************************************************** */
void sendNextPackage()
{
  // claer the flag
  sendNextPackageFlag = 0;

  // if got to AFTER the last package
  if (currentTransmitCurrentPosition == currentTransmitTotalPackages)
  {
    currentTransmitCurrentPosition = 0;
    currentTransmitTotalPackages = 0;
    Serial.println("Done submiting files");
    //transmitCompletedFlag = 1;
    //takeNextPhotoFlag = 1;
    return;
  } //end if

  //first read the data.
  fs::FS &fs = SD_MMC;
  File file = fs.open(fileName.c_str(), FILE_READ);
  if (!file) {
    Serial.println("Failed to open file in writing mode");
    return;
  }

  // set array size.
  int fileDataSize = fileDatainMessage;
  // if its the last package - we adjust the size !!!
  if (currentTransmitCurrentPosition == currentTransmitTotalPackages - 1)
  {
    Serial.println("*************************");
    Serial.println(file.size());
    Serial.println(currentTransmitTotalPackages - 1);
    Serial.println((currentTransmitTotalPackages - 1)*fileDatainMessage);
    fileDataSize = file.size() - ((currentTransmitTotalPackages - 1) * fileDatainMessage);
  }

  //Serial.println("fileDataSize=" + String(fileDataSize));

  // define message array
  uint8_t messageArray[fileDataSize + 3];
  messageArray[0] = 0x02;


  file.seek(currentTransmitCurrentPosition * fileDatainMessage);
  currentTransmitCurrentPosition++; // set to current (after seek!!!)
  //Serial.println("PACKAGE - " + String(currentTransmitCurrentPosition));

  messageArray[1] = currentTransmitCurrentPosition >> 8;
  messageArray[2] = (byte) currentTransmitCurrentPosition;
  for (int i = 0; i < fileDataSize; i++)
  {
    if (file.available())
    {
      messageArray[3 + i] = file.read();
    } //end if available
    else
    {
      Serial.println("END !!!");
      break;
    }
  } //end for

  sendData(messageArray, sizeof(messageArray));
  file.close();
}

//Send sigle data
void byteTransmit(int dat){
  uint8_t message[] = {0x03, dat>>8, (byte)dat};

  Serial.printf("Sending control information: %d\n",dat);
  sendData(message, sizeof(message));
  byteTransmitFlag = 1;
}

// send data array for pictures
void sendData(uint8_t * dataArray, uint8_t dataArrayLength) {
  const uint8_t *peer_addr = slave.peer_addr;
  //Serial.print("Sending: "); Serial.println(data);
  //Serial.print("length: "); Serial.println(dataArrayLength);

  esp_err_t result = esp_now_send(peer_addr, dataArray, dataArrayLength);
  //Serial.print("Send Status: ");
  if (result == ESP_OK) {
    //Serial.println("Success");
  } else if (result == ESP_ERR_ESPNOW_NOT_INIT) {
    // How did we get so far!!
    Serial.println("ESPNOW not Init.");
  } else if (result == ESP_ERR_ESPNOW_ARG) {
    Serial.println("Invalid Argument");
  } else if (result == ESP_ERR_ESPNOW_INTERNAL) {
    Serial.println("Internal Error");
  } else if (result == ESP_ERR_ESPNOW_NO_MEM) {
    Serial.println("ESP_ERR_ESPNOW_NO_MEM");
  } else if (result == ESP_ERR_ESPNOW_NOT_FOUND) {
    Serial.println("Peer not found.");
  } else {
    Serial.println("Not sure what happened");
  }
}

// callback when data is sent from Master to Slave
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
if(byteTransmitFlag){
  byteTransmitFlag = 0;
}
else if (currentTransmitTotalPackages)
  {
    sendNextPackageFlag = 1;
    // if nto suecess 0 resent the last one
    if (status != ESP_NOW_SEND_SUCCESS)
      currentTransmitCurrentPosition--;
  } //end if
 
}

/* ***************************************************************** */
/* INIT SD                                                           */
/* ***************************************************************** */
void initSD()
{
  Serial.println("Starting SD Card");
  if (!SD_MMC.begin("/sdcard", true)) {
    Serial.println("SD Card Mount Failed");
    return;
  }

  uint8_t cardType = SD_MMC.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No SD Card attached");
    return;
  }
}

void capture(){
  takeNextPhotoFlag = 0;
//  sensor_t *s = esp_camera_sensor_get();
//  s->set_framesize(s, FRAMESIZE_HQVGA);
  //s->set_framesize(s, FRAMESIZE_QVGA);
  delay(100);
  
  camera_fb_t *fb = NULL;
  fb = esp_camera_fb_get();

  if (!fb) {
    Serial.println("Camera capture failed");
    return;
  }
  // Path where new picture will be saved in SD Card
  String path = "/picture" + String(pictureNumber) + ".jpg";

  fs::FS &fs = SD_MMC;
  Serial.printf("Picture file name: %s\n", path.c_str());

  fs.remove(path.c_str());

  File file = fs.open(path.c_str(), FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file in writing mode");
  }
  else {
    file.write(fb->buf, fb->len); // payload (image), payload length
    Serial.printf("Saved file to path: %s\n", path.c_str());
  }
  file.close();
  esp_camera_fb_return(fb);
  fb = NULL;
  fileName = path;
  if (isPaired)
    startTransmit();

  pictureNumber++;
}

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  //init with high specs to pre-allocate larger buffers
  if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

#if defined(CAMERA_MODEL_ESP_EYE)
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
#endif

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
  //initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1);//flip it back
    s->set_brightness(s, 1);//up the blightness just a bit
    s->set_saturation(s, -2);//lower the saturation
  }
  //drop down frame size for higher initial frame rate
  s->set_framesize(s, FRAMESIZE_CIF);
  s->set_hmirror(s, 1);
  //s->set_brightness(s,1);

#if defined(CAMERA_MODEL_M5STACK_WIDE)
  s->set_vflip(s, 1);
  s->set_hmirror(s, 1);
#endif
 
initSD();

taskDelay(1000);
 WiFi.mode(WIFI_MODE_APSTA);
 WiFi.softAP(ap_ssid,ap_password);

  Serial.print("Access Point IP: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("' to connect");

 // Init ESPNow with a fallback logic
 // WiFi.disconnect();
  InitESPNow();
  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);  
  delay(100);

  startCameraServer();

 Serial.println("Camera Ready!");
  delay(40000);
  Serial.println("Motion Sensor Ready!");
}

void loop() {
  if (!isPaired  && lastConnectNowAttempt + nextConnectNowGap < millis())
  {
    Serial.println("NOT CONNECTED -> TRY TO CONNECT");
    ScanForSlave();
    // if we connected
    if (isPaired)
    {
      Serial.println("ESP-NOW CONNECTED\n");
    }
    else
    {
      nextConnectNowGap *= 2; // dbl the gap
    }

    // save last attmpe
    lastConnectNowAttempt = millis();
  }

  if(detect() && !currentTransmitTotalPackages && !sendNextPackageFlag) {
  takeNextPhotoFlag = 1;
  recognizeFaceFlag = 1;
} //else connectWiFi();

  door_return = doorReturn();
  if(door_return && !currentTransmitTotalPackages && !sendNextPackageFlag) {
   byteTransmit(door_return);
  // door_return = 0;
  } //else connectWiFi();

 if(recognizeFaceFlag && !is_streaming() && !sendNextPackageFlag){
  recognizeFaceFlag = 0;
  if((millis()-recognizeTime)>500){
    recognizeTime = millis();
   uint8_t recognizeID = recognizeFace();
   if(recognizeID != lastRecognizeID){
    byteTransmit(recognizeID);
    lastRecognizeID = recognizeID;
   }
  }
 }

// if the sendNextPackageFlag is set
  if (sendNextPackageFlag) {
    sendNextPackage();
  }

  // if takeNextPhotoFlag is set
  if (takeNextPhotoFlag && !is_streaming()) {
    takeNextPhotoFlag = 0;
    if((millis() - lastCaptureTime)>5000){
    lastCaptureTime = millis();
    capture();
//  taskDelay(3000000); //2sec delay
    }
  }
}
