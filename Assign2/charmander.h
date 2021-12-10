/******************************************************
** Program: Charmander.h
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: a header file for Charmander class
** Input: "pokemon.h"
******************************************************/
#ifndef CHARMANDER_H
#define CHARMANDER_H
#include "pokemon.h"

using namespace std;

class Charmander : public Pokemon{
public:
    Charmander();
    ~Charmander();

    float get_Type_Effectiveness(string) override;
};

#endif