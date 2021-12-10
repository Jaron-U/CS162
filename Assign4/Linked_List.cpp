/******************************************************
** Program: Linked_List.cpp
** Author: Jianglong Yu
** Date: 12/3/2021
** Description: a file implemented the Linked_List class. push_back, insert, 
**              merge sort. And clear list.
** Input: Linked_List.h
******************************************************/
#include "Linked_List.h"
#include <iostream>

using namespace std;

/******************************************************************
** Function: Linked_List()
** Description: default the Linked_List object.
** Parameters: none
******************************************************************/
Linked_List::Linked_List(){
    this->length = 0;               
    this->head = NULL;
}

/******************************************************************
** Function: Linked_List()
** Description: Set the Linked_List object.
** Parameters: Node* head
******************************************************************/
Linked_List::Linked_List(Node* head){   
    this->length = 0;        
    this->head = head;
}

/******************************************************************
** Function: get_length()
** Description: count the length of this linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: it is initialized.
******************************************************************/
int Linked_List::get_length(){
    int count = 0;
    Node* node = head;
    while(node != NULL){
        count++;
        node = node->next;
    }
    return count;
}

/******************************************************************
** Function: print()
** Description: print the numbers in this linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: there is a linked list.
******************************************************************/
void Linked_List::print(){
    if(this->head == NULL){
        cout<<"This list is empty." <<endl;
    }else{
        Node* node = head;
        while(node != NULL){
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<"\n";
    }
}

/******************************************************************
** Function: push_front(int n)
** Description: insert a new value at the front of the list (returns the new length of the list)
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: valid number
******************************************************************/
unsigned int Linked_List::push_front(int n){
    Node* new_node = new Node(n);
    if(this->head == NULL){
        head = new_node;
    }else{
        new_node->next = head;
        this->head = new_node;
    }
    return this->length++;
}

/******************************************************************
** Function: push_back(int n)
** Description: insert a new value at the back of the list (returns the new length of the list)
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: valid number
******************************************************************/
unsigned int Linked_List::push_back(int n){
    Node* new_node = new Node(n);
    if(this->head == NULL){
        head = new_node;
    }else{
        Node* node = head;
        while(node != NULL){
            if(node->next == NULL){
                break;
            }
            node = node->next;
        }
        node->next = new_node;
    }
    return this->length++;
}

/******************************************************************
** Function: insert()
** Description: insert a new value in the list at the specified index (returns the new length of the list)
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: valid number
******************************************************************/
unsigned int Linked_List::insert(int val, unsigned int index){
    Node* new_node = new Node(val);
    if(index > this->length-1){
        cout<<"Invalid index, should less than"<<this->length<<"."<<endl;
    }else{
        Node *node = head;
        for(int i=0; i<index-1; i++){
            node = node->next;
        }
        Node* last_node = node->next;
        node->next = new_node;
        new_node->next = last_node;
    }
    return this->length++;
}

/******************************************************************
** Function: clear()
** Description: delete the entire list (remove all nodes and reset length to 0)
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: there is linked list
******************************************************************/
void Linked_List::clear(){
    if(head == NULL){
        cout<<"This list is empty."<<endl;
    }else{
        Node* current = head;
        Node* next = NULL;
        while(current != NULL){
            next = current->next;
            delete current;
            current = next;
        }
        this->head = NULL;
    }
}

/******************************************************************
** Function: sort_ascending()
** Description: call a merge sort function. and get the ascending sorted linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: there is linked list
******************************************************************/
void Linked_List::sort_ascending(){
    this->head = split(this->head);
}

/******************************************************************
** Function: split()
** Description: split the linked list into two part.
** Parameters: Node*
** Pre-Conditions: none
** Post-Conditions: there is linked list
******************************************************************/
Node* Linked_List::split(Node* ihead){
    if(ihead->next == NULL || ihead->next == NULL){
        return ihead;
    }
    Node* left = ihead; 
    Node* right = ihead->next;
    while (right != NULL){
        right = right->next;
        if (right != NULL){
            right = right->next; 
            left = left->next;}
    }
    Node* left_head = ihead;
    Node* right_head = left->next;
    left->next = NULL;
    return merge_sort(split(left_head), split(right_head));
}

/******************************************************************
** Function: merge_sort()
** Description: compare the val of two list. and sort. return the sorted node head.
** Parameters: Node*, Node*
** Pre-Conditions: none
** Post-Conditions: there is linked list
******************************************************************/
Node* Linked_List::merge_sort(Node* left_head, Node* right_head){
    Node temp_head(0); 
    Node* result_head = &temp_head;
    Node* r_head = result_head;
    while(left_head != NULL && right_head != NULL){
        if(left_head->val < right_head->val){
            result_head->next = left_head;
            left_head = left_head->next;
        }else{
            result_head->next = right_head;
            right_head = right_head->next;
        }
        result_head = result_head->next;
    }
    if(left_head != NULL){
        result_head->next = left_head;
    }else{
        result_head->next = right_head;}
    return r_head->next;
}

/******************************************************************
** Function: sort_descending()
** Description: call a selection sort function. and get the descending sorted linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: there is linked list
******************************************************************/
void Linked_List::sort_descending(){
    this->head=selection_sort(this->head);
}

/******************************************************************
** Function: sort_descending()
** Description: use selection sort algorithm sort linked list.
** Parameters: Node*
** Pre-Conditions: none
** Post-Conditions: there is linked list
******************************************************************/
Node* Linked_List::selection_sort(Node* ihead){
    Node* outter = ihead;
    for(int i=0; i<this->length; i++){
        Node* max = outter;
        Node* inner = outter->next;
        while(inner != NULL){
            if(max->val < inner->val){
                max = inner;
            }
            inner = inner->next;
        }
        //just swap the val
        int temp_val = outter->val;
        outter->val = max->val;
        max->val = temp_val;
        outter = outter->next;
    }
    return ihead;
}

/******************************************************************
** Function: get_prime_num()
** Description: get the prime num in the linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: there is linked list
******************************************************************/
int Linked_List::get_prime_num(){
    int prime_num = 0; 
    Node* node = this->head;
    while (node != NULL){
        bool flag = true;
        if (node->val <= 1)
            flag = false;
        for (int i = 2; i <= node->val / 2; i++){
            if (node->val % i == 0)
                flag = false;
        }
        node = node->next; 
        if(flag)
            prime_num++;
    } 
    return prime_num;
}