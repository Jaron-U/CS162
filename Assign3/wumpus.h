/******************************************************
** Program: wumpus.h
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: a header file for wumpus class
** Input: "event.h"
******************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H
#include "event.h"

class Wumpus : public Event{
public:
    Wumpus();
    void percept() override;
    void encounter(Player&, int&, int) override;
    ~Wumpus();
};


#endif