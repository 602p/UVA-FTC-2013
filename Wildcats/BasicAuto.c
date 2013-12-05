#pragma config(Hubs   , S1          , HTMotor , none                   , none     , none  )
#pragma config(Sensor , S1          ,         , sensorI2CMuxController ,          ,       )
#pragma config(Motor  , mtr_S1_C1_1 , motor1  , tmotorTetrix           , openLoop ,       )
#pragma config(Motor  , mtr_S1_C1_2 , motor2  , tmotorTetrix           , openLoop ,       )
//Setup Motors^

//========================================//
//This Autonomous script will drive       //
//forward for one second using motors one //
//and two on a TETRIX/MATRIX DC motor hub //
//attached to sensor port one.            //
//========================================//

//This variable controlls waiting for autonomous to start before moving motors. Values are:
// true  :: do wait for auto mode to start. This mode only works with samantha.
// false :: move motors once program is run. This mode can be used without samantha.
const bool useFCS = true;

//Need joystick module for bluetooth messages...
#include "JoystickDriver.c"

task main()
{
  	if (useFCS){
  		waitForStart();    // Wait for the beginning of autonomous phase.
  	}
	motor[motor1]=100;     //Turn on motors
	motor[motor2]=100;     //Other one too...
	wait1Msec(1000);       //Wait one Second
	motor[motor1]=0;       //Turn off motors
  	motor[motor2]=0;       //Other one too...
}