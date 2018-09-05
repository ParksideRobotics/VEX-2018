#pragma config(Motor,  port2,           p_driveRight,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           p_driveLeft,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           p_piston,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           p_liftLowLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           p_liftLowRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           p_liftUpLeft,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           p_liftUpRight, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

#include "motors_concept.h" // Motors, concept code.

void pre_auton()
{
	bDisplayCompetitionStatusOnLcd = false;
	bStopTasksBetweenModes = true;
}

task autonomous()
{

}

task usercontrol()
{
	while(true)
	{
		mapJoystick();
	}
}
