#include <avr/interrupt.h>
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

float SoftwarePID::calculateOutput(float current, float setpoint, long dT, boolean isStandardized){
  float delta = (current - setpoint)/(isStandardized ? setpoint : 1);
  return 
    pid.kP *   delta +
    pid.kI * ( delta * dT) + 
    pid.kD * ( delta / dT);
}

float SoftwarePID::calculateOutput(float current, long dT, boolean isStandardized){
  return calculateOutput(current, setpoint , dT, isStandardized);
}
}

SG90::SG90(int ID, SoftwarePID ctrl):
  control(ctrl){
    motor = Servo();
    motor.attach(3);
}

float SG90::getPosition(){
  return 0; //TODO: Try out the way to get the position measure.
}

void SG90::set(float percent){
  motor.write(map(percent, 0, 100, 0,100)); //TODO: Try out the range
}

void SG90::turnTo(float degree){
  control.withSetpoint(degree);
  while (!((degree - getPosition())/degree < 0.05)) {
    set(control.calculateOutput(getPosition(), 15, true));
    delay(15);
  }
}

Drivetrain::Drivetrain(SoftwarePID LeftPID, SoftwarePID RightPID, SoftwarePID SteerPID, FeedForwardConfig WheelFF) :
  LeftPID(LeftPID),
  RightPID(RightPID),
  SteerPID(SteerPID),
  ff(WheelFF),
  LeftEncoder(AS5600()),
  RightEncoder(AS5600()){
  };

/**
Accepting postition in `Degrees`
*/
void Drivetrain::steer(float Position){
  SteerPID.withSetpoint(Position);
  while(!(((Position - getSteerState().CurrentPosition)/Position) < 0.05)){
    
  }
}