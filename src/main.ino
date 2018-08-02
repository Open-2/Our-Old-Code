#include <Arduino.h>
#include <Common.h>
//#include <compass.h>
#include <define.h>
//#include <I2C.h>
//#include <lightSensor.h>
//#include <lightSensorArray.h>
#include <Motor.h>
#include <MotorController.h>

//This is where basic documentation will go.
MotorController Motor;
int speed = 255;

void setup(){
  Motor.Setup();
}

void loop(){
  //int bxco = 150;
  //int byco = 120;
  Motor.Move(0, 0, speed);
  //analogWrite(motorPin, 255);
}
