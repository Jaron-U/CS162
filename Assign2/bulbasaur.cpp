/******************************************************
** Program: bulbasaur.cpp
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: child class of Pokemon. Inherit the properties of the parent class。
** Input: bulbasaur.h
******************************************************/
#include "bulbasaur.h"
#include <iostream>

using namespace std;

/******************************************************************
** Function: Bulbasaur
** Description: default the Bulbasaur object, use parent function set data
** Parameters: none
******************************************************************/
Bulbasaur::Bulbasaur(){
    set_name("Bulbasaur");
    set_type("Grass");
    set_health_point(45);
    set_max_health_point(45.0);
    set_attack(49);
    set_defense(49);
}

/******************************************************************
** Function: ~Bulbasaur()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Bulbasaur::~Bulbasaur(){}

/******************************************************************
** Function: get_Type_Effectiveness(string)
** Description: get the type effectivness
** Parameters: the type of opponent Pokemon
** Pre-Conditions: none
** Post-Conditions: the type is valid
******************************************************************/
float Bulbasaur::get_Type_Effectiveness(string type_attacked){
    if(type_attacked == "Grass"){
        return 1;
    }
    else if(type_attacked == "Fire"){
        return 0.5;
    }
    else{
        return 2;
    }
}