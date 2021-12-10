/******************************************************
** Program: pit.cpp
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: child class of Event. Inherit the properties of the parent class.
** Input: pit.h
******************************************************/
#include "pit.h"

using namespace std;

/******************************************************************
** Function: Pit()
** Description: default the Pit object, use parent function set data
** Parameters: none
******************************************************************/
Pit::Pit(){
    set_event_icon("P");
}

/******************************************************************
** Function: percept()
** Description: get the percept of pit
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Pit::percept(){
    cout<<"You feel a breeze."<<endl;
}

/******************************************************************
** Function: encounter()
** Description: get the encounter of gold. set number to 2. use for gameover judge
** Parameters: Player& p, int& n, int edge number
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Pit::encounter(Player& p, int& n, int edge_n){
    cout<<"You are falling in a pit. You are dead."<<endl;
    n = 2;
}

/******************************************************************
** Function: ~Pit()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Pit::~Pit(){}