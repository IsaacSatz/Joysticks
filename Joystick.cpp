//#include <Joystick.h>
#include <Joystickmove.h>
#include <Robot.cpp>

Joystick::Joystick(Robot *robot)
speedStick(PORT_JS_SPEED),
turnStick(PORT_JS_TURN),
operatorStick(PORT_JS_OPERATOR){
this->robot=robot
}
/*void Joystick::update(){
  if(speedStick.GetX() >= 0.2)
    printf("1X: %f\n", speedStick.GetX());
    leftVic1.Set(0.5);
    leftVic2.Set(0.5);
    rightVic1.Set(-0.5);
    rightVic2.set(-0.5);
  else if(speedsStick.GetX() <= -0.2)
    printf("1X: %f\n", speedStick.GetX());
    leftVic1.Set(-0.5);
    leftVic2.Set(-0.5);
    rightVic1.Set(0.5);
    rightVic.Set(0.5);
  else
    leftVic1.Set(0.0);
    leftVic2.Set(0.0);
    rightVic1.Set(0.0);
    rightVic2.Set(0.0);
  if(turnStick.GetY() >= 0.2 && leftVic1.Get() <= 1.5 && leftVic2.Get() <= 1.5)
    leftVic1.Set(leftVic1.Get()+0.5);
    leftVic2.Set(leftVic2.Get()+0.5);
  else
    rightVic1.Set(rightVic1.Get()+0.5);
    rightVic2.Set(rightVic2.Get()+0.5);
  if(turnStick.GetY() <= -0.2 && rightVic1.Get() >= -1.5 && rightVic2.Get() >= -1.5)
    rightVic1.Set(rightVic1.Get()-0.5);
    rightVic2.Set(rightVic2.Get()-0.5);
  else
    leftVic1.Set(leftVic1.Get()-0.5);
    leftVic2.Set(leftVic2.Get()-0.5);
}*/

