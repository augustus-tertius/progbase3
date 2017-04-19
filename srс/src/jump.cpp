// #include <iostream>
#include "jump.h" 


Jump::Jump(){
    this->jumped = false;
    this->timeInJump = 0;
    this->speedAtStart = 0.5;
}

void Jump::started(){
    this->jumped = true;
}

void Jump::update(float timePassed){
    this->timeInJump += timePassed;
}

void Jump::ended(){
    this->jumped = false;
}
