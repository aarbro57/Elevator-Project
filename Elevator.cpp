/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Elevator.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * William Chen, Josef Huang, Aaron Brown, Shiyu Fu
 * chenww, yuyaoh, aarbro, shiyufu
 *
 * Final Project - Elevators
 */

#include "Elevator.h"
#include <iostream>

using namespace std;

void Elevator::tick(int currentTime)
{
    if(currentTime % TICKS_PER_ELEVATOR_MOVE == 0 && isServicing())
    {
        if(targetFloor > currentFloor)
        {
            currentFloor++;
        }
        else if(targetFloor < currentFloor)
        {
            currentFloor--;
        }
    }
    if(targetFloor == currentFloor)
    {
        servicing = false;
    }
}

void Elevator::serviceRequest(int floorNum)
{
    if(floorNum >= 0 && floorNum <= NUM_FLOORS)
    {
        targetFloor = floorNum;
        servicing = true;
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

void Elevator::print(ostream &outs) {
    outs << currentFloor;
    if (!servicing){
        outs << "w";
    } else {
        outs << "s" << targetFloor;
    }
}

Elevator::Elevator() {
    currentFloor = 0;
    servicing = false;
	targetFloor = 0;
}

void Elevator::setCurrentFloor(int currentFloorIn) {
    currentFloor = currentFloorIn;
}

bool Elevator::isServicing() const {
	return servicing;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

int Elevator::getTargetFloor() const {
    return targetFloor;
}
