/******************************************************
** Program: rope.cpp
** Author: Jianglong Yu
** Date: 10/19/2021
** Description: child class of Event. Inherit the properties of the parent class.
** Input: rope.h
******************************************************/
#include "game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring> 
#include <string>
#include <stdio.h>
#include <stdexcept>

using namespace std;

/******************************************************************
** Function: Game()
** Description: default the Game object.
** Parameters: none
******************************************************************/
Game::Game(){
    this->cave_edge = 0;
    vector<vector<Room> >Cave(cave_edge, vector<Room>(cave_edge));
    this->model = false;
    this->wumpus_dead = false;
}

/******************************************************************
** Function: Game()
** Description: set the arrtribute in game
** Parameters: int argc, char** argv
** Pre-Conditions: user input a valid parameters
** Post-Conditions: run program.
******************************************************************/
Game::Game(int argc, char** argv){
    // check if the parameter is valid
    check_main_parameters(argc, argv);
    this->cave_edge =atoi(argv[1]);
    // generate a cave 2D vector.
    for(int i=0; i<cave_edge; i++){
        Cave.push_back(vector<Room>());
        for (int j = 0; j < cave_edge; j++)
        {
            Room room;
            Cave[i].push_back(room);
        }
    }
    this->wumpus_dead = false;
}

/******************************************************************
** Function: check_main_parameters()
** Description: check the parameters user input is valid.
** Parameters: int argc, char** argv
** Pre-Conditions: user input a valid parameters
** Post-Conditions: run program.
******************************************************************/
void Game::check_main_parameters(int argc, char** argv){
    // if user did not input parameters or just input one.
    if(argc != 3){
        throw invalid_argument("Incorrect number of arguments");
    }
    //if the the room number in each edge user input is less than 4.
    else if(atoi(argv[1]) < 4){
        throw invalid_argument("Caves smaller than 4 rooms on a side aren't allowed!");
    }
    //if the second parameter user input is not true or false.
    else if(strcmp(argv[2], "true") != 0 && strcmp(argv[2], "false") != 0){
        throw invalid_argument("For the third parameter you should input true(debug model) or false(normal model)!");
    }else if(strcmp(argv[2], "true") == 0){
        this->model = true;
    }else if(strcmp(argv[2], "false") == 0){this->model = false;}
}

/******************************************************************
** Function: ~Game()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Game::~Game(){}

/******************************************************************
** Function: get_empty_room_coord()
** Description: get a empty room coordinates
** Parameters: int*
** Pre-Conditions: there is a cave
** Post-Conditions: there is empty room.
******************************************************************/
void Game::get_empty_room_coord(int arr[2]){
    srand(time(NULL));
    int i; int j;
    // generate a random room coordinates untill this room is empty.
    do{
        i = rand() % cave_edge;
        j = rand() % cave_edge;
    } while (Cave[i][j].get_event() != NULL);
    arr[0] = i; arr[1] = j; //put them into an array
}

/******************************************************************
** Function: generate_cave()
** Description: put events into this cave random room.
** Parameters: none
** Pre-Conditions: there is a cave
** Post-Conditions: there is empty room.
******************************************************************/
void Game::generate_cave(){
    int arr[2] = {};
    //get random room and set event
    get_empty_room_coord(arr);
    Cave[arr[0]][arr[1]].set_event(new Bats);
    get_empty_room_coord(arr);
    Cave[arr[0]][arr[1]].set_event(new Bats);
    get_empty_room_coord(arr);
    Cave[arr[0]][arr[1]].set_event(new Gold);
    get_empty_room_coord(arr);
    Cave[arr[0]][arr[1]].set_event(new Wumpus);
    get_empty_room_coord(arr);
    Cave[arr[0]][arr[1]].set_event(new Pit);
    get_empty_room_coord(arr);
    Cave[arr[0]][arr[1]].set_event(new Pit);
    get_empty_room_coord(arr);
    int i = arr[0]; int j = arr[1];
    Cave[i][j].set_event(new Rope); //player start from rope
    p.set_row(i); p.set_col(j);
}

/******************************************************************
** Function: print_cave()
** Description: print the cave.
** Parameters: none
** Pre-Conditions: there is a cave
** Post-Conditions: none
******************************************************************/
void Game::print_cave(){
    for(int i=0; i<cave_edge; i++){
        for(int i1 =0; i1<cave_edge; i1++){
            cout<<"+---";
        }cout<<"+"<<endl;
        for(int j=0; j<cave_edge; j++){
            cout<<"| ";
            print_event_icon(i, j);
        }
        cout<<"|"<<endl;
    }
    for(int i2 =0; i2<cave_edge; i2++){
        cout<<"+---";
    }cout<<"+"<<endl;
}

/******************************************************************
** Function: print_event_icon()
** Description: print the event in the cave. if model is false just print the player icon
** Parameters: none
** Pre-Conditions: there is a cave
** Post-Conditions: none
******************************************************************/
void Game::print_event_icon(int i, int j){
    if(i == p.get_row() && j == p.get_col()){
        cout<<p.get_player_icon()<<" ";
    }else if(Cave[i][j].get_event() != NULL && this->model == true){
        if(Cave[i][j].get_event()->get_event_icon() == "W" && this->wumpus_dead == true){
            cout<<"  ";//if event is wumpus and the wumpus is dead. just print nothing
        }else if(Cave[i][j].get_event()->get_event_icon() == "G" && p.get_has_gold() == true){
            cout<<"  ";
        }else{
            cout<<Cave[i][j].get_event()->get_event_icon()<<" ";
        }
    }else{
        cout<<"  ";
    }
}

/******************************************************************
** Function: check_user_input()
** Description: check user input. if input put is invalid. code will ask user reinput.
** Parameters: char c, bool not_fire
** Pre-Conditions: user have input a char
** Post-Conditions: none
******************************************************************/
bool Game::check_user_input(char c, bool not_fire){
    int n = c;
    if(not_fire == false){
        // ' ', 'w','W', 'a','A' 's','S' 'd' 'D' 
        if( c==32||c==65||c==97||c==68||c==100||c==83||c==115||c==87||c==119){
            return true;
        }else{
            return false;
        }
    }else{
        if(c==65||c==97||c==68||c==100||c==83||c==115||c==87||c==119){
            return true;
        }else{
            return false;
        }
    }
}

/******************************************************************
** Function: get_player_move()
** Description: ask user input the w a d s to move. or space+wasd to shot arrow
** Parameters: char dir[2]
** Pre-Conditions: user have input someting
** Post-Conditions: none
******************************************************************/
void Game::get_player_move(char dir[2]){
    char user_input;
	system("stty -icanon");
	user_input = getchar();
	while(check_user_input(user_input, false) == false){
        cout<<"\nInput invalid, please input: ";
	    user_input = getchar();
    }
    // if user want to shot arrow
    if (user_input == ' '){
        user_input = getchar();
        while(check_user_input(user_input, true) == false){
            cout<<"\nInvalid dirction, please just input a valid direction you want to fire: ";
            user_input = getchar();
        }
        dir[1] = '%';
    }
    dir[0] = user_input;
    cout<<"\n";
}

/******************************************************************
** Function: player_move()
** Description: implatement user's movement. move or shot arrow
** Parameters: none
** Pre-Conditions: user have input someting
** Post-Conditions: none
******************************************************************/
void Game::player_move(){
    char dir[2] = {};
    get_player_move(dir);
    if(dir[1] == '%'){
        if(p.get_arrow_num() == 0){
            cout<<"You don't have any arrow."<<endl;
        }else{
            cout<<"\nYou shot an arrow to the direction "<<dir[0];
            shoot_arrow(dir[0]);
        }
    }else{
        //set player's movement
        set_player_coord(dir[0]);
    }
}

/******************************************************************
** Function: print_percept()
** Description: print the percept when player near by these events
** Parameters: none
** Pre-Conditions: player moved
** Post-Conditions: none
******************************************************************/
void Game::print_percept(){
    int p_row = p.get_row();
    int p_col = p.get_col();
    int p_row_sub_1 = return_valid_coord(p_row, 0);
    int p_row_add_1 = return_valid_coord(p_row, 1);
    int p_col_sub_1 = return_valid_coord(p_col, 0);
    int p_col_add_1 = return_valid_coord(p_col, 1);
    check_print_percept(p_row_sub_1, p_col);
    check_print_percept(p_row_add_1, p_col);
    check_print_percept(p_row, p_col_add_1);
    check_print_percept(p_row, p_col_sub_1);
}

/******************************************************************
** Function: check_print_percept()
** Description: print the percept if the G and W room are null, just nothing print out.
** Parameters: int row, int col
** Pre-Conditions: player moved
** Post-Conditions: none
******************************************************************/
void Game::check_print_percept(int row, int col){
    if(Cave[row][col].get_event() != NULL){
        if(Cave[row][col].get_event()->get_event_icon() == "G" && p.get_has_gold() == true){
            cout<<"";
        }else if(Cave[row][col].get_event()->get_event_icon() == "W" && this->wumpus_dead == true){
            cout<<"";
        }else{
            Cave[row][col].get_event()->percept();
        }
    }
}

/******************************************************************
** Function: encounter_event()
** Description: set player's encounter. if player into a event room
** Parameters: int& n
** Pre-Conditions: player moved
** Post-Conditions: none
******************************************************************/
void Game::encounter_event(int& n){
    n = 0;
    int p_row = p.get_row();
    int p_col = p.get_col();
    if(Cave[p_row][p_col].get_event() != NULL){
        if(Cave[p_row][p_col].get_event()->get_event_icon() == "W" && this->wumpus_dead == true){
            cout<<"";
        }else if(Cave[p_row][p_col].get_event()->get_event_icon() == "G" && p.get_has_gold() == true){
            cout<<"";
        }else{
            Cave[p_row][p_col].get_event()->encounter(p, n, this->cave_edge);
        }
    }
    //if user encounter a bats room, just recheck if this room has event.
    if(n == 1){
        encounter_event(n);
    }
}

/******************************************************************
** Function: set_player_coord()
** Description: set player's coordinates. count the player's coordinates
** Parameters: char dir
** Pre-Conditions: player moved
** Post-Conditions: none
******************************************************************/
void Game::set_player_coord(char dir){
    int i= p.get_row(); int j=p.get_col();
    int k = 0;
    if(dir == 'w' || dir == 'W'){
        k = return_valid_coord(i, 0);
        p.set_row(k);
    }else if(dir == 'a' || dir == 'A'){
        k = return_valid_coord(j, 0);
        p.set_col(k);
    }else if(dir == 's' || dir == 'S'){
        k=return_valid_coord(i, 1);
        p.set_row(k);
    }else{
        k=return_valid_coord(j, 1);
        p.set_col(k);
    }
}

/******************************************************************
** Function: return_valid_coord()
** Description: make sure player's row or col would not greater than the cave edge number.
** Parameters: int n, int sign
** Pre-Conditions: player moved
** Post-Conditions: none
******************************************************************/
int Game::return_valid_coord(int n, int sign){
    int result=0;
    if(sign == 0){
        result = n-1;
    }else{
         result = n+1;
    }
    if(result<0 || result>=this->cave_edge){
        return n;
    }else{
        return result;
    }
}

/******************************************************************
** Function: shoot_arrow()
** Description: check if user shot the wumpus. if not wumpus will move
** Parameters: char dir
** Pre-Conditions: player shot arrow
** Post-Conditions: none
******************************************************************/
void Game::shoot_arrow(char dir){
    int w_row =0; int w_col = 0;
    for(int i=0; i<this->cave_edge; i++){
        for(int j=0; j<this->cave_edge; j++){
            if(Cave[i][j].get_event() != NULL && Cave[i][j].get_event()->get_event_icon() == "W"){
                w_row = i; w_col = j;}
        }
    }
    if(this->wumpus_dead == false){
        shoot_or_not(w_row, w_col, dir);
        if(this->wumpus_dead == true){
            cout<<"\nGood jod! you have killed the monster.";
        }else{
            cout<<"\nOops! you are missing. You may wake Wumpus up.";
            wumpus_move(w_row, w_col);
        }
    }
    int arrow_n = p.get_arrow_num(); arrow_n--;
    p.set_arrow_num(arrow_n);
}

/******************************************************************
** Function: wumpus_move()
** Description: wumpus will have 75% chance to move another room
** Parameters: int w_row, int w_col
** Pre-Conditions: player shot arrow
** Post-Conditions: none
******************************************************************/
void Game::wumpus_move(int w_row, int w_col){
    int dir[2] = {};
    srand(time(NULL));
    int chance = rand() % (3+1)+0;
    // 3/4 is 75% chance.
    if(chance == 0 || chance==1 || chance==2){
        get_empty_room_coord(dir);
        Event *w = Cave[w_row][w_col].get_event();
        Cave[w_row][w_col].set_event(NULL);
        Cave[dir[0]][dir[1]].set_event(w);
    }
}

/******************************************************************
** Function: shoot_or_not()
** Description: check if user shot the wumpus. arrow can through 3 room
** Parameters: int w_row, int w_col, char dir
** Pre-Conditions: player shot arrow
** Post-Conditions: none
******************************************************************/
void Game::shoot_or_not(int w_row, int w_col, char dir){
    int p_row = p.get_row(); int p_col = p.get_col();
    if(p_col == w_col){
        if(dir == 'w' || dir == 'W'){
            if(w_row < p_row && w_row >= p_row - 3){
                this->wumpus_dead = true;}
        }else if(dir == 's' || dir == 'S'){
            if(w_row > p_row && w_row <= p_row + 3){
                this->wumpus_dead = true;}
        }
    }else if(p_row == w_row){
        if(dir == 'a' || dir == 'A'){
            if(w_col < p_col && w_col >= p_col - 3){
                this->wumpus_dead = true;}
        }else if(dir == 'd' || dir == 'D'){
            if(w_col > p_col && w_col <= p_col + 3){
                this->wumpus_dead = true;}
        }
    }
}

/******************************************************************
** Function: main_game()
** Description: make user keep move and check the gameover condition.
** Parameters: none
** Pre-Conditions: player shot arrow
** Post-Conditions: none
******************************************************************/
void Game::main_game(){
    int game_over_flage = 0;
    generate_cave();
    print_cave();
    print_percept();
    do{
        player_move(); cout<<"\n";
        encounter_event(game_over_flage);
        print_cave();
        if(game_over_flage != 4 && game_over_flage != 3 && game_over_flage != 2)
            print_percept(); cout<<"\n";
    }while(game_over_flage != 4 && game_over_flage != 3 && game_over_flage != 2);
    cout<<"<----Game Over!---->"<<endl;
}