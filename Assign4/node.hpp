/******************************************************
** Program: node.hpp
** Author: Jianglong Yu
** Date: 12/3/2021
** Description: a file implemented the node class
******************************************************/
#include <iostream>

using namespace std;
class Node {
public:
   int val;             // the value that this node stores
   Node *next;          // a pointer to the next node in the list

/******************************************************************
** Function: Node()
** Description: default the Node object.
** Parameters: val, Node* next
******************************************************************/
   Node(int val = 0, Node* next = NULL){
      this->val = val;
      this->next = next;
   }

/******************************************************************
** Function: Node()
** Description: a copy constructor of Node
** Parameters: const Node& node
** Pre-Conditions: there is a copy constructor
** Post-Conditions: none
******************************************************************/
   Node(const Node& node){
      this->val = node.val;
      this->next = node.next;
   }

/******************************************************************
** Function: operator=()
** Description: a operation "=" overload function
** Parameters: const Event& event
** Pre-Conditions: there is a copy constructor
** Post-Conditions: none
******************************************************************/
   void operator=(Node& node){
      this->val = node.val;
      this->next = node.next;
   }

/******************************************************************
** Function: ~Node()
** Description: a destructor function
** Parameters: none
** Pre-Conditions: there is a constructor
** Post-Conditions: none
******************************************************************/   
   ~Node(){};
};