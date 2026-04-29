#include "Utils.h"
#include "Constants.h"

SoftwarePID::SoftwarePID(ClosedLoopConfig pid,  float setpoint):
  pid(pid),
  setpoint(setpoint){};


SoftwarePID::SoftwarePID(ClosedLoopConfig pid){
  SoftwarePID(pid, 0);
};

float SoftwarePID::calculateOutput(float current, float setpoint, long dT){
  float delta = current - setpoint;
  return 
  pid.kP *   delta +
  pid.kI * ( delta * dT) + 
  pid.kD * ( delta / dT);
}

float SoftwarePID::calculateOutput(float current, long dT){
  return calculateOutput(current, setpoint, dT);
}