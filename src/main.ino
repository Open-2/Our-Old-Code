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
const double kp = 0.45;
const double kd = 0.9;
unsigned long previousMillis = 0;
unsigned long compMillis = 0;
int previousHeading = 0;
int bAngle = 0;
int goalAngle = 0;


void setup(){
  Serial.begin(9600);
  Motor.Setup();
  Wire.begin();
  // compass.compassSetup();
  // compass.calibrate();
  camera.init();
}

void loop(){


  //compass.updateGyro();

  if (camera.bGoalAngle != -2 || camera.yGoalAngle != 2)  {
    if (camera.bGoalAngle != -2) {
      goalAngle = camera.bGoalAngle;
    }
  } else {
    goalAngle = 0;
  }
  //
  // if (goalAngle > 10 && goalAngle < 180) {
  //   Motor.weights[0] += 30;
  //
  // }  else {
  //   if (goalAngle < 350 && goalAngle > 180){
// }
  //     Motor.weights[2] += -30;
    // }

  unsigned long currentMillis = millis();

  int relativeHeading = goalAngle > 180 ? (360 - goalAngle) : goalAngle;

  double diffTime = ((double)(currentMillis - compMillis))/100.0;
  double difference = ((double)(relativeHeading - previousHeading)) / diffTime;
  compMillis = currentMillis;
  //Serial.print((previousHeading-relativeHeading));
  //Serial.print("\t");
  //Serial.println(difference);
  previousHeading = relativeHeading;

  int correction = round(kp*((double)relativeHeading) + kd*difference);

  camera.update();

  if (camera.ballAngle > 340 || camera.ballAngle < 20) {
    bAngle = 180;
    } else {
      if (camera.ballAngle < 80) {
        bAngle = 90;
      } else {
        if (camera.ballAngle < 290) {
          bAngle = 0;
        } else {
          bAngle = 270;
      }
    }
  }


  Motor.Move(bAngle, correction, 150);
    }
