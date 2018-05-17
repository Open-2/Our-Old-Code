#include "lightSensorArray.h"

void LightSensorArray::Setup(){
  lsFrontright.Setup(LS_FRONTRIGHT);
  lsFrontleft.Setup(LS_FRONTLEFT);
  lsLeft.Setup(LS_LEFT);
  lsBack.Setup(LS_BACK);
  lsRight.Setup(LS_RIGHT);
}

void LightSensorArray::SetThresh(int front, int left, int back, int right){
  lsFrontLeft.SetThresh(front_left);
  lsFrontRight.SetThresh(front_right);
  lsLeft.SetThresh(left);
  lsBack.SetThresh(back);
  lsRight.SetThresh(right);
  thresholds[0] = lsFrontleft.threshold;
  thresholds[1] = lsFrontright.threshold;
  thresholds[2] = lsLeft.threshold;
  thresholds[3] = lsBack.threshold;
  thresholds[4] = lsRight.threshold;
}

void LightSensorArray::GetVal(){
  lightValues[0] = lsFrontleft.GetVal();
  lightValues[1] = lsFrontright.GetVal();
  lightValues[2] = lsLeft.GetVal();
  lightValues[3] = lsBack.GetVal();
  lightValues[4] = lsRight.GetVal();
  onWhite[0] = lsFrontLeft.onWhite();
  onWhite[1] = lsFrontright.onWhite();
  onWhite[2] = lsLeft.onWhite();
  onWhite[3] = lsBack.onWhite();
  onWhite[4] = lsRight.onWhite();
}

double LightSensorArray::LightAngle(){
  for (int i; i < 4; i++){
		if (onWhite[i]){
			vectori += iCords[i];
			vectorj += jCords[i];
		}
	}
	if(vectori!=0||vectorj!=0){
		escape = atan2(vectorj, vectori);
		escape = escape * 180/pi;
		angle = mod(escape + 270,360);
  }else{
    angle = -30;
    vectori = 0;
    vectorj = 0;
    escape = 0;
    return angle;
  }
  vectori = 0;
  vectorj = 0;
  escape = 0;
  return mod(angle+180,360);
}
