/******************************************************
** Program: arnea.h
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: a header file for arena class
** Input: "pokemon.h", "bulbasaur.h","charmander.h","squirtle.h","trainer.h"
******************************************************/
#ifndef ARENA_H
#define ARENA_H
#include "pokemon.h"
#include "bulbasaur.h"
#include "charmander.h"
#include "squirtle.h"
#include "trainer.h"
#include <iostream>

using namespace std;

class Arena{
private:
    Trainer t[2];

public:
    Arena();
    ~Arena();
    Arena(Trainer*);

    //getter
    Trainer* get_trainers();
    //setter
    void set_trainers(Trainer*);

    void number_check(std::istream &input = cin, int *val = NULL);

    string print_pokemons_list();

    void ask_user_choose_pokes(Trainer&);
    void computer_choose_pokes(Trainer&);
    void add_pokemons(int, Pokemon**, int);

    void print_actions();
    void ask_player_choose_action(Trainer&, Trainer&, int&);
    int computer_swap_valid_poke(Trainer&, int);
    void computer_choose_action(Trainer&, Trainer&, int&);

    void fight(Trainer&, Trainer&);
    void heal(Trainer&, int, int);
    void swap(Trainer&, int, int);

    void print_pokemons_info_t(Trainer&, Trainer&);

    int check_each_poke_hp(Trainer&);
    int check_first_poke_hp(Trainer&);
    int check_last_two_poke_hp(Trainer&);

    void round_game(Trainer&, Trainer&);
    void main_game();
};

#endif
