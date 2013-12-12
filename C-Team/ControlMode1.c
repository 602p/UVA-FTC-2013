#pragma config(Hubs  ,  S1          , HTMotor, HTMotor               , HTServo , none     )
#pragma config(Sensor,  S1          ,        , sensorI2CMuxController                     )
#pragma config(Motor ,  mtr_S1_C1_1 , motor1 , tmotorTetrix          , openLoop, reversed )
#pragma config(Motor ,  mtr_S1_C1_2 , motor2 , tmotorTetrix          , openLoop           )
#pragma config(Motor ,  mtr_S1_C2_1 , spnmtr , tmotorTetrix          , openLoop           )
#pragma config(Servo ,  srvo_S1_C3_1, Arm    , tServoStandard                             )
#pragma config(Servo ,  srvo_S1_C3_2, Elbow  , tServoStandard                             )
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
float ArmServo = 102;
float ElbowServo = 0;

//Main Code:
task main(){
	while(true){ //Repeat the following forever:
		{ // Driving
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

		{ if(joy1Btn(7)==1){
			motor[spnmtr]=-50;
		}else{
			if(joy1Btn(8)==1){
				motor[spnmtr]=50;
				}else{ motor[spnmtr]=0;
				}
			}
			if(joy1Btn(2)==1){
				ArmServo = ArmServo - 0.1;
			}else{
				if(joy1Btn(4)==1){
					ArmServo = ArmServo + 0.1;
				}

			}
			if(joy1Btn(5)==1){
				ElbowServo = ElbowServo - 0.1;
			}else{
				if(joy1Btn(6)==1){
					ElbowServo = ElbowServo + 0.1;
				}

			}
			if(ElbowServo > 255){
				ElbowServo = 255;
				servo[Elbow] = ElbowServo;}
				else if(ElbowServo < 0){
					ElbowServo = 0;
					servo[Elbow] = ElbowServo;}
					else
					{servo[Elbow] = ElbowServo;}
			if(ArmServo > 255){
				ArmServo = 255;
				servo[Arm] = ArmServo;}
				else if(ArmServo < 0){
					ArmServo = 0;
					servo[Arm] = ArmServo;}
					else
					{servo[Arm] = ArmServo;}
			nxtDisplayTextLine(4, "   ELBOW: %f", ElbowServo);
			nxtDisplayTextLine(4, "   ARM  : %f", ArmServo);
		}

	}
}
