#include "WPILib.h"
#include "Photo_Eye_V2.h"
/**
 * this program should be used to get the count form the photo eye from there treat it as an encoder and attempt the math used to get rpm 
 */
class RobotDemo : public SimpleRobot
{
		RobotDrive myRobot; // robot drive system
		Joystick stick; // only joystick
		Victor launcher;	
		DriverStation *ds;
		DriverStationLCD *dsLCD;
		PhotoEyeV2 PhotoEye;
		Timer Time;
	public:
		RobotDemo(void):// these must be initialized in the same order as they are declared above.
			myRobot(1, 2),	
			stick(1),
			launcher(2),
			ds(DriverStation::GetInstance()),
			dsLCD(DriverStationLCD::GetInstance()),
			PhotoEye(3)
			{
			Timer *Time;
			Time = new Timer(); 
			//autonTimer->Start();
			myRobot.SetExpiration(0.1);
			}
		void Return_RPM()
		{
			PhotoEye.Reset();
			PhotoEye.Start();
			if(PhotoEye.Get()>0)
			{
			Time.Start();
			int unit = PhotoEye.Get();
			double RPM = ((double)unit/Time.Get())* 60;//gives RPM
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line3, "wheel is: (%d)Rpm", RPM);//print out digital output 
			dsLCD->UpdateLCD();
			}
			
		}
		void ReturnPhotoEyeCount()
		{
			PhotoEye.Reset();
			PhotoEye.Start();
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line2, "Photo-Eye: %d", PhotoEye.Get());//print out digital output 
			dsLCD->UpdateLCD();
			PhotoEye.Stop();
		}
	//autonomous
		void Autonomous(void)
		{
		}
	// tele-op
		void OperatorControl(void)
		{
			myRobot.SetSafetyEnabled(true);
			while (IsOperatorControl())
			{
				Wait(0.005);// wait for a motor update time
			}
		}
};

START_ROBOT_CLASS(RobotDemo);

