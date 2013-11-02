#include <WPILib.h>

#define PORT_DRIVE_VIC_1 5
#define PORT_DRIVE_VIC_2 10
#define PORT_DRIVE_VIC_3 2
#define PORT_DRIVE_VIC_4 1
#define PORT_JS_SPEED 1
#define PORT_JS_TURN 2
#define PORT_JS_CONTROL 3
#define PORT_COMPRESSOR_RELAY 1
#define PORT_COMPRESSOR_END 1
#define PORT_SOLENOID_YES 5
#define PORT_SHOOT_VIC_1 3
#define PORT_SHOOT_VIC_2 4
enum{
	IDLE,
	SPINNING,
	EXTENDING,
	RECEDING,
}shooterState;
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
	Timer shootTimer;
	Timer recedeTimer;

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
		t(),
		shootTimer(),
		recedeTimer()
	{
	}

	void AutonomousInit() {
		t.Start();
		Compressor *c = new Compressor(1, 1);
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
		printf("Autonomous mode Disabled\n");
	}
	void TeleopInit(){

	}
	void TeleopPeriodic(){
		leftVic1.Set(speedStick.GetY()+turnStick.GetX());
		leftVic2.Set(speedStick.GetY()+turnStick.GetX());
		rightVic1.Set(-(speedStick.GetY()-turnStick.GetX()));
		rightVic2.Set(-(speedStick.GetY()-turnStick.GetX()));
		if(shooterState==IDLE){
			if(controlStick.getTrigger()==true){
				shooterState=SPINNING;
			}
		}
		else if(shooterState==SPINNING){
			printf("Charging up\n");
			shootTimer.Start();
			shootVic1.Set(1.0);
			shootVic2.Set(1.0);
			if(shootTimer.Get()==5.0){
			aSolenoid.Set(true);
			}
			if(shootTimer.Get()>5.0){ //check this later
				shooterState=EXTENDING;
			}
		}
		else if(shooterState==EXTENDING){
			if(shootTimer.Get()>6.0){
			aSolenoid.Set(false);
			shootTimer.Stop();
			shootTimer.Reset();
			shooterState=RECEDING;
			}
		}
		else if(shooterState==RECEDING){
			printf("Retracting\n");
			recedeTimer.Start();
			if(recedeTimer.Get()>2.0){
				recedeTimer.Stop();
				recedeTimer.Reset();
				shooterState=IDLE;
			}
			
		}
	}
	void TeleopDisabled(){
		printf("Teleop Disabled\n");
	}
};

START_ROBOT_CLASS(MyRobot);
