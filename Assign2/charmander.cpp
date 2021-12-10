/******************************************************
** Program: charmander.cpp
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: child class of Pokemon. Inherit the properties of the parent class。
** Input: charmander.h
******************************************************/
#include "charmander.h"
#include <iostream>

using namespace std;


/******************************************************************
** Function: Charmander
** Description: default the Charmander object, use parent function set data
** Parameters: none
******************************************************************/
Charmander::Charmander(){
    set_name("Charmander");
    set_type("Fire");
    set_health_point(39.0);
    set_max_health_point(39);
    set_attack(52);
    set_defense(43);
}

/******************************************************************
** Function: ~Charmander()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Charmander::~Charmander(){}

/******************************************************************
** Function: get_Type_Effectiveness(string)
** Description: get the type effectivness
** Parameters: the type of opponent Pokemon
** Pre-Conditions: none
** Post-Conditions: the type is valid
******************************************************************/
float Charmander::get_Type_Effectiveness(string type_attacked){
    if(type_attacked == "Grass"){
        return 2;
    }
    else if(type_attacked == "Fire"){
        return 1;
    }
    else{
        return 0.5;
    }
}

