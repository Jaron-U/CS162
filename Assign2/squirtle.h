/******************************************************
** Program: Squirtle.h
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: a header file for Squirtle class
** Input: "pokemon.h"
******************************************************/
#ifndef SQUIRTLE_H
#define SQUIRTLE_H
#include "pokemon.h"

using namespace std;

class Squirtle : public Pokemon{
public:
    Squirtle();
    ~Squirtle();

    float get_Type_Effectiveness(string) override;
};

#endif