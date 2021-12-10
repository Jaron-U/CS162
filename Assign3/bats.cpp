/******************************************************
** Program: bats.cpp
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: child class of Event. Inherit the properties of the parent class.
** Input: bats.h
******************************************************/
#include "bats.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

/******************************************************************
** Function: Bats
** Description: default the Bats object, use parent function set data
** Parameters: none
******************************************************************/
Bats::Bats(){
    set_event_icon("B");
}

/******************************************************************
** Function: percept()
** Description: get the percept
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Bats::percept(){
    cout<<"You hear wings flapping."<<endl;
}

/******************************************************************
** Function: encounter()
** Description: get the encounter of bats. generate a random coord. 
**              and set the player's coord.
** Parameters: Player& p, int& n, int edge number
** Pre-Conditions: none
** Post-Conditions: call it
******************************************************************/
void Bats::encounter(Player& p, int& n, int edge_n){
    srand(time(NULL));
    int i = rand() % edge_n;
    int j = rand() % edge_n;
    p.set_row(i);
    p.set_col(j);
    cout << "You have been taken to a random room by bats."<<endl;
    n = 1;
}

/******************************************************************
** Function: ~Bats()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Bats::~Bats(){}