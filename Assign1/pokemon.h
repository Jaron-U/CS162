/******************************************************
** Program: pokemon.h
** Author: Jianglong Yu
** Date: 10/15/2021
** Description: this is a header file for pokemon
******************************************************/
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

using namespace std;

class Pokemon{
private:
    int dex_num;
    string name;
    string type;
    string moves[4];

public:
    Pokemon();
    Pokemon(int, string, string, string*);

    void set_dex_num(int);
    int get_dex_num();

    void set_name(string);
    string get_name();

    void set_type(string);
    string get_type();

    void set_moves(string*);
    string* get_moves();

    void print();
};

#endif