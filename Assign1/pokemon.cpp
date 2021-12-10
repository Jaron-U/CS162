/******************************************************
** Program: pokemon.cpp
** Author: Jianglong Yu
** Date: 10/15/2021
** Description: This code create the pokemon object. getter, setter and print
** Input: "pokemon.h"
******************************************************/
#include "pokemon.h"
#include <iostream>
using namespace std;

/******************************************************************
** Function: Pokemon()
** Description: default the Pokedex object 
** Parameters: none
******************************************************************/
Pokemon::Pokemon(){
    dex_num = -1;
    name = "";
    type = "";
    for(int i=0; i<4; i++){
        moves[i] = "";
    }
}

/******************************************************************
** Function: Pokemon()
** Description: initialize the pokemon.
** Parameters: new_dex, new_name, new_type, n_moves
** Pre-Conditions: the fstream is valid.
** Post-Conditions: the info in the file is good.
******************************************************************/
Pokemon::Pokemon(int new_dex, string new_name, string new_type, string* n_moves){
    dex_num = new_dex;
    name = new_name;
    type = new_type;
    for(int i=0; i<4; i++){
        moves[i] = n_moves[i];
    }
}

/******************************************************************
** Function: set_dex_num()
** Description: set the dex number
** Parameters: nex_dex
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_dex_num(int new_dex){
    dex_num = new_dex;
}

/******************************************************************
** Function: get_dex_num()
** Description: to get the private attribute dex number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
int Pokemon::get_dex_num(){
    return dex_num;
}

/******************************************************************
** Function: set_name()
** Description: set the name
** Parameters: new_name
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_name(string new_name){
    name = new_name;
}

/******************************************************************
** Function: get_name()
** Description: to get the private attribute name
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
string Pokemon::get_name(){
    return name;
}

/******************************************************************
** Function: set_type()
** Description: set the type
** Parameters: new_type
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_type(string new_type){
    type = new_type;
}

/******************************************************************
** Function: get_type()
** Description: to get the private attribute type
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
string Pokemon::get_type(){
    return type;
}

/******************************************************************
** Function: set_moves()
** Description: set the moves
** Parameters: new moves 
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokemon::set_moves(string* n_moves){
    for(int i=0; i<4; i++){
        moves[i] = n_moves[i];
    }
}

/******************************************************************
** Function: get_moves()
** Description: to get the private attribute moves
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
string* Pokemon::get_moves(){
    return moves;
}

/******************************************************************
** Function: print()
** Description: print a pokemon information
** Parameters: none
** Pre-Conditions: pokemons have data
** Post-Conditions: none
******************************************************************/
void Pokemon::print(){
    cout<< get_dex_num();
    cout<<" "<< get_name();
    cout<<" "<<get_type()<<endl;
    string* moves = get_moves();
    for(int i=0; i<4; i++){
        cout<<moves[i] <<" ";
    }
    cout<<""<<endl;
}