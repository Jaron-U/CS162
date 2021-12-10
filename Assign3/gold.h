/******************************************************
** Program: gold.h
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: a header file for gold class
** Input: "event.h"
******************************************************/
#ifndef GOLD_H
#define GOLD_H
#include "event.h"

class Gold : public Event{
public:
    Gold();
    void percept() override;
    void encounter(Player&, int&, int) override;
    ~Gold();
};

#endif
