#pragma config(Hubs   , S1          , HTMotor , none                   , none     , none     )
#pragma config(Sensor , S1          ,         , sensorI2CMuxController ,          ,          )
#pragma config(Motor  , mtr_S1_C1_1 , motor1  , tmotorTetrix           , openLoop , reversed )
#pragma config(Motor  , mtr_S1_C1_2 , motor2  , tmotorTetrix           , openLoop ,          )
//Setup Motors^

//========================================//
//This TeleOp code allows for driving the //
//robot using the Y axis of ONE controller//
//thingy. Can be used with samantha or    //
//wired directly.                         //
//========================================//

//Allow Use Of Joysticks:
#pragma  debuggerWindows("joystickSimple");
#include "JoystickDriver.c"

//Define Constants:
const int THRESHOLD  =10;
const int SPEED_MULT =1 ;

//Main Code:
task main(){
	while(true){ //Repeat the following forever:
		if(abs(SPEED_MULT * joystick.joy1_y1) > THRESHOLD) { //If the joystick is outside of the deadzone:
			motor[motor1] = SPEED_MULT * joystick.joy1_y1;   //Set motor speed to joystick value * multiplier
		}else{                                               //Otherwise:
			motor[motor1] = 0;                               //Set motor to 0
		}
		if(abs(SPEED_MULT * joystick.joy1_y2) > THRESHOLD) { //If the joystick is outside of the deadzone:
			motor[motor2] = SPEED_MULT * joystick.joy1_y2;   //Set motor speed to joystick value * multiplier
		}else{                                               //Otherwise:
			motor[motor2] = 0;                               //Set motor to 0
		}
	}
}
