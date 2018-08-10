#ifndef DEFINES_H
#define DEFINES_H

//Maths
#define pi 3.141592653

// Light Sensor
#define LS_FRONT_LEFT A0
#define LS_FRONT_RIGHT A1
#define LS_LEFT A2
#define LS_BACK A3
#define LS_RIGHT A4

#define LS_FRONT_LEFT_G
#define LS_FRONT_LEFT_W
#define LS_FRONT_RIGHT_G
#define LS_FRONT_RIGHT_W
#define LS_LEFT_G
#define LS_LEFT_W
#define LS_BACK_G
#define LS_BACK_W
#define LS_RIGHT_G
#define LS_RIGHT_W

// Compass
#define MPU9250_ADDRESS 0x68
#define MAG_ADDRESS 0x0C

#define GYRO_FULL_SCALE_250_DPS 0x00
#define GYRO_FULL_SCALE_500_DPS 0x08
#define GYRO_FULL_SCALE_1000_DPS 0x10
#define GYRO_FULL_SCALE_2000_DPS 0x18

#define ACC_FULL_SCALE_2_G 0x00
#define ACC_FULL_SCALE_4_G 0x08
#define ACC_FULL_SCALE_8_G 0x10
#define ACC_FULL_SCALE_16_G 0x18

#define COMPASS_CALIBRATION 1.39
#define COMPASS_CALIBRATION_TIME 1000

#define MOTOR_ANGLE 45

#define MOTOR_FRONT_LEFT_ENA 13
#define MOTOR_FRONT_LEFT_IN1 12
#define MOTOR_FRONT_LEFT_IN2 11
#define MOTOR_FRONT_LEFT_REVERSED true
#define MOTOR_BACK_LEFT_ENA 10
#define MOTOR_BACK_LEFT_IN1 9
#define MOTOR_BACK_LEFT_IN2 8
#define MOTOR_BACK_LEFT_REVERSED false
#define MOTOR_BACK_RIGHT_ENA 4
#define MOTOR_BACK_RIGHT_IN1 2
#define MOTOR_BACK_RIGHT_IN2 3
#define MOTOR_BACK_RIGHT_REVERSED true
#define MOTOR_FRONT_RIGHT_ENA 7
#define MOTOR_FRONT_RIGHT_IN1 5
#define MOTOR_FRONT_RIGHT_IN2 6
#define MOTOR_FRONT_RIGHT_REVERSED false

#define CAMERA_PACKET_SIZE 2

#endif
