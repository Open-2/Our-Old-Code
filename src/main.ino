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
        //Ball is at the front
}     if (byco <= 160){
        if (byco >= 80){
          //Ball is literally on the camera
}}    if (byco > 160){
      //Ball is at the back
}}if (bxco > 240){
}   if (byco < 80){
    //Ball is to the front right
}   if (byco <= 160){
      if (byco >= 80){
      //Ball is on the right
}}  if (byco > 160){
    //Ball is to the back right
} if (bxco < 160){
}   if (byco < 80){
    //Ball is to the front left
}   if (byco <= 160){
      if (byco >= 80){
        Motor.Move(180, 0, speed);
}}  if (byco > 160){
    //Ball is to the back left
    }
  }
}
