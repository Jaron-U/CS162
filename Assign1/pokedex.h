/******************************************************
** Program: pokedex.h
** Author: Jianglong Yu
** Date: 10/15/2021
** Description: this is a header file for pokedex
** Input: "pokemon.h"
******************************************************/
#ifndef POKEDEX_H
#define POKEDEX_H
#include "pokemon.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pokedex{
private:
    string trainer;
    int number;
    Pokemon* pokemons;

public:
    Pokedex();
    Pokedex(fstream&, string);
    ~Pokedex();
    // Pokedex(string, int, Pokemon*);

    string get_trainer();
    void set_trainer(string);

    int get_number();
    void set_number(int);

    Pokemon* get_pokemons();
    void set_pokemons(Pokemon*);

    Pokemon new_pokemon_info();
    void add_pokemons(Pokemon);

    void search_by_dex_number(int);

    void search_by_type(string);

    void search_by_name(string);

    void print();

    void number_check(std::istream &input = cin, int *val = NULL);

    void prompt();

    void write_infile(Pokemon*, int);

};



#endif