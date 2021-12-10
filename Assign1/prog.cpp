/******************************************************
** Program: prog.cpp
** Author: Jianglong Yu
** Date: 10/15/2021
** Description: This main file. 
** Input: "pokemon.h", "pokedex.h"
******************************************************/
#include "pokemon.h"
#include "pokedex.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    fstream inf;
    //open the file
    inf.open(argv[1]);
    // if cannot open
    if(!inf.is_open()){
        cout << "Error, unable to open file!" << endl;
        return 1;
    }
    string trainer = "";
    //ask the users name
    cout<<"Welcome to Pokemon Encyclopedia! What is your name: ";
    cin >> trainer;
    //create the pokedex
    Pokedex p(inf, trainer);
    p.prompt();
    inf.close();

    return 0;
}
