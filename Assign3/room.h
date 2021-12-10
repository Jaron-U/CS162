/******************************************************
** Program: room.h
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: a header file for room class
** Input: "event.h"
******************************************************/
#ifndef ROOM_H
#define ROOM_H
#include "event.h"
using namespace std;

class Room{
private:
    Event *event;

public:
    Room();
    Room(Event*);
    Room(const Room&);
    ~Room();

    Event* get_event();

    void set_event(Event*);

};
#endif