/******************************************************
** Program: event.h
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: a header file for event class
** Input: "player.h"
******************************************************/
#ifndef EVENT_H
#define EVENT_H
#include <string>
#include "player.h"
#include <iostream>
using namespace std;

class Event{
private:
    string event_icon;

public:
    Event();
    Event(const Event&);
    ~Event();

    //getter
    string get_event_icon();

    //setter
    void set_event_icon(string);

    virtual void percept(){};
    virtual void encounter(Player&, int&, int){};
};

#endif