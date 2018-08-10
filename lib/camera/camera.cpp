#include "camera.h"

void Camera::init() {
  Serial3.begin(9600);
  Serial2.begin(9600);
  Serial1.begin(9600);
}

void Camera::update() {
  // while (Serial3.available() >= CAMERA_PACKET_SIZE) {
  //   uint8_t first = Serial3.read();
  //
  //   Serial.println("ding dong thot");
  //
  //   if (first == 0x80) {
  //     uint8_t dataBuffer[CAMERA_PACKET_SIZE - 1];
  //
  //     for (int i = 0; i < CAMERA_PACKET_SIZE - 1; i++) {
  //       dataBuffer[i] = Serial3.read();
  //     }
  //
  //     ballVisible = (bool)((dataBuffer[0] << 7) | dataBuffer[1]);
  //     ballAngle = (dataBuffer[2] << 7) | dataBuffer[3];
  //     ballDistance = (dataBuffer[4] << 7) | dataBuffer[5];
  //   }
/*  Serial.println("thot master");
  // }
  uint8_t dataBuffer[CAMERA_PACKET_SIZE - 1];
  while (Serial3.available() >= CAMERA_PACKET_SIZE){
    Serial.println("OI YO DAFT THOT");
    if (Serial3.read() == 0x80){
      Serial.println("thot 2");
      for (int i = 0; i < CAMERA_PACKET_SIZE; i++){
        Serial.print("thot 3 lol");
        while (!Serial3.available());
        dataBuffer[i] = Serial3.read();
      }
    }
  }*/

  Serial.printf("Serial1: %d\tSerial2: %d\tSerial3: %d\n", Serial1.available(), Serial2.available(), Serial3.available());

}
