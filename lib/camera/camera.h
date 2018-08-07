#ifndef CAMERA_H
#define CAMERA_H

#include <Arduino.h>
#include <define.h>

class Camera {
public:
  void init();
  void update();

  bool ballVisible;
  int ballAngle = 0;
  int ballDistance = 0;
};

#endif
