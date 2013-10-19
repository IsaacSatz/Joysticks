#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <WPIlib.h>
class Joystick{
  private:
    Joystick speedStick;
    Joystick turnStick;
    Joystick operatorStick;
    Robot *robot;
  public:
  Joystick(Robot *robot)
  void update()
};
#endif
