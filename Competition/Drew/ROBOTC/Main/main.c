#pragma config(Motor,  port1,           dBackRight,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           piston,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           dFrontLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           flipper,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           dFrontRight,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           dBackLeft,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !! *//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

#include "motors.h"
#include "auto_functions.h"
#include "auto_selector.h"

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
		_skills_old();
		_skills_old_thesequel();
	}
	while(bIfiRobotDisabled)
		getInput();  // Get Input for auto selection
}

task autonomous()
{
	doAuto(); // Jump to auto selector code
}

task usercontrol()
{
	while(true)
	{
		if(vexRT[Btn8D] == 1)
			fireBall(true);
		mapJoystick();
	}
}
