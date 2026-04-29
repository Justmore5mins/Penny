class SoftwarePID{
  private:
    float kP, kI, kD;
    float setpoint;
  public:
    SoftwarePID(float kP, float kI, float kD);
    SoftwarePID(float kP, float kI, float kD, float setpoint);
    float calculateOutput(float current, long dT);
    float calculateOutput(float current, float setpoint, long dT);
};