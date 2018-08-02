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
  int bxco = 150;
  int byco = 120;
  //analogWrite(motorPin, 255);

  if (bxco >= 160){
    if (bxco <= 240){
      if (byco < 80){
        Motor.Move(0, 0, speed);
}     if (byco <= 160){
        if (byco >= 80){
          Motor.Move(180, 0, speed);
}}    if (byco > 160){
        Motor.Move(225, 0, speed);
}}if (bxco > 240){
}   if (byco < 80){
        Motor.Move(90, 0, speed);
}   if (byco <= 160){
      if (byco >= 80){
        Motor.Move(135, 0, speed);
}}  if (byco > 160){
        Motor.Move(180, 0, speed);
} if (bxco < 160){
}   if (byco < 80){
        Motor.Move(270, 0, speed);
}   if (byco <= 160){
      if (byco >= 80){
        Motor.Move(225, 0, speed);
}}  if (byco > 160){
        Motor.Move(180, 0, speed);
    }
  }
}
