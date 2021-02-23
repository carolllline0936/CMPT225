/* 
 * Queue.cpp
 *
 * Description: Queue data collection ADT class.
 *              Implementation of an int sequence with enqueue at the back and dequeue at the front of the array.
                Expand size when the capacity is less than 1/4 space.
 * Class Invariant: Queue data in FIFO order
 *
 * Author:Shiyi Zhou, Danling Yang
 * Date:Sep 28, 2019
 */
 
#include "Queue.h"
#include "iostream"
using namespace std;

// Description: Constructor
Queue::Queue() {
    
    elementCount=0;
    capacity=INITIAL_SIZE;
    elements=new int[capacity];

    
} 


// Description: Inserts newElement at the back (O(1))
void Queue::enqueue(int newElement) {
    elementCount++;
    if(elementCount>=static_cast<float>(0.75*capacity)){
        capacity=capacity*2;
    }
    backindex=elementCount-1;
    int *temp=new int[capacity];
    temp[backindex]=newElement;
    for (int i=0;i<elementCount-1;i++){
        temp[i]=elements[i];
    }
    delete[] elements;
    elements=temp;
    return;
} 

// Description: Removes the frontmost element (O(1))
// Precondition: Queue not empty
void Queue::dequeue() {
	
    if(elementCount==0){
        cout<<"empty now!"<<endl;
        return;
    }
	elementCount--;
    int *temp=new int[capacity];
    
    for (int i=0;i<elementCount;i++){
        temp[i]=elements[i+1];
    } 
    delete[] elements;
    elements=temp;
}


// Description: Returns a copy of the frontmost element (O(1))
// Precondition: Queue not empty
int Queue::peek() const {
    return elements[0];
} 


// Description: Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return elementCount == 0;
} 

