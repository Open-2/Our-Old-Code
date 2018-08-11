#ifndef CAMERA_H
#define CAMERA_H

#include <Arduino.h>
#include <define.h>

class Camera {
public:
  void init();
  void update();
  int ballAngle = 0;
  int bGoalAngle = 0;
  int yGoalAngle = 0;
};

#endif
