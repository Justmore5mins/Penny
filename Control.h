#include "Servo.h"
#include "AS5600.h"
#include "Utils.h"


class SoftwarePID{
  private:
    ClosedLoopConfig pid;
    float setpoint;
  public:
    SoftwarePID(ClosedLoopConfig pid);
    SoftwarePID(ClosedLoopConfig pid, float setpoint);
    float calculateOutput(float current, long dT, bool isStandardized);
    float calculateOutput(float current, float setpoint, long dT, bool isStandardized);
    void withSetpoint(float setpoint);
};


class SG90{
  private:
    SoftwarePID control;
    Servo motor;
  public:
    SG90(int ID, SoftwarePID ctrl);

    /**
    Output value in `degrees`
    */
    float getPosition();
    void turnTo(float degree);
    void set(float percent);
};

class Drivetrain{
  private:
    SoftwarePID LeftPID, RightPID, SteerPID;
    FeedForwardConfig ff;
    AS5600 LeftEncoder, RightEncoder;
    MotorState LeftLastState, RightLastState, SteerLastState;

  public:
    Drivetrain(SoftwarePID LeftPID, SoftwarePID RightPID, SoftwarePID SteerPID, FeedForwardConfig WheelFF);
    MotorState getLeftState();
    MotorState getRightState();
    MotorState getSteerState();
    ChassisSpeeds getSpeeds();

    void steer(float Position);

    Pose2d getPose();
};
