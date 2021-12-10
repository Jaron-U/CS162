/******************************************************
** Program: rope.cpp
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: this is a virtual function. A parent object.
** Input: rope.h
******************************************************/
#include "event.h"
#include <iostream>

using namespace std;

/******************************************************************
** Function: Event()
** Description: default the Event object.
** Parameters: none
******************************************************************/
Event::Event(){
    event_icon = "";
}

/******************************************************************
** Function: Event()
** Description: a copy constructor function
** Parameters: const Event& event
** Pre-Conditions: there is a copy constructor
** Post-Conditions: none
******************************************************************/
Event::Event(const Event& event){
    this->event_icon = event.event_icon;
}

/******************************************************************
** Function: ~Event()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Event::~Event(){}

//getter
/******************************************************************
** Function: get_event_icon()
** Description: to get the private attribute event_icon.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
string Event::get_event_icon(){
    return this->event_icon;
}

//setter
/******************************************************************
** Function: set_event_icon()
** Description: to set the private attribute event_icon.
** Parameters: string
** Pre-Conditions: valid input
** Post-Conditions: it is initialized.
******************************************************************/
void Event::set_event_icon(string event_icon){
    this->event_icon = event_icon;
}