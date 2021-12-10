/******************************************************
** Program: player.h
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: a header file for player class
** Input: ""
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

using namespace std;

class Player{
private:
    string player_icon;
    int col;
    int row;
    bool has_gold;
    int arrow_num;
public:
    Player();
    Player(const Player&);
    ~Player();

    string get_player_icon();
    int get_col();
    int get_row();
    bool get_has_gold();
    int get_arrow_num();

    void set_player_icon(string);
    void set_col(int);
    void set_row(int);
    void set_has_gold(bool);
    void set_arrow_num(int);
};

#endif