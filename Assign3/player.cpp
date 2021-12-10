#include "player.h"
#include <iostream>
#include <string>

using namespace std;

/******************************************************************
** Function: Player()
** Description: default the Player object.
** Parameters: none
******************************************************************/
Player::Player(){
    player_icon = "*";
    col = 0;
    row = 0;
    has_gold = false;
    arrow_num = 3;
}

/******************************************************************
** Function: Player()
** Description: a copy constructor function
** Parameters: const Player& player
** Pre-Conditions: there is a copy constructor
** Post-Conditions: none
******************************************************************/
Player::Player(const Player& player){
    this->player_icon = player.player_icon;
    this->col = player.col;
    this->row = player.row;
    this->has_gold = player.has_gold;
    this->arrow_num = player.arrow_num;
}

/******************************************************************
** Function: ~Player()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/
Player::~Player(){}

/******************************************************************
** Function: get_player_icon()
** Description: to get the private attribute player_icon.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
string Player::get_player_icon(){
    return this->player_icon;
}

/******************************************************************
** Function: get_col()
** Description: to get the private attribute col.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
int Player::get_col(){
    return this->col;
}

/******************************************************************
** Function: get_row()
** Description: to get the private attribute row.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
int Player::get_row(){
    return this->row;
}

/******************************************************************
** Function: get_has_gold()
** Description: to get the private attribute has_gold.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
bool Player::get_has_gold(){
    return this->has_gold;
}

/******************************************************************
** Function: get_arrow_num()
** Description: to get the private attribute arrow_num.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
int Player::get_arrow_num(){
    return this->arrow_num;
}

/******************************************************************
** Function: set_player_icon()
** Description: to set the private attribute player_icon.
** Parameters: string
** Pre-Conditions: valid input
** Post-Conditions: it is initialized.
******************************************************************/
void Player::set_player_icon(string player_icon){
    this->player_icon = player_icon;
}

/******************************************************************
** Function: set_col()
** Description: to set the private attribute col.
** Parameters: int
** Pre-Conditions: valid input
** Post-Conditions: it is initialized.
******************************************************************/
void Player::set_col(int col){
    this->col = col;
}

/******************************************************************
** Function: set_row()
** Description: to set the private attribute row.
** Parameters: int
** Pre-Conditions: valid input
** Post-Conditions: it is initialized.
******************************************************************/
void Player::set_row(int row){
    this->row = row;
}

/******************************************************************
** Function: set_has_gold()
** Description: to set the private attribute has_gold.
** Parameters: bool
** Pre-Conditions: valid input
** Post-Conditions: it is initialized.
******************************************************************/
void Player::set_has_gold(bool has_gold){
    this->has_gold = has_gold;
}

/******************************************************************
** Function: set_arrow_num()
** Description: to set the private attribute arrow_num.
** Parameters: int
** Pre-Conditions: valid input
** Post-Conditions: it is initialized.
******************************************************************/
void Player::set_arrow_num(int arrow_num){
    this->arrow_num = arrow_num;
}