#pragma config(Motor,  port1,           dBackRight,    tmotorVex393TurboSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           dBackLeft,     tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           dFrontRight,   tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           dFrontLeft,    tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           pistonLeft,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           pistonRight,   tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

#include "motors.h"
#include "auto_functions.h"

void pre_auton()
{
	bDisplayCompetitionStatusOnLcd = false;
	bStopTasksBetweenModes = true;
	if(false) { //Putting these here so no compile warnings
		singleJoystick();
		moveForward(0, 0);
		moveBackward(0, 0);
		leftTurn(0, 0);
		rightTurn(0, 0);
		rightVeer(0, 0, 0);
		leftVeer(0, 0, 0);
		rightSpin(0, 0);
		leftSpin(0, 0);
		feedBall(0);
		fireBall();
	}
}

task autonomous()
{

}

task usercontrol()
{
	while(true)
	{
		if(vexRT[Btn8U] == 1) startTask(autonomous);
		mapJoystick();
	}
}
