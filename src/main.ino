#include <Arduino.h>
#include <Common.h>
//#include <Compass.h>
#include <define.h>
#include <I2C.h>
//#include <lightSensor.h>
//#include <lightSensorArray.h>
#include <Motor.h>
#include <MotorController.h>
#include <camera.h>

//This is where basic documentation will go.
MotorController Motor;
//Compass compass;
Camera camera;

const int GoalAcc = 7;
const int speed = 255;
const double kp = 4.5;
const double kd = 9;
unsigned long previousMillis = 0;
unsigned long compMillis = 0;
int previousHeading = 0;
int bAngle = 0;


void setup(){
  Serial.begin(9600);
  Motor.Setup();
  Wire.begin();
  //compass.compassSetup();
  //compass.calibrate();
  camera.init();
}

void loop(){

  Motor.Move(bAngle, /*correction*/ 0, 255);
  camera.update();


  //Motor.motorFrontRight.Move(255);
  if (camera.ballAngle > 170 && camera.ballAngle < 190) {
    bAngle = 0;
    Serial.print("Forward");
  } else {
  if (camera.ballAngle < 250 && camera.ballAngle >= 190) {
    bAngle = 90;
    Serial.print("Right");
  } else {
  if (camera.ballAngle < 170 && camera.ballAngle > 110) {
    bAngle = 270;
    Serial.print("Left");
  } else {
    bAngle = 180;
    Serial.print("Backwards");
      }
    }
  }


  //compass.updateGyro();
  //unsigned long currentMillis = millis();
/*
  int relativeHeading = compass.heading > 180 ? (360 - compass.heading) : -compass.heading;

  double diffTime = ((double)(currentMillis - compMillis))/100.0;
  double difference = ((double)(relativeHeading - previousHeading)) / diffTime;
  compMillis = currentMillis;
  //Serial.print((previousHeading-relativeHeading));
  //Serial.print("\t");
  //Serial.println(difference);
  previousHeading = relativeHeading;

  int correction = round(kp*((double)relativeHeading) + kd*difference);
*/



  //Serial.println(camera.ballAngle);
}
