struct ClosedLoopConfig{
  float kP, kI, kD;
};

struct FeedForwardConfig{
  float kS, kV, kA;
};

struct Position{
  float pos;
};

struct Velocity{
  float vel;
};

struct Acceleration{
  float accel;
};

struct MotorState{
  Position CurrentPosition, PositionAbsoulte;
  Velocity CurrentVelocity;
  Acceleration CurrentAcceleration;
  long TimeStamp;
};

struct ChassisSpeeds{
  float vx, vy, omega;
};

struct Pose2d{
  float x, y, facing;
};