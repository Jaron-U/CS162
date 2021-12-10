/******************************************************
** Program: Linked_List.h
** Author: Jianglong Yu
** Date: 12/3/2021
** Description: a header file for Linked_List class
** Input: "node.hpp"
******************************************************/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.hpp"

using namespace std;

class Linked_List{
private:
   unsigned int length;                 // the number of nodes contained in the list
   Node *head;                          // a pointer to the first node in the list

public:
   Linked_List();
   Linked_List(Node* node = NULL);
   int get_length();
   void print();                        // output a list of all integers contained within the list
   void clear();                        // delete the entire list (remove all nodes and reset length to 0)
   unsigned int push_front(int);        // insert a new value at the front of the list (returns the new length of the list)
   unsigned int push_back(int);         // insert a new value at the back of the list (returns the new length of the list)
   unsigned int insert(int, unsigned int);

   void sort_ascending();
   Node* split(Node*);
   Node* merge_sort(Node*, Node*);

   void sort_descending();
   Node* selection_sort(Node*);
   
   int get_prime_num();
};
#endif
