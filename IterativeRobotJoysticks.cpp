#include <WPILib.h>

#define PORT_DRIVE_VIC_1 5
#define PORT_DRIVE_VIC_2 10
#define PORT_DRIVE_VIC_3 2
#define PORT_DRIVE_VIC_4 1
#define PORT_JS_SPEED 1
#define PORT_JS_TURN 2
#define PORT_JS_CONTROL 3

class MyRobot : public IterativeRobot {
	Victor leftVic1;
	Victor leftVic2;
	Victor rightVic1;
	Victor rightVic2;
	Joystick speedStick;
	Joystick turnStick;
	Joystick controlStick;
	Timer t;

	public:
	MyRobot():
		leftVic1(PORT_DRIVE_VIC_1),
		leftVic2(PORT_DRIVE_VIC_2),
		rightVic1(PORT_DRIVE_VIC_3),
		rightVic2(PORT_DRIVE_VIC_4),
		speedStick(PORT_JS_SPEED),
		turnStick(PORT_JS_TURN),
		controlStick(PORT_JS_CONTROL),
		t()
	{
	}

	void AutonomousInit() {
		t.Start();
	}
	void AutonomousPeriodic(){
		if(t.Get()<5.0){
			leftVic1.Set(0.5);
			leftVic2.Set(0.5);
			rightVic1.Set(-0.5);
			rightVic2.Set(-0.5);
		}
		else if(t.Get()<10.0){
			leftVic1.Set(0.5);
			leftVic2.Set(0.5);
			rightVic1.Set(0.0);
			rightVic2.Set(0.0);
		}
		else if(t.Get()<15.0){
			leftVic1.Set(0.0);
			leftVic2.Set(0.0);
			rightVic1.Set(0.0);
			rightVic2.Set(0.0);
		}
	}
	void AutonomousDisabled(){
		printf("Autonomous mode disabled\n");
	}
	void TeleopInit(){

	}
	void TeleopPeriodic(){
		leftVic1.Set(speedStick.GetY()+turnStick.GetX());
		leftVic2.Set(speedStick.GetY()+turnStick.GetX());
		rightVic1.Set(-(speedStick.GetY()-turnStick.GetX()));
		rightVic2.Set(-(speedStick.GetY()-turnStick.GetX()));
	}
	void TeleopDisabled(){
		printf("Teleop Disabled\n");
	}
};

START_ROBOT_CLASS(MyRobot);
