/******************************************************
** Program: rope.cpp
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: main file. Just start the game. and print some prompt.
** Input: game.h
******************************************************/
#include "game.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    Game g(argc, argv);
    cout<<"\n<----Welcome to Hunt the Wumpus!---->\n"<<endl;
    cout<<"Use w,a,s,d without click enter to move.";
    cout<<"Find the gold and escape the cave."<<endl;
    g.main_game();

    return 0;
}