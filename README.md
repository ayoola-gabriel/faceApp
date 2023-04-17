# faceApp
This app allow you to manage and control the Face Recognition Enabled Security Door. It usess the ESP32 microcontroller, OV2640 camera, a screen, a motion sensor and a solenoid lock as main components of the project
The motion sensor signal is used to activate the camera when motion is detected. If the motion is face, the face is scanned against pre-registered faces in the microcontroller and when a registered face is captures, it opens the door, else it sounds an intruder alarm

There are 2 ESP32 microcontroller in the project, one controls the camera, the other controls the lock.

A webserver is built using HTML, CSS and  Javascript to gain control to the device. The webserver is named FaceApp.

Contact us at newnesselectronics@gmail.com for more information, consultation and assiatance
