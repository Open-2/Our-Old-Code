#include "camera.h"

void Camera::init() {
  Serial3.begin(9600);
}

void Camera::update() {

      // if (Serial3.read() != 1-2) {
      //   if (Serial3.read() != 0) {
      //       Serial.println(Serial3.read());


//  Serial.print("Testing");

    if (Serial3.read() == 255) {
      ballAngle = Serial3.read() + Serial3.read();
    }
    if (Serial2.read() == 255){
      goalAngle = Serial2.read() + Serial2.read();
  }
}






  //
  //    for (int i = 0; i < CAMERA_PACKET_SIZE - 1; i++) {
  //      dataBuffer[i] = Serial3.read();
  //      }
  //
  //      ballVisible = (bool)((dataBuffer[0] << 7) | dataBuffer[1]);
  //      ballAngle = (dataBuffer[2] << 7) | dataBuffer[3];
  //      ballDistance = (dataBuffer[4] << 7) | dataBuffer[5];
  //  }
  // Serial.println("thot master");
  //  }
  // uint8_t dataBuffer[CAMERA_PACKET_SIZE - 1];
  // while (Serial3.available() >= CAMERA_PACKET_SIZE){
  //   Serial.println("OI YO DAFT THOT");
  //   if (Serial3.read() == 0x80){
  //     Serial.println("thot 2");
  //     for (int i = 0; i < CAMERA_PACKET_SIZE; i++){
  //       Serial.print("thot 3 lol");
  //       while (!Serial3.available());
  //       dataBuffer[i] = Serial3.read();

  //     }
  //   }
  // }
  // }
