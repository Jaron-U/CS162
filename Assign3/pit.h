/******************************************************
** Program: pit.h
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: a header file for pit class
** Input: "event.h"
******************************************************/
#ifndef PIT_H
#define PIT_H
#include "event.h"

class Pit : public Event{
public:
    Pit();
    void percept() override;
    void encounter(Player&, int&, int) override;
    ~Pit();
};

#endif