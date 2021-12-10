/******************************************************
** Program: gold.cpp
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: child class of Event. Inherit the properties of the parent class.
** Input: gold.h
******************************************************/
#include "gold.h"

using namespace std;

/******************************************************************
** Function: Gold()
** Description: default the Gold object, use parent function set data
** Parameters: none
******************************************************************/
Gold::Gold(){
    set_event_icon("G");
}

/******************************************************************
** Function: percept()
** Description: get the percept of gold
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Gold::percept(){
    cout<<"You see a glimmer nearby."<<endl;
}

/******************************************************************
** Function: encounter()
** Description: get the encounter of gold. set player have gold
** Parameters: Player& p, int& n, int edge number
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Gold::encounter(Player& p, int& n, int edge_n){
    p.set_has_gold(true);
    cout<<"You get the gold!"<<endl;
}

/******************************************************************
** Function: ~Gold()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Gold::~Gold(){}