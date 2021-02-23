// QueueTestDriver.cpp

#include "Queue.h"
#include <iostream>
using namespace std;


int main () {
    Queue Q;

    // enqueue 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        Q.enqueue(i);
        cout << "enqueue " << i << endl;
        Q.print();
    }


    // dequeue 2x elements
    for (int i = 0; i < 2; i++) {
        int y = Q.peek();
        Q.dequeue();
        cout << "peek " << y << endl;
        Q.print();
    }
    Q.print();

    // enqueue 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++) {
        Q.enqueue(i);
        cout << "enqueue " << i << endl;
        Q.print();
    }
    Q.print();

    // dequeue all elements
    while (!Q.isEmpty()) {
        int y = Q.peek();
        Q.dequeue();
        cout << "peek " << y << endl;
        Q.print();
    }

    return 0;
}
