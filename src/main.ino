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
  // compass.compassSetup();
  // compass.calibrate();
  camera.init();
}

void loop(){

  // compass.updateGyro();
  // unsigned long currentMillis = millis();
  //
  // int relativeHeading = camera.goalAngle > 180 ? (360 - camera.goalAngle) : camera.goalAngle;
  //
  // double diffTime = ((double)(currentMillis - compMillis))/100.0;
  // double difference = ((double)(relativeHeading - previousHeading)) / diffTime;
  // compMillis = currentMillis;
  // //Serial.print((previousHeading-relativeHeading));
  // //Serial.print("\t");
  // //Serial.println(difference);
  // previousHeading = relativeHeading;
  //
  // int correction = round(kp*((double)relativeHeading) + kd*difference);

    // Motor.Move(bAngle, /*correction*/ 0, 255);
    camera.update();
    Serial.println(camera.ballAngle);




     if (camera.ballAngle > 350 || camera.ballAngle < 10) {
       bAngle = 0;
     } else {
     if (camera.ballAngle < 70) {
       bAngle = 90;
     } else {
     if (camera.ballAngle < 290) {
       bAngle = 180;
     } else {
       bAngle = 270;
        }
       }
     }
     Motor.Move(bAngle, 0, 255);
 }
