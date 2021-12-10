/******************************************************
** Program: pokemon.cpp
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: private attribuate getter and setter. This is a pure virtual function.
******************************************************/
#include "pokemon.h"
#include <iostream>

using namespace std;

/******************************************************************
** Function: Pokemon
** Description: default the Pokemon object 
** Parameters: none
******************************************************************/
Pokemon::Pokemon(){
    name = "";
    type = "";
    health_point = 0;
    max_health_point = 0;
    attack = 0;
    defense = 0;
}

/******************************************************************
** Function: Pokemon(string, string, float, int, int)
** Description: Set the Pokemon object.
** Parameters: string name, string type, float health_point, int attack, int defense
** Pre-Conditions: has a defult constructor
** Post-Conditions: these parameters are valid
******************************************************************/
Pokemon::Pokemon(string name, string type, float health_point, int attack, int defense){
    this->name = name;
    this->type = type;
    this->health_point = health_point;
    this->max_health_point = health_point;
    this->attack = attack;
    this->defense = defense;
}

/******************************************************************
** Function: ~Pokemon()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Pokemon::~Pokemon(){
}

//getter
/******************************************************************
** Function: get_name()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
string Pokemon::get_name(){
    return this->name;
}

/******************************************************************
** Function: get_type()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
string Pokemon::get_type(){
    return this->type;
}

/******************************************************************
** Function: get_health_point()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
float Pokemon::get_health_point(){
    return this->health_point;
}

/******************************************************************
** Function: get_max_health_point()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
int Pokemon::get_max_health_point(){
    return this->max_health_point;
}

/******************************************************************
** Function: get_attack()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
int Pokemon::get_attack(){
    return this->attack;
}

/******************************************************************
** Function: get_defense()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
int Pokemon::get_defense(){
    return this->defense;
}

//setter
/******************************************************************
** Function: set_name
** Description: set pokemon name
** Parameters: string
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_name(string name){
    this->name = name;
}

/******************************************************************
** Function: set_type
** Description: set pokemon type
** Parameters: string
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_type(string type){
    this->type = type;
}

/******************************************************************
** Function: set_health_point
** Description: set pokemon hp
** Parameters: float
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_health_point(float health_point){
    this->health_point = health_point;
}

/******************************************************************
** Function: set_max_health_point
** Description: set pokemon max hp
** Parameters: int
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_max_health_point(int max_health_point){
    this->max_health_point = max_health_point;
}

/******************************************************************
** Function: set_attack
** Description: set pokemon attack
** Parameters: int
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_attack(int attack){
    this->attack = attack;
}

/******************************************************************
** Function: set_defense
** Description: set pokemon defense
** Parameters: int
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_defense(int defense){
    this->defense = defense;
}

/******************************************************************
** Function: print_info
** Description: print the pokemon info
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
void Pokemon::print_info(){
    cout<<this->get_name()<<" "<<this->get_type()<<" "<<this->get_health_point();
    cout<<"  "<<this->get_attack()<<"      "<<this->get_defense()<<endl;
}