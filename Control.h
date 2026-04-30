#include "AS5600.h"
#include "Utils.h"


class SoftwarePID{
  private:
    ClosedLoopConfig pid;
    float setpoint;
  public:
    SoftwarePID(ClosedLoopConfig pid);
    SoftwarePID(ClosedLoopConfig pid, float setpoint);
    float calculateOutput(float current, long dT);
    float calculateOutput(float current, float setpoint, long dT);
};


class Drivetrain{
  private:
    SoftwarePID LeftPID, RightPID;
    FeedForwardConfig ff;
    AS5600 LeftEncoder, RightEncoder;
    MotorState LeftLastState, RightLastState, SteerLastState;

  public:
    Drivetrain(SoftwarePID LeftPID, SoftwarePID RightPID, FeedForwardConfig WheelFF);
    MotorState getLeftState();
    MotorState getRightState();
    MotorState getSteerState();
    ChassisSpeeds getSpeeds();
    Pose2d getPose();
};
