/******************************************************
** Program: rope.h
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: a header file for Squirtle class
** Input: "event.h"
******************************************************/
#ifndef ROPE_H
#define ROPE_H
#include "event.h"
#include <string>

using namespace std;

class Rope : public Event{
public:
    Rope();
    void percept() override;
    void encounter(Player&, int&, int) override;
    ~Rope();
};

#endif