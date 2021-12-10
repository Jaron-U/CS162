/******************************************************
** Program: rope.cpp
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: child class of Event. Inherit the properties of the parent class.
** Input: rope.h
******************************************************/
#include "rope.h"
#include <iostream>

using namespace std;

/******************************************************************
** Function: Rope()
** Description: default the Rope object, use parent function set data
** Parameters: none
******************************************************************/
Rope::Rope(){
    set_event_icon("R");
}

/******************************************************************
** Function: ~Rope()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Rope::~Rope(){}

/******************************************************************
** Function: percept()
** Description: get the percept of rope, rope do not need any percept
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Rope::percept(){}

/******************************************************************
** Function: encounter()
** Description: get the encounter of rope. 
                need to check if the player got gold. if yes set n to 3
** Parameters: Player& p, int& n, int edge number
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Rope::encounter(Player& p, int& n, int edge_n){
    if(p.get_has_gold() == true){
        cout<<"Congratulation! you got the gold and escaped successfullly!"<<endl;
        n=3;
    }
}