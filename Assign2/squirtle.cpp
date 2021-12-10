/******************************************************
** Program: squirtle.cpp
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: child class of Pokemon. Inherit the properties of the parent class。
** Input: squirtle.h
******************************************************/
#include "squirtle.h"
#include <iostream>

using namespace std;

/******************************************************************
** Function: Squirtle
** Description: default the Squirtle object, use parent function set data
** Parameters: none
******************************************************************/
Squirtle::Squirtle(){
    set_name("Squirtle");
    set_type("Water");
    set_health_point(44.0);
    set_max_health_point(44);
    set_attack(48);
    set_defense(65);
}

/******************************************************************
** Function: ~Squirtle()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Squirtle::~Squirtle(){}

/******************************************************************
** Function: get_Type_Effectiveness(string)
** Description: get the type effectivness
** Parameters: the type of opponent Pokemon
** Pre-Conditions: none
** Post-Conditions: the type is valid
******************************************************************/
float Squirtle::get_Type_Effectiveness(string type_attacked){
    if(type_attacked == "Grass"){
        return 0.5;
    }
    else if(type_attacked == "Fire"){
        return 2;
    }
    else{
        return 1;
    }
}


