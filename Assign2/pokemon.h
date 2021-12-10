/******************************************************
** Program: Pokemon.h
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: a header file for Pokemon class
******************************************************/
#ifndef POKEMON_H
#define POKEMON_H
#include <string>

using namespace std;
class Pokemon{
private:
    string name;
    string type;
    float health_point;
    int max_health_point;//store the max health point of the pokemon
    float attack;
    float defense;

public:
    Pokemon();
    Pokemon(string, string, float, int, int);
    ~Pokemon();

    //getter
    string get_name();
    string get_type();
    float get_health_point();
    int get_max_health_point();
    int get_attack();
    int get_defense();

    //setter
    void set_name(string);
    void set_type(string);
    void set_health_point(float);
    void set_max_health_point(int);
    void set_attack(int);
    void set_defense(int);

    void print_info();

    virtual float get_Type_Effectiveness(string type_attacked) = 0;
};

#endif