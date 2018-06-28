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

void setup(){
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
  compass.updateGyro();
  //Camera initialisation
  lights.GetVal();
  //Our camera initialisation goes here
  int light = lights.LightAngle();
  unsigned long currentMillis = millis();


  int relativeHeading = compass.heading > 180 ? (360 - compass.heading) : -compass.heading;
  // int correctionRotation = relativeHeading * 3;

  double diffTime = ((double)(currentMillis - compMillis))/100.0;
  double difference = ((double)(relativeHeading - previousHeading)) / diffTime;
  compMillis = currentMillis;
  //Serial.print((previousHeading-relativeHeading));
  //Serial.print("\t");
  // Serial.println(difference);
  previousHeading = relativeHeading;

  int correction = round(kp*((double)relativeHeading) + kd*difference);


//This will not compile, so don't try it you mongrel
//There is literally no chance of it compiling because none of the if statements work

  if(!voiding){
  if (light == -30){
    //Not touching line
    if (){
      //No ball around, compass correct (Unable to see a ball on the camera)
      Motor.Move(0,correction,0);
    } else{
      //Orbit Code
      if (){
        //Too far away,  move towards Ball (Camera distance sensor, might be really difficult to do but eh whatever we'll find out)
        Motor.Move(angle,correction,MoveSpd);
      } else{
        //Close Orbit
        if (){
          //Ball on left side (Camera angle is at 270)
          if (){
            //Move Right (Ball is less than 210 angle)
            Motor.Move(90,correction,MoveSpd);
          } else if (){
            //Back clear (Angle is less than 280)
            Motor.Move(185,correction,MoveSpd);
          } else if (){
            // Ball is at front left (350), now move left
            Motor.Move(270,correction,MoveSpd);
          } else{
            // Ball at front,
            Motor.Move(0,correction,MoveSpd);
          }
        } else if (){
          // Ball on right side (Angle less than 180)
          if (){
            // Move left to make back clear (Angle is more than 150)
            Motor.Move(270,correction,MoveSpd);
          } else if (){
            // Back clear, move back (Angle is more than 60)
            Motor.Move(165,correction,MoveSpd);
          } else if (angle>20){
            // Ball is at front right (Angle is less than 20), move right
            Motor.Move(90,correction,MoveSpd);
          } else{
            // Ball infront
            Motor.Move(0,correction,MoveSpd);
          }
        }
      }
    }
  } else {     //Light sensor senses a line, move away
    previousMillis = currentMillis;
    voiding = true;
    oldLight = light;
    Motor.Move(oldLight, correction, -255);
  }
  }else{
    Motor.Move(oldLight, correction, -255);
    if(currentMillis - previousMillis >= interval){
      voiding = false;
    }
  }
