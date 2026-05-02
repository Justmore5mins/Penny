#include "Servo.h"
#include "AS5600.h"
#include "Arduino.h"
#include "Constants.h"
#include "Control.h"


SoftwarePID::SoftwarePID(ClosedLoopConfig pid,  float setpoint):
  pid(pid),
  setpoint(setpoint){};


SoftwarePID::SoftwarePID(ClosedLoopConfig pid){
  this->pid = pid;
  this->setpoint = 0;
};

void SoftwarePID::withSetpoint(float setpoint){
  this->setpoint = setpoint;
}

float SoftwarePID::calculateOutput(float current, float setpoint, long dT, bool isStandardized){
  float delta = (current - setpoint)/(isStandardized ? setpoint : 1);

  return 
    pid.kP *   delta +
    pid.kI * ( delta * dT) + 
    pid.kD * ( delta / dT);
}

float SoftwarePID::calculateOutput(float current, long dT, bool isStandardized){
  return calculateOutput(current, setpoint , dT, isStandardized);
}

SG90::SG90(int ID): 
motor(Servo()){
  motor.attach(ID);
}

L9110S::L9110S(int LeftDirID, int LeftSpeedID, int RightDirectionID, int RightSpeedID):
  LeftDirection(LeftDirID),
  LeftSpeed(LeftSpeedID),
  RightDirection(RightDirectionID),
  RightSpeed(RightSpeedID){
    pinMode(LeftDirection, OUTPUT);
    pinMode(LeftSpeed, OUTPUT);
    pinMode(RightDirection, OUTPUT);
    pinMode(RightSpeed, OUTPUT);
}

void L9110S::set(DriveMotorState DutyCycle){
  digitalWrite(LeftDirection, DutyCycle.LeftMotor > 0.0);
  analogWrite(LeftSpeed, map(abs(DutyCycle.LeftMotor), 0, 1, 0, 255));
  digitalWrite(RightDirection, DutyCycle.RightMotor > 0.0);
  analogWrite(RightSpeed, map(abs(DutyCycle.RightMotor), 0, 1, 0, 255));
}