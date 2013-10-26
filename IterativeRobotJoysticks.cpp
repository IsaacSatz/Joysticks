#include <WPILib.h>

#define PORT_DRIVE_VIC_1 5
#define PORT_DRIVE_VIC_2 10
#define PORT_DRIVE_VIC_3 2
#define PORT_DRIVE_VIC_4 1
#define PORT_JS_SPEED 1
#define PORT_JS_TURN 2
#define PORT_JS_CONTROL 3
#define PORT_COMPRESSOR_RELAY 0
#define PORT_COMPRESSOR_END 0
#define PORT_SOLENOID_YES 0
#define PORT_SHOOT_VIC_1 0
#define PORT_SHOOT_VIC_2 0

class MyRobot : public IterativeRobot {
	Victor leftVic1;
	Victor leftVic2;
	Victor rightVic1;
	Victor rightVic2;
	Joystick speedStick;
	Joystick turnStick;
	Joystick controlStick;
	Solenoid aSolenoid;
	Victor shootVic1;
	Victor shootVic2;
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
		aSolenoid(PORT_SOLENOID_YES),
		shootVic1(PORT_SHOOT_VIC_1),
		shootVic2(PORT_SHOOT_VIC_2),
		t()
	{
	}

	void AutonomousInit() {
		t.Start();
		Compressor *c = new Compressor(PORT_COMPRESSOR_END, PORT_COMPRESSOR_RELAY);//ports not known yet
		c->Start();
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
		if(operatorStick.getTrigger()=true){
			aSolenoid.Set(true);
			//put in shooter victors here
		}
		}
	}
	void TeleopDisabled(){
		printf("Teleop Disabled\n");
	}
};

START_ROBOT_CLASS(MyRobot);
