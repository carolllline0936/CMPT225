////// Stack.cpp
/*
* Stack.cpp
*
* Description: Stack data collection ADT class.
*              Implementation of an int sequence with push/pop at the  end of the linked list
* Class Invariant: linked list in a LIFO order
*
* Author: Danling Yang, Shiyi Zhou
* Date: Oct 3rd, Thu
*/

#include <iostream>
#include "Stack.h"
#include <stdio.h>
using namespace std;

Stack::Stack(){
    head=NULL;
    tail=NULL;
}

Stack::~Stack(){
    while (head!=NULL){
        StackNode *node=head->next;
        delete head;
        head=node;
    }
}

void Stack::push(int newElement){
    StackNode *newnode=new StackNode();
    newnode->data=newElement;
    newnode->next=NULL;
    if (head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        StackNode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        tail=newnode;
    }
}

// Description: Remove and return element at the top of the stack.
// Precondition: Stack is not empty   
int Stack::pop(){
    //empty
    if(head==NULL){
        cout<<"Empty!"<<endl;
        return -1;
    }

    if(head->next==NULL){
        head=NULL;
        tail=NULL;
        cout<<"list is empty now"<<endl;
        return 0;
    }
    StackNode *temp=head;
    StackNode *curr=head->next;
    while(temp->next!=tail){
        temp=temp->next;
        curr=curr->next;
    }
    temp->next=NULL;
    tail=temp;
    return tail->data;
}

int Stack::peek() const{
    return tail->data;
}

bool Stack::isEmpty() const{
    return head==NULL;
}

void Stack::print(){
    cout<<"Linked List is: "<<endl;
    StackNode *curr =head;
    while(curr!=NULL){
        cout <<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
