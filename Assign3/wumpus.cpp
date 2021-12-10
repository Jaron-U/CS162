/******************************************************
** Program: wumpus.cpp
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: child class of Event. Inherit the properties of the parent class.
** Input: wumpus.h
******************************************************/
#include "wumpus.h"
#include <iostream>

using namespace std;

/******************************************************************
** Function: Wumpus()
** Description: default the Wumpus object, use parent function set data
** Parameters: none
******************************************************************/
Wumpus::Wumpus(){
    set_event_icon("W");
}

/******************************************************************
** Function: percept()
** Description: get the percept of wumpus
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Wumpus::percept(){
    cout<<"You smell a terrible stench."<<endl;
}   

/******************************************************************
** Function: encounter()
** Description: get the encounter of wumpus. the player will dead and gameover. set n to 4.
** Parameters: Player& p, int& n, int edge number
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Wumpus::encounter(Player& p, int& n, int edge_n){
    cout<<"You are eaten by Wumpus."<<endl;
    n=4;
}

/******************************************************************
** Function: ~Wumpus()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Wumpus::~Wumpus(){}