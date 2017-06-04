#ifndef DIFF_DRIVE_H
#define DIFF_DRIVE_H


//import robotics cape functions
extern "C"
{
  #include "rc_usefulincludes.h"
}
extern "C"
{
  #include "roboticscape.h"
}

#define LEFT_DRIVEMOTOR 4
#define RIGHT_DRIVEMOTOR 1

#define LEFT_ENCODER 4
#define RIGHT_ENCODER 1

class DiffDrive{
public:
  DiffDrive();
  int getEncoder(int, int);
  void setMotor(float); //from -100 to 100
private:
  int motorPort;
  int encoderPort;

};

#endif // DIFF_DRIVE_H
