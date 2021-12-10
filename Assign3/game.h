/******************************************************
** Program: game.h
** Author: Jianglong Yu
** Date: 11/19/2021
** Description: a header file for game class
** Input: "wumpus.h" "event.h" "bats.h""gold.h""rope.h""room.h"
******************************************************/
#ifndef GAME_H
#define GAME_H
#include "wumpus.h"
#include "event.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"
#include "player.h"
#include "rope.h"
#include "room.h"
#include <vector>
#include <iostream>

using namespace std;

class Game{
private:
    Player p;
    int cave_edge;
    vector<vector<Room> >Cave;
    bool model;
    bool wumpus_dead;

public:
    Game();
    Game(int, char**);
    ~Game();

    void check_main_parameters(int, char**);

    void generate_cave();
    void get_empty_room_coord(int*);
    void print_cave();
    void print_event_icon(int, int);

    bool check_user_input(char, bool);
    void get_player_move(char*);
    void player_move(); 

    void set_player_coord(char);
    int return_valid_coord(int, int);
    void shoot_arrow(char);
    void shoot_or_not(int, int, char);
    void wumpus_move(int, int);

    void print_percept();
    void check_print_percept(int, int);
    void encounter_event(int&);

    void main_game();


};
#endif