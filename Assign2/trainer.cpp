/******************************************************
** Program: trainer.cpp
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: Implement functions trainer's attribuate, print the pokemons info
** Input: trainer.h
******************************************************/
#include "trainer.h"
#include <iostream>

using namespace std;

/******************************************************************
** Function: Trainer
** Description: default the Trainer object 
** Parameters: none
******************************************************************/
Trainer::Trainer(){
    player_name = "";
    for(int i=0; i<3; i++){
        this->team[i] = NULL;
    }
}

/******************************************************************
** Function: Trainer(string, Pokemon**)
** Description: Set the Trainer object with player name and pokemon list
** Parameters: player name and pokemon list
** Pre-Conditions: has a defult constructor
** Post-Conditions: the pokemon list is valid
******************************************************************/
Trainer::Trainer(string player, Pokemon* team[3]){
    this->player_name = player;
    for(int i=0; i<3; i++){
        this->team[i] = team[i];
    }
}

/******************************************************************
** Function: Trainer(string)
** Description: Set the Trainer object with player name
** Parameters: player name
** Pre-Conditions: has a defult constructor
** Post-Conditions: the name is valid
******************************************************************/
Trainer::Trainer(string player_name){
    this->player_name = player_name;
    for(int i=0; i<3; i++){
        this->team[i] = NULL;
    }
}

/******************************************************************
** Function: ~Trainer()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Trainer::~Trainer(){
    for(int i=0; i<3; i++){
        delete team[i];
    }
}

//getter
/******************************************************************
** Function: get_player_name()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
string Trainer::get_player_name(){
    return this->player_name;
}

/******************************************************************
** Function: get_team()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
Pokemon** Trainer::get_team(){
    return this->team;
}

//setter
/******************************************************************
** Function: set_player_name
** Description: set player name
** Parameters: string
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Trainer::set_player_name(string player_name){
    this->player_name = player_name;
}

/******************************************************************
** Function: set_team
** Description: set pokemon team
** Parameters: Pokemon*
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Trainer::set_team(Pokemon* team[3]){
    for(int i=0; i<3; i++){
        this->team[i] = team[i];
    }
}

/******************************************************************
** Function: print_pokemons
** Description: print the pokemon's info of current trainer
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
void Trainer::print_pokemons(){
    cout<<"Trainer: "<<this->player_name<<endl;
    cout<<"Name        "<<"Type  "<<"HP     "<<"Attack  "<<"Defense  "<<endl;
    for(int i=0; i<3; i++){
        cout<<i+1<<"."<<team[i]->get_name()<<" "<<team[i]->get_type()<<" "<<team[i]->get_health_point();
        cout<<"     "<<team[i]->get_attack()<<"      "<<team[i]->get_defense()<<endl;
    }
}