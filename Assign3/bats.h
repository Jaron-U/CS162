/******************************************************
** Program: bats.h
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: a header file for bats class
** Input: "event.h"
******************************************************/
#ifndef BATS_H
#define BATS_H
#include "event.h"

class Bats : public Event{
public:
    Bats();
    void percept() override;
    void encounter(Player&, int&, int) override;
    ~Bats();
};

#endif