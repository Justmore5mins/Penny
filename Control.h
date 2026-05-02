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
    Servo motor;
    MotorState state;
  public:

    /**
    Inherhit from Servo library, with some modification.
    IMPORTANT: the `Servo.write(float)` in 360 degree sero is velocity based control.
    */
    SG90(int ID);
    /**
    get position in `Degrees`
    */
    float getPosition();
    /**
    get velocity in `Deg/s`
    */
    float getVelocity();
    /**
    move the shaft to target position in `Degrees`
    */
    void toPosition(float deg);

    /**
    request the dutycycle
    */
    void set(float DutyCycle);
};

class L9110S{
  private:
    int LeftDirection, LeftSpeed, RightDirection, RightSpeed;
    MotorState state;
  public:
    L9110S(int LeftDirID, int LeftSpeedID, int RightDirectionID, int RightSpeedID);
    DriveMotorState getPosition();
    DriveMotorState getVelocity();
    void setVelocity(DriveMotorState vel);
    /**
    Accepting duty cycle in `Percent`, ranging from `0` to `1`.
    */
    void set(DriveMotorState DutyCycle);
};