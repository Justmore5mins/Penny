#include "ClosedLoop.h"

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


class SwerveModule{
  private:
    int MotorID, EncoderID;
};
