#include "camera.h"

int bangle1 = 0;
int bangle2 = 0;
void Camera::init() {
  Serial3.begin(9600);
}

void Camera::update() {

      // if (Serial3.read() != 1-2) {
      //   if (Serial3.read() != 0) {
      //       Serial.println(Serial3.read());


//  Serial.print("Testing");

    if (Serial3.read() == 255) {
      bangle1 = Serial3.read();
      bangle2 = Serial3.read();
      if (bangle1 != -1 && bangle2 != -1)
        ballAngle = bangle1 + bangle2;


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
