#include "Utils.h"

SoftwarePID::SoftwarePID(float kP, float kI, float kD, float setpoint)
  : kP(kP),
    kI(kI),
    kD(kD),
    setpoint(setpoint){};

SoftwarePID::SoftwarePID(float kP, float kI, float kD){
  SoftwarePID(kP,kI,kD, 0);
}

float SoftwarePID::calculateOutput(float current, float setpoint, long dT){
  float delta = setpoint - current;
  return 
    this-> kP *   delta  +
    this-> kI * ( delta * dT ) +
    this-> kD * ( delta / dT);
};

float SoftwarePID::calculateOutput(float current, long dT){
  return calculateOutput(current, this->setpoint, dT);
}