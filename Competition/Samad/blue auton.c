#pragma config(Motor,  port2,           frontrightmotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontleftmotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backrightmotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backleftmotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           arm1,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           arm2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           fliptable,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           arm1top,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          arm2top,       tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/

/*                                                                           */

/*        Description: Competition template for VEX EDR                      */

/*                                                                           */

/*---------------------------------------------------------------------------*/



// This code is for the VEX cortex platform

#pragma platform(VEX2)



// Select Download method as "competition"

#pragma competitionControl(Competition)



//Main competition background code...do not modify!

#include "Vex_Competition_Includes.c"


void stop_Robot()

{
	// stop the robot
	motor[frontrightmotor] = 0;
	motor[backrightmotor] = 0;
	motor[frontleftmotor] =0;
	motor[backleftmotor] = 0;
	motor[fliptable] = 0;
	motor[arm1] = 0;
	motor[arm2] = 0;
	motor[arm1top] = 0;
	motor[arm2top] = 0;
}


void forward()

{
	// go forward
	motor[frontrightmotor] = 127;
	motor[frontleftmotor] = 127;
	motor[backrightmotor] = 127;
	motor[backleftmotor] = 127;

}




void pre_auton(){

}


task autonomous(){



	// blue auton

	// go backwards go forward turnright flipdown go forwards flip upwards stop robot

	// backward for 2 seconds
	motor[frontrightmotor] = -127;
	motor[backrightmotor] = -127;
	motor[frontleftmotor] = -127;
	motor[backleftmotor] = -127;
	wait1Msec(2000);
	stop_Robot();
	// forward for 2 seconds
	forward();
	wait1Msec(2000);
	stop_Robot();
	// turn right for 1.52 secoonds
	motor[frontleftmotor] = 127;
	motor[backleftmotor] = 127;
	motor[frontrightmotor] = -127;
	motor[backrightmotor] = -127;
	wait1Msec(2000);
	stop_Robot();
	//flip downwards for .75 seconds
	motor[fliptable] = -127;
	wait1Msec(750);
	stop_Robot();
	// forward for 1.6 seconds
	motor[frontrightmotor] = 127;
	motor[backrightmotor] = 127;
	motor[frontleftmotor] = 127;
	motor[backrightmotor] = 127;
	wait1Msec(1600);
	stop_Robot();
	// flip upwards for .75 seconds
	motor[fliptable] = 127;
	wait1Msec(750);
	stop_Robot();
}
















task usercontrol()

{





	while (true)

	{


		motor[backrightmotor]  = vexRT[Ch3];
		motor[frontleftmotor]  = vexRT[Ch3];
		motor[frontrightmotor] = vexRT[Ch2];
		motor[backleftmotor] = vexRT[Ch2];


		motor[arm1] = vexRT[Ch2Xmtr2];
		motor[arm2] = vexRT[Ch2Xmtr2];
		motor[arm1top] = vexRT[Ch2Xmtr2];
		motor[arm2top] = vexRT[Ch2Xmtr2];



		motor[fliptable] = vexRT[Ch3Xmtr2];



	}

}
