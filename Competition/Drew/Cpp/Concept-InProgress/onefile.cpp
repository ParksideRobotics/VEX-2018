#include "robot-config.h"

namespace auto {
    class AutoFunctions {
        public:
        void stopRobot();
        void moveForward(uint32_t time, double speed);
        void moveBackward(uint32_t time, double speed);
        void leftSpin(uint32_t time, double speed); 
        void rightSpin(uint32_t time, double speed);
        void rightVeer(uint32_t time, double speed, double o);
        void leftVeer(uint32_t time, double speed, double o);
        void feedBall(uint32_t time);
        bool fireBall();
        
        private enum LIFT_STATES {
            STOPPED,
            STARTED,
            READY
        };
        
    } extern AutoFunctions functions;


    void AutoFunctions::stopDrive(){
        p_lDrive.stop();
        p_rDrive.stop();
    }

    void AutoFunctions::moveForward(uint32_t time, double speed){
        p_lDrive.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
        p_rDrive.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
        task::sleep(time);
        stopDrive();
    }

    void AutoFunctions::moveBackward(uint32_t time, double speed){
        p_lDrive.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
        p_rDrive.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
        task::sleep(time);
        stopDrive();
    }

    void AutoFunctions::leftTurn(uint32_t time, double speed){
        p_lDrive.spin(directionType::fwd, speed, velocityUnits::pct);
        task::sleep(time);
        stopDrive();
    }

    void AutoFunctions::rightTurn(uint32_t time, double speed){
        p_rDrive.spin(directionType::fwd, speed, velocityUnits::pct);
        task::sleep(time);
        stopDrive();
    }

    void AutoFunctions::leftSpin(uint32_t time, double speed){
        p_lDrive.spin(directionType::rev, speed, velocityUnits::pct);
        p_rDrive.spin(directionType::fwd, speed, velocityUnits::pct);
        task::sleep(time);
        stopDrive();
    }

    void AutoFunctions::rightSpin(uint32_t time, double speed){
        p_lDrive.spin(directionType::fwd, speed, velocityUnits::pct);
        p_rDrive.spin(directionType::rev, speed, velocityUnits::pct);
        task::sleep(time);
        stopDrive();
    }

    void AutoFunctions::rightVeer(uint32_t time, double speed, double o){
        p_lDrive.spin(directionType::fwd, speed, velocityUnits::pct);
        p_rDrive.spin(directionType::rev, speed - o, velocityUnits::pct)
        task::sleep(time);
        stopDrive();
    }

    void AutoFunctions::leftVeer(uint32_t time, double speed, double o){
        p_lDrive.spin(directionType::rev, speed - o, velocityUnits::pct);
        p_rDrive.spin(directionType::fwd, speed, velocityUnits::pct);
        task::sleep(time);
        stopDrive();
    }

    void AutoFunctions::feedBall(uint32_t time){
        mainLift = STARTED;
        p_elevator.spin(directionType::fwd, 100, velocityUnits::pct);
        task::sleep(time);
        mainLift = READY; // Assuming ball has fed into the piston
        // TODO: Add actual way to check we have a ball (HW & SW)
        p_elevator.stop();
    }

    bool AutoFunctions::fireBall(){
        if(mainLift != READY)
            return false; // Ball shot failed, we return false
        // We want the ball to be fed first

        // TODO: Add adjustment function for angle of shot
        // adjustAngle(position);

        p_piston.spin(directionType::fwd, 100, velocityUnits::pct);
        task::sleep(PISTON_LENGTH); // Placeholder for time
        p_piston.stop();

        mainLift = STOPPED; // Reset lift for next shot

        return true; // Shot completed successfully
    }
};

namespace drive {
    class DriveFunctions {
        private:
        bool lift   = false;
        bool firing = false;
        
        public:
        inline bool getLiftState(){
            return lift;
        }
        
        inline bool getFireState(){
            return firing;
        }
        
        inline double arcade_drive(vex::controller c_controller, bool positive) {
            if(reversed)
                return (c_controller.Axis3.value() + c_controller.Axis4.value()) / 2;
            else
                return (c_controller.Axis3.value() - c_controller.Axis4.value()) / 2;
        }
    }; extern DriveFunctions functions;
    
    void DriveFunctions::mapJoystick() {
        p_lDrive.spin(directionType::fwd, drive::functions.arcade_drive(drive_controller, false), vex::velocityUnits::pct);
        p_rDrive.spin(directionType::fwd, drive::functions.arcade_drive(drive_controller, true), vex::velocityUnits::pct);
        p_pistonAdjuster.spin(directionType::fwd, piston_controller.Axis1.value(), vex::velocityUnits::pct);
        
        if(piston_controller.ButtonA.pressed()){
            lift = !lift;
        }else if(lift) {
            p_elevator.spin(directionType::fwd, 100, velocityUnits::pct);
        }else if(!lift){
            p_elevator.stop();
        }
        
        if(piston_controller.ButtonB.pressed()) {
            firing = !firing;
        }else if(firing){
            p_piston.spin(directionType::fwd, 100, velocityUnits::pct);
        }else if(!firing){
            p_piston.stop();
        }
    }
};

void pre_auton() {
    // All activities that occur before competition start
    // Example: setting initial positions

}

void autonomous() {
    // Place autonomous code here

}

void drivercontrol() {
    while (true) 
        drive::functions.mapJoystick();
}

int main() {
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);
    
    pre_auton();

}