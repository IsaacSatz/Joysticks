#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <WPIlib.h>
#define PORT_JS_SPEED 1
#define PORT_JS_TURN 2
#define PORT_JS_OPERATOR 3
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
