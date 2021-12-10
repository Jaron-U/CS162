/******************************************************
** Program: prog.cpp
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: main function file. Create Arena object.
** Input: Arena.h
** Output: Start game
******************************************************/
#include "pokemon.h"
#include "bulbasaur.h"
#include "charmander.h"
#include "squirtle.h"
#include "trainer.h"
#include "arena.h"
#include <iostream>

using namespace std;
int main(){
    Arena a;
    a.main_game();

    return 0;
}
