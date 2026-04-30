#include "AS5600.h"
#include "Arduino.h"
#include "Constants.h"
#include "Wire.h"
#include "Control.h"


SoftwarePID::SoftwarePID(ClosedLoopConfig pid,  float setpoint):
  pid(pid),
  setpoint(setpoint){};


SoftwarePID::SoftwarePID(ClosedLoopConfig pid){
  this->pid = pid;
  this->setpoint = 0;
};

float SoftwarePID::calculateOutput(float current, float setpoint, long dT){
  float delta = current - setpoint;
  return 
    pid.kP *   delta +
    pid.kI * ( delta * dT) + 
    pid.kD * ( delta / dT);
}

float SoftwarePID::calculateOutput(float current, long dT){
  return calculateOutput(current, setpoint , dT);
}

Drivetrain::Drivetrain(SoftwarePID LeftPID, SoftwarePID RightPID, FeedForwardConfig WheelFF) :
  LeftPID(LeftPID),
  RightPID(RightPID),
  ff(WheelFF),
  LeftEncoder(AS5600()),
  RightEncoder(AS5600()){
    
  };
  
MotorState Drivetrain::getLeftState(){
  long CurrentTime = millis();
  MotorState currentState = MotorState{
    
  };
}