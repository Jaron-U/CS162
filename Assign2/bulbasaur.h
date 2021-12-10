/******************************************************
** Program: Bulbasaur.h
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: a header file for Bulbasaur class
** Input: "pokemon.h"
******************************************************/
#ifndef BULBASAUR_H
#define BULBASAUR_H
#include "pokemon.h"
#include <string>

using namespace std;
class Bulbasaur : public Pokemon{
public:
    Bulbasaur();
    ~Bulbasaur();

    float get_Type_Effectiveness(string) override;
};

#endif