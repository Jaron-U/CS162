/******************************************************
** Program: room.cpp
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: a room to store the event use for creat cave vector
** Input: room.h
******************************************************/
#include "room.h"
#include <iostream>

using namespace std;

/******************************************************************
** Function: Room
** Description: default constructor of Room object 
** Parameters: none
******************************************************************/
Room::Room(){
    event = NULL;
}

/******************************************************************
** Function: Room()
** Description: a copy constructor function
** Parameters: none
** Pre-Conditions: there is a copy constructor
** Post-Conditions: none
******************************************************************/
Room::Room(const Room& room){
    this->event = room.event;
}

/******************************************************************
** Function: Room(Event* event)
** Description: Set the Room object with event
** Parameters: Event*
** Pre-Conditions: has a defult constructor
** Post-Conditions: the event is valid
******************************************************************/
Room::Room(Event* event){
    this->event = event;
}

/******************************************************************
** Function: ~Room()
** Description: a destructor function. delete the event
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Room::~Room(){
    delete event;
}

/******************************************************************
** Function: get_event()
** Description: to get the private attribute event.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
Event* Room::get_event(){
    return this->event;
}

/******************************************************************
** Function: set_event()
** Description: set the event
** Parameters: Event* 
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Room::set_event(Event* event){
    this->event = event;
}
