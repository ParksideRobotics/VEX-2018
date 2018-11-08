#pragma config(Motor,  port2,           leftSide,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightSide,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

void pre_auton()
{
	bStopTasksBetweenModes = true;
	bDisplayCompetitionStatusOnLcd = false;
}

task autonomous()
{
	AutonomousCodePlaceholderForTesting(); // Remove this when you have real code.
}

task usercontrol()
{
	while(true)
	{
		motor[leftSide] = vexRT[Ch3];
		motor[rightSide] = vexRT[Ch2];
	}
}