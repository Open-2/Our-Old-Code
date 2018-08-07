#include "camera.h"

void Camera::init() {
  Serial1.begin(115200);
}

void Camera::update() {
  while (Serial1.available() >= CAMERA_PACKET_SIZE) {
    uint8_t first = Serial1.read();

    if (first == 0x80) {
      uint8_t dataBuffer[CAMERA_PACKET_SIZE - 1];

      for (int i = 0; i < CAMERA_PACKET_SIZE - 1; i++) {
        dataBuffer[i] = Serial1.read();
      }

      ballVisible = (bool)((dataBuffer[0] << 7) | dataBuffer[1]);
      ballAngle = (dataBuffer[2] << 7) | dataBuffer[3];
      ballDistance = (dataBuffer[4] << 7) | dataBuffer[5];
    }
  }
}
