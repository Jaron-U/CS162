/******************************************************
** Program: pokedex.cpp
** Author: Jianglong Yu
** Date: 10/15/2021
** Description: This code create the pokedex object. And implement functions Searching and Printing
** Input: "pokedex.h", "pokemon.h"
** Output: files and strings
******************************************************/
#include "pokedex.h"
#include "pokemon.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <iomanip>  //use for checking users' input
#include <limits>
using namespace std;

/******************************************************************
** Function: Pokedex
** Description: default the Pokedex object 
** Parameters: none
******************************************************************/
Pokedex::Pokedex(){
    trainer = "";
    number = 0;
    pokemons = new Pokemon[number];
}

/******************************************************************
** Function: Pokedex
** Description: read the info from the file into the pokedex
** Parameters: fstream, string
** Pre-Conditions: the fstream is valid.
** Post-Conditions: the info in the file is good.
******************************************************************/
Pokedex::Pokedex(fstream& fin, string n_trainer){
    int dex_num;
    string pokemon_name;
    string type;
    string moves[4];
    //set trainer name
    trainer = n_trainer;
    //read the pokemon number from the file
    fin >> number;
    pokemons = new Pokemon[number];
    // read pokemon information from the file
    for(int i=0; i<number; i++){
        fin >> dex_num;
        pokemons[i].set_dex_num(dex_num);
        fin >> pokemon_name;
        pokemons[i].set_name(pokemon_name);
        fin >> type;
        pokemons[i].set_type(type);
        for(int j=0; j<4; j++){
            fin >> moves[j];
        }
        pokemons[i].set_moves(moves);
    }
}

/******************************************************************
** Function: get_trainer()
** Description: to get the private attribute trainer
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
string Pokedex::get_trainer(){
    return trainer;
}

/******************************************************************
** Function: set_trainer
** Description: set the trainer
** Parameters: n_trainer
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokedex::set_trainer(string n_trainer){
    trainer = n_trainer;
}

/******************************************************************
** Function: get_number()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
int Pokedex::get_number(){
    return number;
}

/******************************************************************
** Function: set_number
** Description: set the n_num
** Parameters: n_num
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Pokedex::set_number(int n_num){
    number = n_num;
}

/******************************************************************
** Function: get_pokemons()
** Description: to get the private attribute pokemons
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
Pokemon* Pokedex::get_pokemons(){
    return pokemons;
}

/******************************************************************
** Function: set_pokemons
** Description: set the pokemons
** Parameters: n_pokemons
** Pre-Conditions: there is a valid n_pokemons input
** Post-Conditions: none
******************************************************************/
void Pokedex::set_pokemons(Pokemon* n_pokemons){
    delete[] pokemons;
    pokemons = n_pokemons;
}

/******************************************************************
** Function: print()
** Description: print the pokemons information
** Parameters: none
** Pre-Conditions: pokemons have data
** Post-Conditions: none
******************************************************************/
void Pokedex::print(){
    // cout<<"Name: " << get_name() <<endl;
    cout<<get_number()<<endl;
    Pokemon* pokemons = get_pokemons();
    for(int i=0; i<number; i++){
        pokemons[i].print();
        cout<<""<<endl;
    }
}

/******************************************************************
** Function: new_pokemon_info()
** Description: ask user input the pokemon's info
** Parameters: none
** Pre-Conditions: user have valid input
** Post-Conditions: none
******************************************************************/
Pokemon Pokedex::new_pokemon_info(){
    int dex_num_new = 0;
    string name_new = "";
    string type_new = "";
    string moves_new[4];

    //ask user to input the pokemon's info 
    cout<<"Please input the dex of this new pokemon(numbers only): ";
    number_check(cin, &dex_num_new); //just check the user's input

    cout<<"Please input the name of this new pokemon: ";
    cin >> name_new;

    cout<<"Please input the type of this new pokemon: ";
    cin >> type_new;

    cout<<"Please input the moves of this new pokemon: "<<endl;
    for(int i=0; i<4; i++){
        cout << "moves " << i+1 <<": ";
        cin >> moves_new[i];
    }
    // set this pokemon
    Pokemon pokemon(dex_num_new, name_new, type_new, moves_new);
    return pokemon;
}

/******************************************************************
** Function: add_pokemons()
** Description: add a new pokemon to the list using dynamic array
** Parameters: n_pokemon
** Pre-Conditions: pokemons have data
** Post-Conditions: none
******************************************************************/
void Pokedex::add_pokemons(Pokemon n_pokemon){
    int n = get_number();
    //increase the space.
    n++;
    set_number(n);
    Pokemon* temp = new Pokemon[n];
    Pokemon* pokemons = get_pokemons();
    for(int i=0; i<n-1; i++){
        temp[i] = pokemons[i];
    }
    temp[n-1] = n_pokemon;
    set_pokemons(temp);
    cout <<"new Pokemon has been added."<<endl;
}

/******************************************************************
** Function: ~Pokedex()
** Description: a destructor function, relase the memory
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Pokedex::~Pokedex(){
    delete[] pokemons;
}

/******************************************************************
** Function: search_by_dex_number
** Description: search the pokemon by dex number, and ask user output way
** Parameters: a dex number
** Pre-Conditions: the dex number is valid
** Post-Conditions: none
******************************************************************/
void Pokedex::search_by_dex_number(int n){
    int flag = 0;
    int poke_n = get_number();
    Pokemon temp[1024];
    int j = 0;
    Pokemon* pokemons = get_pokemons();
    for(int i=0; i<poke_n; i++){
        if(pokemons[i].get_dex_num() == n){
            temp[j] = pokemons[i];
            flag = 1;
            j++;
        }
    }
    //if cannot find.
    if(flag == 0){
        cout << "This pokemon which dex number is " << n << " does not exist" << endl;
    }
    else{
        int choice = 0;
        //ask user output way
        cout << "Do you want print directly(press 1) or put into a file(press2): ";
        number_check(cin, &choice);
        //print directly
        if(choice == 1){
            cout<<j<<endl;
            for(int k=0; k<j;k++){
                temp[k].print();
            }
        }
        //print into a file
        else if(choice == 2){
            write_infile(temp, j);
        }
    }
}

/******************************************************************
** Function: search_by_type
** Description: search the pokemon by type, and ask user output way
** Parameters: a type string
** Pre-Conditions: the type is valid
** Post-Conditions: user input valid
******************************************************************/
void Pokedex::search_by_type(string type){
    int flag = 0;
    int j = 0;
    Pokemon temp[1024];
    int poke_n = get_number();
    // set a list to recieve all pokemons
    Pokemon* pokemons = get_pokemons();
    for(int i=0; i<poke_n; i++){
        if(pokemons[i].get_type() == type){
            temp[j] = pokemons[i];
            flag = 1; // if there are at least one pokemons meet the requirement
            j++; // to mark how many pokemons is this type
        }
    }
    //if the type user input do not exsit.
    if(flag == 0){
        cout << "This pokemon which type is " << type << " does not exist" << endl;
    }
    else{
        int choice = 0;
        cout << "Do you want print directly(press 1) or put into a file(press2): ";
        //check input
        number_check(cin, &choice);
        while(!(choice == 1 || choice == 2)){
            cout << "Invalid number, please input again(1-2): ";
            number_check(cin, &choice);
        }
        //if user want to print directly
        if(choice == 1){
            cout<<j<<endl;
            for(int k=0; k<j;k++){
                temp[k].print();
            }
        }
        //if user want to write into a file
        else if(choice == 2){
            write_infile(temp, j);
        }
    }
}

/******************************************************************
** Function: search_by_name
** Description: search the pokemon by name, and ask user output way
** Parameters: a name string
** Pre-Conditions: the name is valid
** Post-Conditions: user input valid
******************************************************************/
void Pokedex::search_by_name(string n_name){
    int flag = 0;
    int j = 0;
    Pokemon temp[1024];
    int poke_n = get_number();
    Pokemon* pokemons = get_pokemons();
    for(int i=0; i<poke_n; i++){
        if(pokemons[i].get_name() == n_name){
            temp[j] = pokemons[i];
            flag = 1;
            j++;
        }
    }
    if(flag == 0){
        cout << "This pokemon which name is " << n_name << " does not exist" << endl;
    }
    else{
        int choice = 0;
        cout << "Do you want print directly(press 1) or put into a file(press2): ";
        //check user's input
        number_check(cin, &choice);
        if(choice == 1){
            cout<<j<<endl;
            for(int k=0; k<j;k++){
                temp[k].print();
            }
        }
        else if(choice == 2){
            write_infile(temp, j);
        }
    }
}

/******************************************************************
** Function: number_check
** Description: check whether user input a number or not.
** Parameters: istream, and the address to store the input
** Pre-Conditions: there is a input
** Post-Conditions: none
******************************************************************/
void Pokedex::number_check(std::istream &input, int *val){
    input >> *val;
    if(input.fail()){
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Input is invalid, please input again: ";
        number_check(input, val);
    }
}

/******************************************************************
** Function: prompt()
** Description: say hello to user, and ask which methods they want use.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: user input is valid 
******************************************************************/
void Pokedex::prompt(){
    int choice = 0;
    cout<<"Hello "<<get_trainer()<<endl;
    do{
        cout<< ""<<endl;
        cout<< "1.Search Pokemon by dex number."<<endl;
        cout<< "2.Search Pokemon by name." <<endl;
        cout<< "3.Search Pokemon by type."<<endl;
        cout<< "4.Add a new Pokemon." <<endl;
        cout<< "0.exit" << endl;
        cout<< "please input a choice number: ";
        number_check(cin, &choice);
        while(!(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 0)){
            cout << "Invalid number, please input again(0-4): ";
            number_check(cin, &choice);
        }
        //if user want to search by dex number
        if(choice == 1){
            int dex_n = -1;
            cout<<"please input a dex number: ";
            cin >> dex_n;
            search_by_dex_number(dex_n);
        }
        //if user want to search by name
        else if(choice == 2){
            string name_i = "";
            cout<<"please input a pokemon's name: ";
            cin >> name_i;
            search_by_name(name_i);
        }
        //if user want to search by type
        else if(choice == 3){
            string type_n = "";
            cout<<"please input a type: ";
            cin >> type_n;
            search_by_type(type_n);
        }
        //if user want add a new pokemon
        else if(choice == 4){
            add_pokemons(new_pokemon_info());
        }

    }while(choice != 0);
}

/******************************************************************
** Function: write_infile
** Description: write the pokemons' info into a file
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: user input is valid 
******************************************************************/
void Pokedex::write_infile(Pokemon* pokemons, int poke_n){
    string file_n = "";
    cout << "please input a file name: ";
    cin >> file_n;
    // add a postfix
    file_n += ".txt";
    //create a file and open
    fstream ouf(file_n, ios::out | ios::app);
    //wirte the number into the file
    ouf << poke_n << endl;
    for(int i=0; i<poke_n; i++){
        ouf << pokemons[i].get_dex_num();
        ouf <<" "<<pokemons[i].get_name();
        ouf <<" "<<pokemons[i].get_type() <<endl;
        string* moves = pokemons[i].get_moves();
        for(int i=0; i<4; i++){
            ouf<<moves[i] <<" ";
        }
        ouf<<""<<endl;
    }
    ouf.close();
}
