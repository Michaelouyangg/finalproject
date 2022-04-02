/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Floor.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */


#include "Floor.h"

using namespace std;

int Floor::tick(int currentTime) {
    int i;
    int j = 0;
    int angernum = 0;
    int arr[angernum];
    for(i = 0; i < MAX_PEOPLE_PER_FLOOR; i++){
        if(people[i].tick(currentTime)){
            angernum++;
            arr[j] = i;
            j++;
        }
    }
    removePeople(arr, angernum);
    return angernum;
}

void Floor::addPerson(Person newPerson, int request) {
    if(numPeople == 0){
        people[0] = newPerson;
        numPeople++;
    }
    else if(numPeople == 1){
        people[1] = newPerson;
        numPeople++;
    }
    else if(numPeople == 2){
        people[2] = newPerson;
        numPeople++;
    }
    else if(numPeople == 3){
        people[3] = newPerson;
        numPeople++;
    }
    else if(numPeople == 4){
        people[4] = newPerson;
        numPeople++;
    }
    else if(numPeople == 5){
        people[5] = newPerson;
        numPeople++;
    }
    else if(numPeople == 6){
        people[6] = newPerson;
        numPeople++;
    }
    else if(numPeople == 7){
        people[7] = newPerson;
        numPeople++;
    }
    else if(numPeople == 8){
        people[8] = newPerson;
        numPeople++;
    }
    else if (numPeople == 9){
        people[9] = newPerson;
        numPeople++;
    }
    if(request > 0){
        hasUpRequest = true;
        hasDownRequest = false;
    }
    else if(request < 0){
        hasUpRequest = false;
        hasDownRequest = true;
    }
}

void Floor::removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR], int numPeopleToRemove) {
    int i;
    int j;
    int p = 0;
    int x;
    Person arr2[numPeople];
    sort(indicesToRemove, indicesToRemove + numPeopleToRemove);
    for(i = 0; i < numPeople; i++){
        for(j = 0; j < numPeopleToRemove; j++){
            if(i != indicesToRemove[j]){
                arr2[p] = people[i];
            }
            p++;
        }
    }
    for(x = 0; x < numPeople; x++){
        people[x] = arr2[x];
    }
}

void Floor::resetRequests() {
    //TODO: Implement resetRequests
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor() {
    hasDownRequest = false;
    hasUpRequest = false;
    numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream& outs) const {
	string up = "U";
	outs << (hasUpRequest ? up : " ") << " ";
	for (int i = 0; i < numPeople; ++i){
		outs << people[i].getAngerLevel();
		outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
	}
	outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream& outs) const {
	string down = "D";
	outs << (hasDownRequest ? down : " ") << " ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "o   ";
	}
	outs << endl;
}

void Floor::printFloorPickupMenu(ostream& outs) const {
	cout << endl;
	outs << "Select People to Load by Index" << endl;
	outs << "All people must be going in same direction!";
	/*  O   O
	// -|- -|-
	//  |   |
	// / \ / \  */
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " O   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "-|-  ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " |   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "/ \\  ";
	}
	outs << endl << "INDEX:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << i << "   ";
	}
	outs << endl << "ANGER:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getAngerLevel() << "   ";
	}
	outs << endl << "TARGET FLOOR: ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getTargetFloor() << "   ";
	}
}

void Floor::setHasUpRequest(bool hasRequest) {
    hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const {
	return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest) {
    hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const {
	return hasDownRequest;
}

int Floor::getNumPeople() const {
    return numPeople;
}

Person Floor::getPersonByIndex(int index) const {
    return people[index];
}
