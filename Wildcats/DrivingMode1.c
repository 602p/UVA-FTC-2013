#pragma config(Hubs  ,  S1         , HTMotor   , HTMotor               ,  HTMotor, none     )
#pragma config(Sensor,  S1         ,           , sensorI2CMuxController                     )
#pragma config(Motor ,  mtr_S1_C1_1, leftDrive , tmotorTetrix          , openLoop, reversed )
#pragma config(Motor ,  mtr_S1_C1_2, rightDrive, tmotorTetrix          , openLoop           )
#pragma config(Motor ,  mtr_S1_C2_2, arm       , tmotorTetrix          , openLoop           )
#pragma config(Motor ,  mtr_S1_C3_2, elbow     , tmotorTetrix          , openLoop           )
#pragma config(Motor ,  mtr_S1_C2_1, spinner   , tmotorTetrix          , openLoop           )
#pragma config(Motor ,  mtr_S1_C3_1, gripper   , tmotorTetrix          , openLoop           )
//Setup Motors^

//For control mappings refer to /notes.txt

//Allow Use Of Joysticks:
#pragma  debuggerWindows("joystickSimple");
#include "JoystickDriver.c"

//Define Constants:
const int THRESHOLD   =10;
const int SPEED_MULT  =1 ;
const int ARM_SPEED   =50;
const int ELBOW_SPEED =50;
const int SPIN_SPEED  =75;
const int GRIP_SPEED  =40;

//Main Code:
task main(){
	while(true){ //Repeat the following forever:

		{ // Driving code:
			if(abs(SPEED_MULT * joystick.joy1_y1) > THRESHOLD) { //If the joystick is outside of the deadzone:
				motor[leftDrive] = SPEED_MULT * joystick.joy1_y1;   //Set motor speed to joystick value * multiplier
			}else{                                               //Otherwise:
				motor[leftDrive] = 0;                               //Set motor to 0
			}
			if(abs(SPEED_MULT * joystick.joy1_y2) > THRESHOLD) { //If the joystick is outside of the deadzone:
				motor[rightDrive] = SPEED_MULT * joystick.joy1_y2;   //Set motor speed to joystick value * multiplier
			}else{                                               //Otherwise:
				motor[rightDrive] = 0;                               //Set motor to 0
			}
		}

		{ // Hat control
			if (joystick.joy1_TopHat==0 || joystick.joy1_TopHat==1 || joystick.joy1_TopHat==7){ // Arm Forward
				motor[arm]=ARM_SPEED;
			}else{
				if (joystick.joy1_TopHat==4 || joystick.joy1_TopHat==3 || joystick.joy1_TopHat==5){ // Arm Backward
					motor[arm]=-ARM_SPEED;
				}else{
					motor[arm]=0;
				}
			}
			if (joystick.joy1_TopHat==2 || joystick.joy1_TopHat==3 || joystick.joy1_TopHat==1){ // Elbow forward
				motor[elbow]=ELBOW_SPEED;
			}else{
				if (joystick.joy1_TopHat==6 || joystick.joy1_TopHat==7 || joystick.joy1_TopHat==5){ // Elbow backward
					motor[elbow]=-ELBOW_SPEED;
				}else{
					motor[elbow]=0;
				}
			}
		}

		{ // Spinner control
			if (joy1Btn(0)==1){
				motor[spinner]=SPIN_SPEED;
			}else{
				if (joy1Btn(1)==1){
					motor[spinner]=-SPIN_SPEED;
				}else{
					motor[spinner]=0;
				}
			}
		}

		{ // Gripper control
			if (joy1Btn(2)==1){
				motor[gripper]=GRIP_SPEED;
			}else{
				if (joy1Btn(3)==1){
					motor[gripper]=-GRIP_SPEED;
				}else{
					motor[gripper]=0;
				}
			}
		}
	}
}
