// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Arduino.h"
#include "esp_http_server.h"
#include "esp_timer.h"
#include "camera_index.h"
#include "fb_gfx.h"
#include "fd_forward.h"
#include "fr_forward.h"
#include "fr_flash.h"
#include "img_converters.h"
#include "esp_camera.h"
#include "sensor.h"

#include "FS.h"                // SD Card ESP32
#include "SD_MMC.h"            // SD Card ESP32

#define DEFAULT_wwwid "admin"
#define DEFAULT_wwwpass "admin"

#define ENROLL_CONFIRM_TIMES 5
#define FACE_ID_SAVE_NUMBER 7
#define MOTION_SENSE_PIN 13
#define BOARD_FLASH_PIN 4

#define lightPin 33
//#define CONTROL_PIN 12

#define FACE_COLOR_WHITE  0x00FFFFFF
#define FACE_COLOR_BLACK  0x00000000
#define FACE_COLOR_RED    0x000000FF
#define FACE_COLOR_GREEN  0x0000FF00
#define FACE_COLOR_BLUE   0x00FF0000
#define FACE_COLOR_YELLOW (FACE_COLOR_RED | FACE_COLOR_GREEN)
#define FACE_COLOR_CYAN   (FACE_COLOR_BLUE | FACE_COLOR_GREEN)
#define FACE_COLOR_PURPLE (FACE_COLOR_BLUE | FACE_COLOR_RED)

#define FACE_FOUND_VALUE 250
#define DOOR_RETURN_VALUE 251
#define FACE_NOT_ALIGNED_VALUE 252
#define NO_FACE_VALUE 253

bool authentified = false;
String wwwid_;
String wwwpass_;
char nameVal[32] = {0,};


typedef struct {
  httpd_req_t *req;
  size_t len;
} jpg_chunking_t;

#define PART_BOUNDARY "123456789000000000000987654321"
static const char* _STREAM_CONTENT_TYPE = "multipart/x-mixed-replace;boundary=" PART_BOUNDARY;
static const char* _STREAM_BOUNDARY = "\r\n--" PART_BOUNDARY "\r\n";
static const char* _STREAM_PART = "Content-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n";

httpd_handle_t stream_httpd = NULL;
httpd_handle_t index_httpd = NULL;

const char * names[] = {"/0.txt", "/1.txt", "/2.txt", "/3.txt", "/4.txt", "/5.txt"};


String readFile(fs::FS &fs, const char * path){
    Serial.printf("Reading file: %s\n", path);

    File file = fs.open(path);
    if(!file){
        Serial.println("Failed to open file for reading");
        return String();
    }

    Serial.print("Read from file: ");
    String fileContent;
    while(file.available()){
       fileContent+=String((char)file.read());
    }
    file.close();
    Serial.println(fileContent);
    return fileContent;
}

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
}

void deleteFile(fs::FS &fs, const char * path){
    Serial.printf("Deleting file: %s\n", path);
    if(fs.remove(path)){
        Serial.println("File deleted");
    } else {
        Serial.println("Delete failed");
    }
}

static mtmn_config_t mtmn_config = mtmn_init_config();
static int8_t detection_enabled = 0;
static int8_t recognition_enabled = 0;
static int8_t is_enrolling = 0;
static int8_t face_delete = 0;
static int8_t is_door_opened = 0;
static int8_t all_face_delete = 0;
static face_id_list id_list = {0};
bool is_connected = false;
bool lightflag = false;

uint64_t tt;

static void rgb_print(dl_matrix3du_t *image_matrix, uint32_t color, const char * str){
    fb_data_t fb;
    fb.width = image_matrix->w;
    fb.height = image_matrix->h;
    fb.data = image_matrix->item;
    fb.bytes_per_pixel = 3;
    fb.format = FB_BGR888;
    fb_gfx_print(&fb, (fb.width - (strlen(str) * 14)) / 2, 10, color, str);
}

static int rgb_printf(dl_matrix3du_t *image_matrix, uint32_t color, const char *format, ...) {
  char loc_buf[64];
  char * temp = loc_buf;
  int len;
  va_list arg;
  va_list copy;
  va_start(arg, format);
  va_copy(copy, arg);
  len = vsnprintf(loc_buf, sizeof(loc_buf), format, arg);
  va_end(copy);
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      return 0;
    }
  }
  vsnprintf(temp, len + 1, format, arg);
  va_end(arg);
  rgb_print(image_matrix, color, temp);
  if (len > 64) {
    free(temp);
  }
  return len;
}

static void draw_face_boxes(dl_matrix3du_t *image_matrix, box_array_t *boxes, int face_id) {
  int x, y, w, h, i;
  uint32_t color = FACE_COLOR_YELLOW;
  if (face_id < 0) {
    color = FACE_COLOR_RED;
  } else if (face_id > 0) {
    color = FACE_COLOR_GREEN;
  }
  fb_data_t fb;
  fb.width = image_matrix->w;
  fb.height = image_matrix->h;
  fb.data = image_matrix->item;
  fb.bytes_per_pixel = 3;
  fb.format = FB_BGR888;
  for (i = 0; i < boxes->len; i++) {
    // rectangle box
    x = (int)boxes->box[i].box_p[0];
    y = (int)boxes->box[i].box_p[1];
    w = (int)boxes->box[i].box_p[2] - x + 1;
    h = (int)boxes->box[i].box_p[3] - y + 1;
    fb_gfx_drawFastHLine(&fb, x, y, w, color);
    fb_gfx_drawFastHLine(&fb, x, y + h - 1, w, color);
    fb_gfx_drawFastVLine(&fb, x, y, h, color);
    fb_gfx_drawFastVLine(&fb, x + w - 1, y, h, color);
#if 0
    // landmark
    int x0, y0, j;
    for (j = 0; j < 10; j += 2) {
      x0 = (int)boxes->landmark[i].landmark_p[j];
      y0 = (int)boxes->landmark[i].landmark_p[j + 1];
      fb_gfx_fillRect(&fb, x0, y0, 3, 3, color);
    }
#endif
  }
}

//returns 1 to 7 for faces, 255 for no face, 250 for face not aligned
static int run_face_recognition(dl_matrix3du_t *image_matrix, box_array_t *net_boxes) {
  dl_matrix3du_t *aligned_face = NULL;
  int matched_id = -1;
  //allocate a 3d matrix to aligned_face, returns 0 if successful
  aligned_face = dl_matrix3du_alloc(1, FACE_WIDTH, FACE_HEIGHT, 3);
  if (!aligned_face) {
    Serial.println("Could not allocate face recognition buffer");
    return matched_id;
  }
  //check if a face is detected
  if (align_face(net_boxes, image_matrix, aligned_face) == ESP_OK) {
    
    matched_id = recognize_face(&id_list, aligned_face);
    int enrolled_count = readFile(SD_MMC, names[0]).toInt();
    Serial.printf("Enrolled face count: %u\n", enrolled_count);

    if(enrolled_count>=5){
      Serial.printf("Maximum enrolled face reached");
      rgb_print(image_matrix, FACE_COLOR_RED, "MAX FACE ENROLL NUMBER REACHED!");
      return matched_id;
    }
    
    if (is_enrolling == 1) {
      //check if face has been previously enrolled
      if(matched_id<0){
      //enroll a face
      int8_t left_sample_face = enroll_face_id_to_flash(&id_list, aligned_face);
      if (left_sample_face == (ENROLL_CONFIRM_TIMES - 1)) {
        Serial.printf("Enrolling Face ID: %d\n", id_list.tail);
        }
      Serial.printf("Enrolling Face ID: %d sample %d\n", id_list.tail, ENROLL_CONFIRM_TIMES - left_sample_face);
      rgb_printf(image_matrix, FACE_COLOR_CYAN, "ID[%u] Sample[%u]", id_list.tail, ENROLL_CONFIRM_TIMES - left_sample_face);
             
      if (left_sample_face == 0) {
        is_enrolling = 0;
        Serial.printf("Enrolled Face ID: %d\n", id_list.tail);
        //writeFile(SD_MMC, names[0], (const char*)id_list.tail);
        writeFile(SD_MMC, names[id_list.tail], nameVal);
        }
       } else{
        is_enrolling = 0;
       }
      } else {
      if (matched_id>=0) {
        String name_id = readFile(SD_MMC, names[id_list.tail]);
        Serial.printf("Match Face ID: %u\nName: %s\n", matched_id, name_id.c_str());
        rgb_printf(image_matrix, FACE_COLOR_GREEN, "Hello %s\n", name_id.c_str());
      } else {
        Serial.println("No Match Found");
        rgb_print(image_matrix, FACE_COLOR_RED, "INTRUDER DETECTED!");
        matched_id = NO_FACE_VALUE;
      }
   }
  } else {
    Serial.println("Face Not Aligned");
    //rgb_print(image_matrix, FACE_COLOR_YELLOW, "Human Detected");
    matched_id = FACE_NOT_ALIGNED_VALUE;
  }

  dl_matrix3du_free(aligned_face);
  return matched_id;
}

static esp_err_t handleLogin(httpd_req_t *req){
  char  *buf;
  char *value;
  size_t buf_len;
  char user_[32] = {0,};
  char pass_[32] = {0,};

  buf_len = httpd_req_get_url_query_len(req) + 1;
  if (buf_len > 1) {
    buf = (char*)malloc(buf_len);
    if (!buf) {
      httpd_resp_send_500(req);
      return ESP_FAIL;
    }
   Serial.println("Trying to Login"); 
   if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) {
    if ((httpd_query_key_value(buf, "LOGINUSER", user_, sizeof(user_))== ESP_OK) && 
     (httpd_query_key_value(buf, "LOGINPASS", pass_, sizeof(pass_))== ESP_OK)) {
     } else {
      free(buf);
      httpd_resp_send_404(req);
      return ESP_FAIL;
     }
    }else {
    httpd_resp_send_404(req);
    return ESP_FAIL;
   free(buf);
    }
 }else {
        httpd_resp_send_404(req);
        return ESP_FAIL;
    }
  Serial.println(user_);
  Serial.println(pass_);

  if(!strcmp(user_, wwwid_.c_str()) && !strcmp(pass_, wwwpass_.c_str())){
    Serial.print("Log in Successful:");
   authentified = true;
   Serial.println(authentified);
    httpd_resp_set_hdr(req, "Cache-Control", "no-cache"); 
    httpd_resp_set_hdr(req, "Location", "/");
    httpd_resp_set_status(req, "301 Moved Permanently");
    httpd_resp_set_type(req, "text/html");
    return httpd_resp_send(req, NULL, 0);  
  } else {
    authentified = false;
    httpd_resp_set_hdr(req, "Cache-Control", "no-cache"); 
    httpd_resp_set_hdr(req, "Location", "/login.html");
    httpd_resp_set_status(req, "301 Moved Permanently");
    httpd_resp_set_type(req, "text/html");
    return httpd_resp_send(req, NULL, 0);  
  }
}   

static esp_err_t logout_handler(httpd_req_t *req){
  authentified = false;
  httpd_resp_set_hdr(req, "Location", "/login.html");
  httpd_resp_set_hdr(req, "Cache-Control", "no-cache");
  httpd_resp_set_type(req, "text/html");
  httpd_resp_set_status(req, "301 Moved Permanently");
  return httpd_resp_send(req, NULL, 0);
}

static size_t jpg_encode_stream(void * arg, size_t index, const void* data, size_t len) {
  jpg_chunking_t *j = (jpg_chunking_t *)arg;
  if (!index) {
    j->len = 0;
  }
  if (httpd_resp_send_chunk(j->req, (const char *)data, len) != ESP_OK) {
    return 0;
  }
  j->len += len;
  return len;
}

static esp_err_t stream_handler(httpd_req_t *req) {
  camera_fb_t * fb = NULL;
  esp_err_t res = ESP_OK;
  size_t _jpg_buf_len = 0;
  uint8_t * _jpg_buf = NULL;
  char * part_buf[64];
  dl_matrix3du_t *image_matrix = NULL;
  bool detected = false;
  int face_id = 0;

  res = httpd_resp_set_type(req, _STREAM_CONTENT_TYPE);
  if (res != ESP_OK) {
    return res;
  }

  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
  Serial.println("Start of Streaming");
  while (true) {
    is_connected = true;
    detected = false;
    face_id = 0;
    fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Camera capture failed");
      res = ESP_FAIL;
    } else {
       if (!detection_enabled || fb->width > 400) {
        if (fb->format != PIXFORMAT_JPEG) {
          bool jpeg_converted = frame2jpg(fb, 80, &_jpg_buf, &_jpg_buf_len);
          esp_camera_fb_return(fb);
          fb = NULL;
          if (!jpeg_converted) {
            Serial.println("JPEG compression failed");
            res = ESP_FAIL;
          }
        } else {
          _jpg_buf_len = fb->len;
          _jpg_buf = fb->buf;
        }
      } else {

        image_matrix = dl_matrix3du_alloc(1, fb->width, fb->height, 3);

        if (!image_matrix) {
          Serial.println("dl_matrix3du_alloc failed");
          res = ESP_FAIL;
        } else {
          if (!fmt2rgb888(fb->buf, fb->len, fb->format, image_matrix->item)) {
            Serial.println("fmt2rgb888 failed");
            res = ESP_FAIL;
          } else {
            box_array_t *net_boxes = NULL;
            if (detection_enabled) {
              net_boxes = face_detect(image_matrix, &mtmn_config);
            }
            if (net_boxes || fb->format != PIXFORMAT_JPEG) {
              if (net_boxes) {
                detected = true;
                if (recognition_enabled) {
                  face_id = run_face_recognition(image_matrix, net_boxes);
                }
                draw_face_boxes(image_matrix, net_boxes, face_id);
                free(net_boxes->score);
                free(net_boxes->box);
                free(net_boxes->landmark);
                free(net_boxes);
              }
              if (!fmt2jpg(image_matrix->item, fb->width * fb->height * 3, fb->width, fb->height, PIXFORMAT_RGB888, 90, &_jpg_buf, &_jpg_buf_len)) {
                Serial.println("fmt2jpg failed");
                res = ESP_FAIL;
              }
              esp_camera_fb_return(fb);
              fb = NULL;
            } else {
              _jpg_buf = fb->buf;
              _jpg_buf_len = fb->len;
            }
          }
          dl_matrix3du_free(image_matrix);
        }
      }
    }
    if (res == ESP_OK) {
      size_t hlen = snprintf((char *)part_buf, 64, _STREAM_PART, _jpg_buf_len);
      res = httpd_resp_send_chunk(req, (const char *)part_buf, hlen);
    }
    if (res == ESP_OK) {
      res = httpd_resp_send_chunk(req, (const char *)_jpg_buf, _jpg_buf_len);
    }
    if (res == ESP_OK) {
      res = httpd_resp_send_chunk(req, _STREAM_BOUNDARY, strlen(_STREAM_BOUNDARY));
    }
    if (fb) {
      esp_camera_fb_return(fb);
      fb = NULL;
      _jpg_buf = NULL;
    } else if (_jpg_buf) {
      free(_jpg_buf);
      _jpg_buf = NULL;
    }
    if (res != ESP_OK) {
      is_connected = false;
      Serial.println("End of Streaming");
      break;
    }
      }
  return res;
}

static esp_err_t cmd_handler(httpd_req_t *req) {
  char*  buf;
  size_t buf_len;
  char variable[32] = {0,};
  char value[32] = {0,};
  char user_[32] = {0,};
  char pass_[32] = {0,};

  buf_len = httpd_req_get_url_query_len(req) + 1;
  if (buf_len > 1) {
    buf = (char*)malloc(buf_len);
    if (!buf) {
      httpd_resp_send_500(req);
      return ESP_FAIL;
    }
    if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) {
      if (httpd_query_key_value(buf, "var", variable, sizeof(variable)) == ESP_OK &&
          httpd_query_key_value(buf, "val", value, sizeof(value)) == ESP_OK) {
      } else if (httpd_query_key_value(buf, "USERNAME", user_, sizeof(user_)) == ESP_OK &&
          httpd_query_key_value(buf, "PASSWORD", pass_, sizeof(pass_)) == ESP_OK) {
          writeFile(SD_MMC, "/user_.txt", user_);
          writeFile(SD_MMC, "/pass_.txt", pass_);
          wwwid_ = String(user_);
          wwwpass_ =String(pass_);
          return ESP_OK;
      } else {
        free(buf);
        httpd_resp_send_404(req);
        return ESP_FAIL;
      }
    } else {
      free(buf);
      httpd_resp_send_404(req);
      return ESP_FAIL;
    }
    free(buf);
  } else {
    httpd_resp_send_404(req);
    return ESP_FAIL;
  }

  if (!strcmp(variable, "face_detect")) {
    if (!strcmp(value, "true")) {
      detection_enabled = 1;
      recognition_enabled = 1;
      digitalWrite(BOARD_FLASH_PIN, HIGH);
    } else {
      detection_enabled = 0;
      recognition_enabled = 0;
      digitalWrite(BOARD_FLASH_PIN, LOW);
    }
  }
  else if (!strcmp(variable, "face_enroll")) {
    is_enrolling = !is_enrolling;
    strcpy(nameVal, value);
  }

  else if (!strcmp(variable, "door")) {
    int val = atoi(value);
    is_door_opened = val;
  }
  else if (!strcmp(variable, "face-delete")){
//    delete_face_id_in_flash(&id_list.tail);
  }
  else if(!strcmp(variable, "all-face-delete")){
    for(int ii=0;ii<6;ii++){
      deleteFile(SD_MMC, names[ii]);
    }
    while(delete_face_id_in_flash(&id_list) > -1){
    Serial.println("Deleting Faces");
    }
    Serial.println("Faces Deleted"); 
  }  else {
    //res = -1;
  }

  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
  return httpd_resp_send(req, NULL, 0);
}

static esp_err_t index_handler(httpd_req_t *req) {
  if(!authentified){
   logout_handler(req);
  }
 Serial.println("Authentication Successful: Sending index Page");
  httpd_resp_set_type(req, "text/html");
  return httpd_resp_send(req, index_html, strlen(index_html));
}

static esp_err_t streampage_handler(httpd_req_t *req) {
  if(!authentified){
    logout_handler(req);
  }
  
 Serial.println("Authentication Successful: Sending Streaming Page"); 
  httpd_resp_set_type(req, "text/html");
  httpd_resp_set_hdr(req, "Cache-Control", "no-cache"); 
  return httpd_resp_send(req, streampage_html, strlen(streampage_html));
}

static esp_err_t about_handler(httpd_req_t *req) {
 if(!authentified){
   logout_handler(req);
  }
  
 Serial.println("Authentication Successful: Sending About Page");
  httpd_resp_set_type(req, "text/html");
  return httpd_resp_send(req, about_html, strlen(about_html));
}

static esp_err_t manage_handler(httpd_req_t *req) {
if(!authentified){
    logout_handler(req);
  }
  digitalWrite(BOARD_FLASH_PIN, LOW);
  Serial.println(F("Authentication Successful: Sending Manage Page"));
  httpd_resp_set_type(req, "text/html");
  return httpd_resp_send(req, manage_html, strlen(manage_html));
}

static esp_err_t login_handler(httpd_req_t *req) {

  httpd_resp_set_type(req, "text/html");
  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
  return httpd_resp_send(req, login_html, strlen(login_html));
}

void startCameraServer() {
  pinMode(MOTION_SENSE_PIN,INPUT);
  pinMode(lightPin, INPUT);
  pinMode(BOARD_FLASH_PIN,OUTPUT);
  digitalWrite(BOARD_FLASH_PIN,LOW);
  
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();

  httpd_uri_t index_uri = {
    .uri       = "/",
    .method    = HTTP_GET,
    .handler   = index_handler,
    .user_ctx  = NULL
  };

  httpd_uri_t stream_uri = {
    .uri       = "/stream",
    .method    = HTTP_GET,
    .handler   = stream_handler,
    .user_ctx  = NULL
  };

  httpd_uri_t streampage_uri = {
    .uri       = "/streampage.html",
    .method    = HTTP_GET,
    .handler   = streampage_handler,
    .user_ctx  = NULL
  };

   httpd_uri_t about_uri = {
    .uri       = "/about.html",
    .method    = HTTP_GET,
    .handler   = about_handler,
    .user_ctx  = NULL
  };

  httpd_uri_t manage_uri = {
    .uri       = "/manage.html",
    .method    = HTTP_GET,
    .handler   = manage_handler,
    .user_ctx  = NULL
  };

  httpd_uri_t cmd_uri = {
    .uri       = "/control",
    .method    = HTTP_GET,
    .handler   = cmd_handler,
    .user_ctx  = NULL
  };

  httpd_uri_t login_uri = {
    .uri       = "/login.html",
    .method    = HTTP_GET,
    .handler   = login_handler,
    .user_ctx  = NULL
  };

  httpd_uri_t logged_uri = {
    .uri       = "/logged",
    .method    = HTTP_GET,
    .handler   = handleLogin,
    .user_ctx  = NULL
  };

   httpd_uri_t logout_uri = {
    .uri       = "/logout.html",
    .method    = HTTP_GET,
    .handler   = logout_handler,
    .user_ctx  = NULL
  };

  mtmn_config.type = FAST;
  mtmn_config.min_face = 80;
  mtmn_config.pyramid = 0.707;
  mtmn_config.pyramid_times = 4;
  mtmn_config.p_threshold.score = 0.6;
  mtmn_config.p_threshold.nms = 0.7;
  mtmn_config.p_threshold.candidate_number = 20;
  mtmn_config.r_threshold.score = 0.7;
  mtmn_config.r_threshold.nms = 0.7;
  mtmn_config.r_threshold.candidate_number = 10;
  mtmn_config.o_threshold.score = 0.7;
  mtmn_config.o_threshold.nms = 0.7;
  mtmn_config.o_threshold.candidate_number = 1;

  face_id_init(&id_list, FACE_ID_SAVE_NUMBER, ENROLL_CONFIRM_TIMES);
  read_face_id_from_flash(&id_list);

  Serial.printf("Starting web server on port: '%d'\n", config.server_port);
  if (httpd_start(&index_httpd, &config) == ESP_OK) {
    httpd_register_uri_handler(index_httpd, &index_uri);
    httpd_register_uri_handler(index_httpd, &cmd_uri);
    httpd_register_uri_handler(index_httpd, &streampage_uri);
    httpd_register_uri_handler(index_httpd, &manage_uri);
    httpd_register_uri_handler(index_httpd, &about_uri);
    httpd_register_uri_handler(index_httpd, &login_uri);
    httpd_register_uri_handler(index_httpd, &logged_uri);
    httpd_register_uri_handler(index_httpd, &logout_uri);
  }

  config.server_port += 1;
  config.ctrl_port += 1;
  Serial.printf("Starting stream server on port: '%d'\n", config.server_port);
  if (httpd_start(&stream_httpd, &config) == ESP_OK) {
    httpd_register_uri_handler(stream_httpd, &stream_uri);
    //httpd_register_uri_handler(stream_httpd, &stream_to_screen_uri);
    }

  wwwid_ = readFile(SD_MMC, "/user_.txt");
  if(wwwid_ == ""){
    Serial.println("No new username saved");
     wwwid_ = DEFAULT_wwwid;
  }

  wwwpass_ = readFile(SD_MMC, "/pass_.txt");
  if(wwwpass_ == "") {
    Serial.println("No new password saved");
  wwwpass_ = DEFAULT_wwwpass;
  }
}

uint8_t recognizeFace() {
  camera_fb_t * fb = NULL;
  dl_matrix3du_t *image_matrix = NULL;
  int face_id = -1;
    
    fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Camera capture failed in Recognize Face");
      return 231;
    } 
    image_matrix = dl_matrix3du_alloc(1, fb->width, fb->height, 3);
    if (!image_matrix) {
      Serial.println("dl_matrix3du_alloc failed");
      return 231;
      } 
    bool i = fmt2rgb888(fb->buf, fb->len, fb->format, image_matrix->item);
    esp_camera_fb_return(fb); 
    fb = NULL; 
    if (!i) {
      Serial.println("fmt2rgb888 failed in Recognize Face");
      dl_matrix3du_free(image_matrix);
      return 231;
      } 
            
    box_array_t *net_boxes = face_detect(image_matrix, &mtmn_config);
    if (net_boxes) {
      face_id = run_face_recognition(image_matrix, net_boxes);
      free(net_boxes->score);
      free(net_boxes->box);
      free(net_boxes->landmark);
      free(net_boxes);
      }
    
  dl_matrix3du_free(image_matrix);
   
  if(face_id>=0 && face_id<9) {
    face_id = FACE_FOUND_VALUE;
  }
  return face_id;
}

void taskDelay(uint64_t timeDelay){
  int64_t finish = esp_timer_get_time() + timeDelay;
  while(finish>esp_timer_get_time()); 
}

int detect(){
  int motionSense = digitalRead(MOTION_SENSE_PIN);;
//  Serial.println(readLight);
 
  if(!detection_enabled){
  if(motionSense==true){
    if((analogRead(lightPin)>3500)&&!lightflag){
      lightflag = 1;
    }
    //int readLight = analogRead(lightPin);
    if(lightflag){
    digitalWrite(BOARD_FLASH_PIN, HIGH);
    }else{
      digitalWrite(BOARD_FLASH_PIN, LOW);
     }
    } else digitalWrite(BOARD_FLASH_PIN, LOW);
  } 
  if(!motionSense && lightflag){
    lightflag = 0;
  }
 return motionSense;
}

uint8_t doorReturn(){
  int val = 0;
  if(is_door_opened == 1){
    val = DOOR_RETURN_VALUE;
    is_door_opened = 0;
  } else val = 0;
  return val;
}

bool is_streaming(){
 return is_connected;
}
