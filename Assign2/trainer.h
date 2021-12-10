/******************************************************
** Program: Trainer.h
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: a header file for Trainer class
** Input: "pokemon.h", "bulbasaur.h","charmander.h","squirtle.h"
******************************************************/
#ifndef TRAINER_H
#define TRAINER_H
#include "pokemon.h"
#include "bulbasaur.h"
#include "squirtle.h"
#include <string>

using namespace std;

class Trainer{
private:
    string player_name;
    Pokemon* team[3];

public:
    Trainer();
    Trainer(string, Pokemon**);
    Trainer(string);
    ~Trainer();

    //getter
    string get_player_name();
    Pokemon** get_team();

    //setter
    void set_player_name(string);
    void set_team(Pokemon**);

    //print pokemons
    void print_pokemons();

};

#endif