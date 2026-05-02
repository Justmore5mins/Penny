struct ClosedLoopConfig{
  float kP, kI, kD;
};

struct FeedForwardConfig{
  float kS, kV, kA;
};

struct Position{
  int pos;
};

struct Velocity{
  float vel;
};

struct DriveMotorState{
  float LeftMotor, RightMotor;
};

struct MotorState{
  long unsigned int CurrentPosition;
  Velocity CurrentVelocity;
  unsigned long TimeStamp;
};

struct ChassisSpeeds{
  float vx, vy, omega;
};

struct Pose2d{
  float x, y, facing;
};