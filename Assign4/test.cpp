/******************************************************
** Program: test.cpp
** Author: Jianglong Yu
** Date: 12/3/2021
** Description: Implement the application. Ask user input the number. 
**              And sort numbers according to user choice. Print the prime number in list.
** Input: Linked_List.h
******************************************************/
#include "Linked_List.h"
#include <iostream>
#include <limits>

using namespace std;

/******************************************************************
** Function: number_check()
** Description: check user input. if not a number, ask user reinput
** Parameters: std::istream &input, int *val
** Pre-Conditions: none
** Post-Conditions: there is a input
******************************************************************/
void number_check(std::istream &input, int *val){
    input >> *val;
    if(input.fail()){
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Input is invalid, please input again: ";
        number_check(input, val);
    }
}

/******************************************************************
** Function: check_choose_yn()
** Description: check user input. Check whether the user entered y or n
** Parameters: char&
** Pre-Conditions: none
** Post-Conditions: there is a input
******************************************************************/
bool check_choose_yn(char& choose){
    int c2n = choose;
    while(c2n != 121 && c2n != 110){
        cout<<"Invalid input please input y or n: ";
        cin >> choose;
        c2n = choose;
    }
    if(c2n == 121){
        return true;
    }else{
        return false;
    }
}

/******************************************************************
** Function: check_choose_yn()
** Description: check user input. Check whether the user entered a or d
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: there is a input
******************************************************************/
bool check_choose_ad(){
    char choice;
    cout<<"Sort ascending or descending (a or d)? ";
    cin >> choice;
    int c2n = choice;
    while(c2n != 97 && c2n != 100){
        cout<<"Invalid input please input a or d: ";
        cin >> choice;
        c2n = choice;
    }
    if(c2n == 97){
        return true;
    }else{
        return false;
    }
}

/******************************************************************
** Function: get_user_input()
** Description: get user input. and ask if user want enter another number.
** Parameters: Linked_List&
** Pre-Conditions: none
** Post-Conditions: there is a input
******************************************************************/
void get_user_input(Linked_List &l){
    int user_input = 0;
    cout<<"Please enter a number: ";
    number_check(cin, &user_input);
    l.push_back(user_input);
    char choose;
    cout<<"Do you want another num (y or n): ";
    cin >> choose;
    while(check_choose_yn(choose)){
        cout<<"Enter a number: ";
        number_check(cin, &user_input);
        l.push_back(user_input);
        cout<<"Do you want another num (y or n): ";
        cin >> choose;
    }
}

/******************************************************************
** Function: game()
** Description: get user input. and ask which sort method they want to use.
**              print the prime number. Ask user if he/she want to do this again.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: there is a input
******************************************************************/
void game(){
    char choose;
    do{
        Linked_List l(0);
        get_user_input(l);
        if(check_choose_ad()){
            l.sort_ascending();
        }else{
            l.sort_descending();
        }
        cout<<"Your linked list is: "; l.print();
        cout<<"You have "<<l.get_prime_num()<<" prime number(s) in your list."<<endl;
        cout<<"Do you want to do this again (y or n)? ";
        cin>>choose;
        l.clear();
    }while(check_choose_yn(choose));
}

/******************************************************************
** Function: main()
** Description: call game()
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
******************************************************************/
int main(){
    game();
}