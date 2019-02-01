#pragma config(Motor,  port2,           fLeft,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           fRight,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           bLeft,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           bRight,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           fDisk,         tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(0)
#pragma userControlDuration(60)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                         Driver Skills Template
//
// This is a template for the driver skills competition. It is identical in structure to
// the standard competition template except that the two "#pragma' statements above (and
// copied below) adjust the time limits for the competition.
//				#pragma autonomousDuration(0)
//				#pragma userControlDuration(60)
// The autonomous duration for "Driver Skills" is zero; i.e. there is no autonomous phase.
// The user control duration is 60 seconds
//
// NOTE: The above two pragmas only impact the Crystal implementation. For systems using
//       VEXNET, the VEXNET system ignores these statements as it has the durations
//       for the competition built-in.
//
// Whenever this user program is run, the duration is automatically sent to the VEX master
// processor. The master CPU will only accept these commands once per power=on cycle. So, it's
// best to power cycle your VEX to ensure that they get recognized in case you were
// previously running a standard competition program with different durations.
//
// Testing Via Crystals:
// ====================
//
// The procedure to test a Driver Skills program using the crystals is as follows:
//
// 1. Turn off power to the Crystal transmitter/joysticks.
//
// 2. Turn on your VEX so that the Driver Skills program is running.
//
// 3. Driver skills program segment of your program will start running. At the end of 60
//    seconds the VEX Master CPU will turn off the motors.
//
// 4. Repeat the above sequence
//
//
// Testing Via VEXNET Using VEXNET Competition Switch
// ==================================================
//
// The procedure to test a Driver Skills program using VEXNET Competition Switch is as follows:
//
// 1. Set the two switches on the Competition switch to "DISABLE" and "USER CONTROL"
//
// 2. Start the Driver skills program
//
// 3. Set Switch to ENABLE from DISABLE
//
// 4. You need to manually time the 60 second duration.
//
// 5. Set Switch to DISABLE
//
// 6. Repeat from step (3) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
//
// Testing Via VEXNET Using ROBOTC IDE
// ==================================================
//
// It is not necessary to own a VEXNET switch. ROBOTC has a test window that allows the same functionality.
// The test window has three buttons for "DISABLE", "AUTONOMOUS", "USER CONTROL".
//
// 1. Open the ROBOTC Debugger. Then open the "Competition Control" Debugger window.
//
// 2. Start your Driver Skills program running.
//
// 3. Click the "DISABLED" button on the "Competition Control" window.
//
// 4. Click the "USER CONTROL" button on the "Competition Control" window.
//
// 5. You need to manually time the 60 second duration.
//
// 6. Click the "DISABLED" button on the "Competition Control" window.
//
// 7. Repeat from step (4) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// The "Driver Skills" competition has no autonomous phase. Simply leave the following
// placeholder.
//
/////////////////////////////////////////////////////////////////////////////////////////

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

void liftLift (int speed, int durationMilliseconds)
{
	motor[lift] = speed;
	wait1Msec(durationMilliseconds);
	stopRobot();
}

void lowerLift (int speed, int durationMilliseconds)
{
	motor[lift] = -1 * speed;
	wait1Msec(durationMilliseconds);
	stopRobot();
}

void flipDisk (int speed, int durationMilliseconds)
{
	motor[fDisk] = speed;
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
//																		ROWAN, RYAN, AND/OR BRANDON: DO NOT CHANGE																													//

//BRAND NEW BATTERY
//FRONT FACING FLAGS
	moveBackward (100, 1500); //BACKWARD 2 BOX TO FLAG
stopRobot ();
wait1Msec(500);
moveForward (100, 800); //FORWARD 1 BOX
stopRobot ();
wait1Msec(500);
turnLeft(100,750);	//TURN LEFT 90 TO DISK
stopRobot ();
wait1Msec(500);
moveForward (100,160); //FORWARD 1/4 BOX
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
turnLeft (100,750); //TURN 90 FRONT FACING FLAGS
stopRobot ();
wait1Msec(500);
moveBackward (100,1350); //BACKWARD 2 BOXES - TO MID
stopRobot ();
wait1Msec(500);
turnLeft (100,730); //TURN 90 BACK FACING PLATFORMS
stopRobot ();
wait1Msec(500);
moveBackward (100,2600); //BACKWARD 1 1/2 BOX FOR THE ALLIANCE PLATFORM
stopRobot ();
wait1Msec(500);
//FIN

/*
//AFTER 10 RUNS
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
moveBackward (100,2600); //BACKWARD 1 1/2 BOX FOR THE ALLIANCE PLATFORM
stopRobot ();
wait1Msec(500);*/
//FIN


}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

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
