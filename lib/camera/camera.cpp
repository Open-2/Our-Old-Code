#include "camera.h"

int incomingByte = 0;
int timer = 0;
int cameraList [2] = { 0, 0};
void Camera::init() {
  Serial3.begin(9600);
}

void Camera::update() {
  while (true) {
      // if (Serial3.read() != 1-2) {
      //   if (Serial3.read() != 0) {
      //       Serial.println(Serial3.read());


//  Serial.print("Testing");

      if (Serial3.read() == 0x80) {
        // Serial.print("This function is running.\n");
        while (timer < CAMERA_PACKET_SIZE){



          cameraList[timer] = Serial3.read();
          timer += 1;
        }

        // Serial.print("The function has finished\n");
        //Serial.print(cameraList[0]);
        timer = 0;
        ballAngle = cameraList[0];
        Serial.print(cameraList[0]);
    }
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
