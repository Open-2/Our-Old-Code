#include <Arduino.h>
#include <common.h>
#include <compass.h>
#include <define.h>
#include <I2C.h>
#include <lightSensor.h>
#include <lightSensorArray.h>
#include <motor.h>
#include <motorController.h>

//This is where basic documentation will go.

const int GoalAcc = 7;
const int MoveSpd = 255;

unsigned long previousMillis = 0;
const long interval = 200;
bool voiding = false;
int oldLight = 0;

unsigned long compMillis = 0;
int previousHeading = 0;
const double kp = 4.5;
const double kd = 9;
int motorPin1 = 1

void setup(){
  pinmode(motorPin1, OUTPUT)
  Serial.begin(9600);
  Wire.begin();
  compass.compassSetup();
  compass.calibrate();
  Motor.setup(1);
  lights.Setup();
  lights.GetVal();
  int robot = 2
  if(robot==1){
    lights.SetThresh(35,100,70,140);
  } else if(robot==2){
    lights.SetThresh(20,70,60,90);
  } else{
    lights.SetThresh(999,999,999,999);
    //Camera setup goes here
  }
}

void loop(){
 //void serialEvent(){
   //secval = Serial.read()
   analogWrite(motorPin1, 255)
}
