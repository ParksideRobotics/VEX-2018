#pragma config(Motor,  port2,           fLeft,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           fRight,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           bLeft,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           bRight,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           fDisk,         tmotorVex393_MC29, openLoop)
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

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void stopRobot()
{
	motor[bLeft] = 0;
	motor[bRight] = 0;
	motor[fLeft] = 0;
	motor[fRight] = 0;
	motor[lift] = 0;
	motor[arm] = 0;
	motor[fDisk] = 0;
}

void moveForward(int speed, int durationMilliseconds)
{
	motor[bLeft] = speed;
	motor[bRight] = speed;
	motor[fLeft] = speed;
	motor[fRight] = speed;
	wait1Msec(durationMilliseconds);
	stopRobot();
}

void moveBackward(int speed, int durationMilliseconds)
{
	motor[bLeft] = -1 * speed;
	motor[bRight] = -1 * speed;
	motor[fLeft] = -1 * speed;
	motor[fRight] = -1 * speed;
	wait1Msec(durationMilliseconds);
	stopRobot();
}

void turnLeft(int speed, int durationMilliseconds)
{
	motor[bLeft] = -1 * speed;
	motor[bRight] = speed;
	motor[fLeft] = -1 * speed;
	motor[fRight] = speed;
	wait1Msec(durationMilliseconds);
	stopRobot();
}

void turnRight(int speed, int durationMilliseconds)
{
	motor[bLeft] = speed;
	motor[bRight] = -1 * speed;
	motor[fLeft] = speed;
	motor[fRight] = -1 * speed;
	wait1Msec(durationMilliseconds);
	stopRobot();

}

void liftArm (int speed, int durationMilliseconds)
{
	motor[arm] = speed;
	wait1Msec(durationMilliseconds);
	stopRobot();
}

void lowerArm (int speed, int durationMilliseconds)
{
	motor[arm] = -1 * speed;
	wait1Msec(durationMilliseconds);
	stopRobot();
}

task autonomous()
{

/*
moveBackward (100, 1400); //BACKWARD 2 BOX TO FLAG
stopRobot ();
wait1Msec(500);
moveForward(100, 2400);	//FORWARD 3 BOX TO MID
stopRobot ();
wait1Msec(500);
turnRight(100,1100);	//TURN RIGHT 90 TO PLATFORM (RED ALLIANCE)
//turnLeft(100,1100);	//TURN LEFT 90 TO PLATFORM (BLUE ALLIANCE)
stopRobot ();
wait1Msec(500);
moveBackward(100, 2000);	//FORWARD 2 BOX ONTO PLATFORM
stopRobot ();
wait1Msec(500);
//FIN
*/

//RED ALLIANCE
//FRONT FACING FLAGS
	moveBackward (100, 1500); //BACKWARD 2 BOX TO FLAG
stopRobot ();
wait1Msec(500);
moveForward (100, 800); //FORWARD 1 BOX
stopRobot ();
wait1Msec(500);
turnLeft(100,800);	//TURN LEFT 90 TO DISK
stopRobot ();
wait1Msec(500);
moveForward (100,250); //FORWARD 1/4 BOX
stopRobot ();
wait1Msec(500);
liftArm (100,700); //LIFT 30 OR UNTIL FLIP
moveForward (100,100); //FORWARD TO PUSH DISK
stopRobot ();
wait1Msec(500);
lowerArm (100,500); //LOWER LIFT TO NEUTRAL
stopRobot ();
wait1Msec(500);
moveBackward (100,100); //REVERSE OF 224
stopRobot ();
wait1Msec(500);
turnLeft (100,850); //TURN 90 FRONT FACING FLAGS
stopRobot ();
wait1Msec(500);
moveBackward (100,1400); //BACKWARD 2 BOXES - TO MID
stopRobot ();
wait1Msec(500);
turnLeft (100,800); //TURN 90 BACK FACING PLATFORMS
stopRobot ();
wait1Msec(500);
moveBackward (100,1900); //BACKWARD 1 1/2 BOX FOR THE ALLIANCE PLATFORM
stopRobot ();
wait1Msec(500);
//FIN

/*
//BLUE ALLIANCE
moveBackward (100, 1500); //BACKWARD 2 BOX TO FLAG
stopRobot ();
wait1Msec(500);
moveForward (100, 800); //FORWARD 1 BOX
stopRobot ();
wait1Msec(500);
turnRight(100,700);	//TURN LEFT 90 TO DISK
stopRobot ();
wait1Msec(500);
moveForward (100,150); //FORWARD 1/4 BOX
stopRobot ();
wait1Msec(500);
liftArm (100,700); //LIFT 30 OR UNTIL FLIP
moveForward (100,100); //FORWARD TO PUSH DISK
stopRobot ();
wait1Msec(500);
lowerArm (100,500); //LOWER LIFT TO NEUTRAL
stopRobot ();
wait1Msec(500);
moveBackward (100,100); //REVERSE OF 224
stopRobot ();
wait1Msec(500);
turnRight (100,700); //TURN 90 FRONT FACING FLAGS
stopRobot ();
wait1Msec(500);
moveBackward (100,1350); //BACKWARD 2 BOXES - TO MID
stopRobot ();
wait1Msec(500);
turnRight (100,700); //TURN 90 BACK FACING PLATFORMS
stopRobot ();
wait1Msec(500);
moveBackward (100,1600); //BACKWARD 1 1/2 BOX FOR THE ALLIANCE PLATFORM
stopRobot ();
wait1Msec(500);
*/
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{

  while (true)
  {
//Joystick Control
		motor[fLeft] = vexRT[Ch3];
		motor[fRight] = vexRT[Ch2];
		motor[bLeft] = vexRT[Ch3];
		motor[bRight] = vexRT[Ch2];

		//5U & 5D - Arm
	  if(vexRT[Btn5U] == 1) {
			motor[arm] = 100;}
		else if (vexRT[Btn5D]) {
			motor[arm] = -100;}
    else {
			motor[arm] = 0;
		}

		//Lift
		if(vexRT[Btn6U] == 1) {
			motor[lift] = 100;}
		else if (vexRT[Btn6D]) {
			motor[lift] = -100;}
    else {
			motor[lift] = 0;
		}

		//Flip Disk Control 8U/ 8R
   	if(vexRT[Btn8U] == 1){
			motor[fDisk] = -80;}
	  else if(vexRT[Btn8R] == 1){
			motor[fDisk] = 80;}
	  else {
			motor[fDisk]=0;
		}


		}
	}
