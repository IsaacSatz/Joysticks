#include "WPILib.h"
#define PORT_DRIVE_VIC_1 5
#define PORT_DRIVE_VIC_2 10
#define PORT_DRIVE_VIC_3 2
#define PORT_DRIVE_VIC_4 1
#define PORT_JS_SPEED 1
#define PORT_JS_TURN 2
#define PORT_JS_CONTROL 3

class MyRobot : public SimpleRobot {
Victor leftVic1;
Victor leftVic2;
Victor rightVic1;
Victor rightVic2;
Joystick speedStick;
Joystick turnStick;
Joystick controlStick;

public:
MyRobot() :
  leftVic1(PORT_DRIVE_VIC_1),
  leftVic2(PORT_DRIVE_VIC_2),
  rightVic1(PORT_DRIVE_VIC_3),
  rightVic2(PORT_DRIVE_VIC_4)
  speedStick(PORT_JS_SPEED),
  turnStick(PORT_JS_TURN),
  controlStick(PORT_JS_CONTROL)
{
  
}

void Autonomous(){
//if need be can be changed (most likely will be changed)
//the stuff we want the robot to do during autonomous mode
  //right
  for(int i=0, i<16, i++){
  leftVic1.Set(0.5);
  leftVic2.Set(0.5);
  rightVic1.Set(0.0);
  rightVic2.Set(0.0);
  Wait(2.0);
  //left
  leftVic1.Set(0.0);
  leftVic2.Set(0.0);
  rightVic1.Set(-0.5);
  rightVic2.Set(-0.5);
  wait(2.0);
  //straight
  leftVic1.Set(0.5)
  leftVic2.Set(0.5);
  rightVic1.Set(-0.5);
  rightVic2.Set(-0.5);
  wait(4.0);
  //stop
  leftVic1.Set(0.0)
  leftVic2.Set(0.0);
  rightVic1.Set(0.0);
  rightVic2.Set(0.0);
  }
}

void OperatorControl(){
  while(IsOperatorControl()){
    
  leftVic1.Set(speedStick.GetY+turnStick.GetX);
  leftVic2.Set(speedStick.GetY+turnStick.GetX);
  rightVic1.Set(-(speedStick.GetY-turnStick.GetX));
  rightVic2.Set(-(speedStick.GetY-turnStick.GetX));
  wait(0.005);l
  }
};
START_ROBOT_CLASS(MyRobot);
