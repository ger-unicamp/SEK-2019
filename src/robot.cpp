#include "robot.h"

robot::run_forever(int speed){
    this->right_motor.set_speed_sp(speed).run_forever();
    this->left_motor.set_speed_sp(speed).run_forever();
}

robot::run_forever(){
    this->right_motor.run_forever();
    this->left_motor.run_forever();
}