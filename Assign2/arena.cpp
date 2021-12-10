/******************************************************
** Program: arnea.cpp
** Author: Jianglong Yu
** Date: 10/29/2021
** Description: Manage the two Trainers in each battle and the game flow. 
                Implement functions for choosing each Pokémon for a team, checking win conditions, user interface, and taking turns.
** Input: mainly user input
** Output: String type, battle information.
******************************************************/
#include "arena.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <limits> //use for check numbers

using namespace std;

/******************************************************************
** Function: Arena
** Description: default constructor of Arena object 
** Parameters: none
******************************************************************/
Arena::Arena(){
    for(int i=0; i<2; i++){
        Trainer t;
        this->t[i] = t;
    }
}

/******************************************************************
** Function: ~Arena()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Arena::~Arena(){}

/******************************************************************
** Function: Arena(Trainer*)
** Description: Set the Arena object
** Parameters: Trainer*
** Pre-Conditions: has a defult constructor
** Post-Conditions: the trainer list is valid
******************************************************************/
Arena::Arena(Trainer t[2]){
    for(int i=0; i<2; i++){
        this->t[i] = t[i];
    }
}

/******************************************************************
** Function: get_trainers()
** Description: to get the private attribute number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
Trainer* Arena::get_trainers(){
    return t;
}

/******************************************************************
** Function: set_trainers
** Description: set the trainer list
** Parameters: Trainer*
** Pre-Conditions: valid input
** Post-Conditions: none
******************************************************************/
void Arena::set_trainers(Trainer t[2]){
     for(int i=0; i<2; i++){
        this->t[i] = t[i];
    }
}

/******************************************************************
** Function: number_check
** Description: check whether user input a number or not.
** Parameters: istream, and the address to store the input
** Pre-Conditions: there is a input
** Post-Conditions: none
******************************************************************/
void Arena::number_check(std::istream &input, int *val){
    input >> *val;
    if(input.fail()){
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Input is invalid, please input again: ";
        number_check(input, val);
    }
}

/******************************************************************
** Function: print_pokemons_list()
** Description: print the pokemons list before user choose pokemons, and return the player name
** Parameters: none
** Pre-Conditions: Pokemons consturctor is valid.
** Post-Conditions: user input a name
******************************************************************/
string Arena::print_pokemons_list(){
    string trainer_name;
    cout<<"Welcom to the Arena! what is your name?"<<endl;
    cin >> trainer_name;
    cout<<"Hello "<<trainer_name<<"! This is the Pokemon list. You can choose only three pokemons."<<endl;
    cout<<"\n-----Pokemons List-----"<<endl;
    cout<<"Name       "<<"Type  "<<"HP  "<<"Attack  "<<"Defense  "<<endl;
    Bulbasaur b;//just for print the pokemon's info
    cout<<"1."; b.print_info();
    Charmander c;
    cout<<"2."; c.print_info();
    Squirtle s;
    cout<<"3."; s.print_info();
    return trainer_name;
}

/******************************************************************
** Function: ask_user_choose_pokes()
** Description: Ask user choose pokemons, and store pokemon team to user's address
** Parameters: Trainer&
** Pre-Conditions: User's input is valid
** Post-Conditions: none
******************************************************************/
void Arena::ask_user_choose_pokes(Trainer& player){
    string trainer_name;
    Pokemon* team[3];
    trainer_name = print_pokemons_list();
    cout<<"\nChoose your pokemon here, just input the sequence number of the pokemon. "<<endl;
    int choice = -1;
    for(int i=0; i<3; i++){
        cout<<"Pokemon "<<i+1<<": ";
        number_check(cin, &choice);//invalid input check
        while(!(choice == 1 || choice == 2 || choice == 3)){
            cout << "Invalid number, please input again(1-3): ";
            number_check(cin, &choice);
        }
        add_pokemons(choice, team, i);
    }
    player.set_team(team);//use set team to store the team info
    player.set_player_name(trainer_name);//set user name
}

/******************************************************************
** Function: add_pokemons()
** Description: add the pokemons into the team
** Parameters: user choice, pokemon list, and idx
** Pre-Conditions: user choice is valid
** Post-Conditions: none
******************************************************************/
void Arena::add_pokemons(int choice, Pokemon* team[3], int idx){
    if(choice == 1){
        Bulbasaur* b = new Bulbasaur;
        team[idx] = b;
    }
    else if(choice == 2){
        Charmander* c = new Charmander;
        team[idx] = c;
    }
    else if(choice == 3){
        Squirtle* s = new Squirtle;
        team[idx] = s;
    }
}

/******************************************************************
** Function: computer_choose_pokes()
** Description: computer add pokemons, use random number to add pokemons
** Parameters: Trainer&
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
void Arena::computer_choose_pokes(Trainer& computer){
    Pokemon* team[3];
    srand((unsigned)time(NULL)); int choice = 0;
    for(int i=0; i<3; i++){
        choice = rand()%(2+1)+1;
        add_pokemons(choice, team, i);
    }
    computer.set_team(team); //set computer pokemon team
}

/******************************************************************
** Function: print_actions()
** Description: print the actions for user
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: when call it
******************************************************************/
void Arena::print_actions(){
    cout<<"---Your turn---"<<endl; cout<<"1. Fight"<<endl; cout<<"2. Heal"<<endl;
    cout<<"3. Swap\n4. Exit"<<endl; cout<<"Please choose(1-4): ";
}

/******************************************************************
** Function: print_actions()
** Description: ask user to make a choice
** Parameters: Trainer& player, Trainer& computer, int& win_flag
** Pre-Conditions: user input is valid
** Post-Conditions: none
******************************************************************/
void Arena::ask_player_choose_action(Trainer& player, Trainer& computer, int& win_flag){
    int choice = 0; 
    if(check_first_poke_hp(player) == 1){ //if the first pokemon's hp is 0, the program will ask user swap
        cout<<"Your first pokemon is no health point.";
        swap(player, choice, 0);
    }else{
        print_actions(); number_check(cin, &choice);
        while(!(choice == 1 || choice == 2 || choice == 3 || choice == 4)){
            cout << "Invalid number, please input again(1-3): ";
            number_check(cin, &choice);
        }cout<<""<<endl;
        if(choice == 1){ //fight
            fight(player, computer);
            if(check_each_poke_hp(computer) == 1)
                win_flag = 1;
        }
        else if(choice == 2){ // heal
            heal(player, choice, 0);}
        else if(choice == 3){ //swap
            swap(player, choice, 0);}
        else{win_flag = 0;} // exit
    }
}

/******************************************************************
** Function: computer_swap_valid_poke()
** Description: When the first pokemon's hp is 0, this funtion help computer swap its pokemon
                and include normal swap condition.
** Parameters: Trainer& t, int n
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
int Arena::computer_swap_valid_poke(Trainer& t, int n){
    Pokemon** team = t.get_team();
    int choice = 0;//if the first pokemon's hp is zero
    if(n == 1){
        if(team[1]->get_health_point() == 0){
            choice = 3;
        }else{
            choice = 2;}
    }else if(n == 2){//if computer choose swap (normal condition)
        do{
            // srand((unsigned)time(NULL));
            choice = rand()%(1+1)+2;
        }while(team[choice-1]->get_health_point() == 0);
    }
    return choice;
}

/******************************************************************
** Function: computer_choose_action()
** Description: computer make a choice, use random number
** Parameters: Trainer& player, Trainer& computer, int& win_flag
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
void Arena::computer_choose_action(Trainer& player, Trainer& computer, int& win_flag){
    int swap_choice = 0; int choice = 0;
    cout<<"---Computer turn---"<<endl;
    if(check_first_poke_hp(computer) == 1){ //if first pokemon's hp is 0
        swap_choice = computer_swap_valid_poke(computer, 1);
        swap(computer, swap_choice, 1);
    }else{
        if(check_last_two_poke_hp(computer) == 1){choice = rand()%(1+1)+1;}
        // srand((unsigned)time(NULL));
        else{choice = rand()%(2+1)+1;}
        // int choice = 1;
        if(choice == 1){
            fight(computer, player);
            if(check_each_poke_hp(player) == 1){
                win_flag = 2;}}
        else if(choice == 2){
            int heal_choice = rand()%(2+1)+1;
            heal(computer, heal_choice, 1);}
        else if(choice == 3){
            swap_choice = computer_swap_valid_poke(computer, 2);
            swap(computer, swap_choice, 1);}}
}

/******************************************************************
** Function: fight()
** Description: use for fight damage count
** Parameters: Trainer& atk, Trainer& dfs
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
void Arena::fight(Trainer& atk, Trainer& dfs){
    //get the trainers' team.
    Pokemon** atk_team = atk.get_team();
    Pokemon** dfs_team = dfs.get_team();
    //generate random number 0.85-1.15
    srand (static_cast <unsigned> (time(0)));
    float random = 0.85 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.15-0.85)));
    //get type_effectiveness
    float type_effectiveness = atk_team[0]->get_Type_Effectiveness(dfs_team[0]->get_type());
    float a = atk_team[0]->get_attack(); float b = dfs_team[0]->get_defense();
    float div = a / b;
    float damage = 15* div * type_effectiveness * random;
    cout<<atk.get_player_name()<<"'s pokemon did "<<damage<<" damage to "<<dfs.get_player_name()<<"'s pokemon\n"<<endl;
    float dfs_hp = dfs_team[0]->get_health_point();
    dfs_hp -= damage;
    //if the hp is less than 0, then set it to 0;
    if(dfs_hp < 0){
        dfs_hp = 0;
    }
    dfs_team[0]->set_health_point(dfs_hp);
}

/******************************************************************
** Function: heal()
** Description: use for heal the pokemon
** Parameters: Trainer& t, int choice, int p
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
void Arena::heal(Trainer& t, int choice, int p){
    if(p == 0){ //user need choose which pokemon he/she want to heal
        int player_choice = -1;
        cout<<"Which pokemon your want to heal(1-3): ";
        number_check(cin, &player_choice);
        while(!(player_choice == 1 || player_choice == 2 || player_choice == 3)){
            cout << "Invalid number, please input again(1-3): ";
            number_check(cin, &player_choice);
        }
        cout<<""<<endl;
        choice = player_choice;
    }
    //get the trainers' team
    Pokemon** team = t.get_team();
    choice-=1;
    float t_hp = team[choice]->get_health_point(); t_hp += 15; 
    // if hp is greater than its max hp after, just set the hp to max hp
    if (t_hp > team[choice]->get_max_health_point()){ 
        t_hp = team[choice]->get_max_health_point();
    }
    team[choice]->set_health_point(t_hp);
    cout<<t.get_player_name()<<" has healed pokemon "<<choice+1<<".\n"<<endl;
}

/******************************************************************
** Function: swap()
** Description: use for swap the pokemon's position
** Parameters: Trainer& t, int choice, int p
** Pre-Conditions: none
** Post-Conditions: user's input is valid
******************************************************************/
void Arena::swap(Trainer& t, int choice, int p){
    Pokemon** team = t.get_team();
    if(p == 0){//if user want to swap position.ask user input the swap number
        int player_choice = 0;
        do{
            cout<<"Which pokemon your want to swap(2-3): ";
            number_check(cin, &player_choice);
            while(!(player_choice == 2 || player_choice == 3)){
                cout << "Invalid number or the pokemon you chosen can not fight: ";
                number_check(cin, &player_choice);}
        }while(team[player_choice-1]->get_health_point() == 0);
        cout<<""<<endl;
        choice = player_choice;
    }
    choice-=1;
    Pokemon* temp = team[0];
    team[0] = team[choice];
    team[choice] = temp;
    cout<<t.get_player_name()<<" has swaped pokemon "<<choice+1<<" position.\n"<<endl;
}

/******************************************************************
** Function: print_pokemons_info_t()
** Description: Print two trainers' pokemon information.
** Parameters: Trainer& player, Trainer& computer
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
void Arena::print_pokemons_info_t(Trainer& player, Trainer& computer){
    cout<<"-----Pokemons information-----"<<endl;
    player.print_pokemons(); cout<<""<<endl;
    computer.print_pokemons();
    cout<<"-------------------------------\n"<<endl;
}

/******************************************************************
** Function: check_each_poke_hp()
** Description: check wheather all pokemons' hp of current trainer are 0; 
** Parameters: Trainer& t
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
int Arena::check_each_poke_hp(Trainer& t){
    Pokemon** team = t.get_team(); int j=0;
    for(int i=0; i<3; i++){
        if(team[i]->get_health_point() == 0){
            j++;
        }
    }
    if(j == 3){//if all pokemons' hp is 0 return 1
        return 1;
    }
    else{return 0;}
} 

/******************************************************************
** Function: check_first_poke_hp()
** Description: check whether the first pokemon's hp of current trainer is 0
** Parameters: Trainer& t
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
int Arena::check_first_poke_hp(Trainer& t){
    Pokemon** team = t.get_team();
    if(team[0]->get_health_point() == 0){//if hp is 0 return 1;
        return 1;
    }
    else{return 0;}
}

/******************************************************************
** Function: check_last_two_poke_hp()
** Description: check wheather last two pokemons' hp of current trainer are 0; 
** Parameters: Trainer& t
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
int Arena::check_last_two_poke_hp(Trainer& t){
    Pokemon** team = t.get_team(); int j=0;
    for(int i=1; i<3; i++){
        if(team[i]->get_health_point() == 0){
            j++;
        }
    }
    if(j == 2){//if all pokemons' hp is 0 return 1
        return 1;
    }
    else{return 0;}
}

/******************************************************************
** Function: round_game()
** Description: Loop rounds until a trainer wins
** Parameters: Trainer& player, Trainer& computer
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
void Arena::round_game(Trainer& player, Trainer& computer){
    int win_flag = -1;
    do{
        print_pokemons_info_t(player,computer);
        ask_player_choose_action(player, computer, win_flag);
        if(win_flag == 0 || win_flag == 1){break;}
        print_pokemons_info_t(player,computer);
        computer_choose_action(player, computer, win_flag);
    }while(!(win_flag == 1||win_flag == 2||win_flag == 0));
    if(win_flag == 1){//if user win
        cout<<"You win! Computer lost this game."<<endl;}
    else if(win_flag == 2){//if computer win
        cout<<"Computer win! You lost this game."<<endl;}
}

/******************************************************************
** Function: main_game()
** Description: set two trainers and ask user choose pokemons
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
void Arena::main_game(){
    srand((unsigned)time(NULL));
    Trainer player;
    Trainer computer("Computer");
    ask_user_choose_pokes(player);
    computer_choose_pokes(computer);
    cout<<"\n----------GAME START----------\n"<<endl;
    round_game(player, computer);
    print_pokemons_info_t(player, computer);
}