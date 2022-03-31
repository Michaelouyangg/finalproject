/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Move.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */
 
#include <cmath>
#include <sstream>
#include <stdio.h>      
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move() {
    //TODO: Implement non-default constructor
    //set the default value to false
    isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;

    if (commandString == "") {
        isPass = true;
    }
    else if (commandString == "S" || commandString == "s") {
            isSave = true;
    }
    else if (commandString == "Q" || commandString == "q") {
            isQuit = true;
    }
    else {
        string str = commandString;
        stringstream ss(str);
        char char1;
        char char2;
        ss >> char1 >> elevatorId >> char2;

        if (char2 == 'f') {
            ss >> targetFloor;
            }
        else if (char2 == 'p') {
            isPickup = true;
        }
    }
}

bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    //TODO: Implement isValidMove
    //for three fundamental moves
     if (isPass == true || isQuit == true || isSave == true) {
        return true;
     }
    
    //for Pickup Moves and Servicing Moves
     else if (elevatorId >= 0 && elevatorId < NUM_ELEVATORS) {
            if (!(elevators[elevatorId].isServicing())) {
                if (isPickup == true) {
                    return true;
                    }
                //for Servicing Moves only
                else if (targetFloor >= 0 && targetFloor < NUM_FLOORS) {
                        if (targetFloor != elevators[elevatorId].getCurrentFloor()) {
                            return true;
                            }
                        else {
                            return false;
                            }
                }
            }
     else {
            return false;
            }
     }
    return false;
}

void Move::setPeopleToPickup(const string& pickupList, const int currentFloor, const Floor& pickupFloor) {
    //TODO: Implement setPeopleToPickup
    int index = 0;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;

    for (int i = 0; i < pickupList.size(); i++) {
        peopleToPickup[i] = (pickupList[i] - '0');
        numPeopleToPickup++;
    }
    int maxDistance = 0;

    for (int i = 0; i < numPeopleToPickup; i++) {
         int anger = pickupFloor.getPersonByIndex(peopleToPickup[i]).getAngerLevel();
         totalSatisfaction += (MAX_ANGER - anger);
         int distance = abs(pickupFloor.getPersonByIndex(peopleToPickup[i]).getTargetFloor() - currentFloor);
         if (maxDistance < distance) {
            maxDistance = distance;
            index = i;
            }
        }
     targetFloor = pickupFloor.getPersonByIndex(peopleToPickup[index]).getTargetFloor();
     return;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
	isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
	return isPass;
}

bool Move::isSaveMove() const {
	return isSave;
}

bool Move::isQuitMove() const {
	return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
