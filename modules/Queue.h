#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "LinkedList.h"
using namespace std;

class Queue
{
public:
    void enqueue(int value) { list.insertAtEnd(value); };
    void dequeue() { list.removeFront(); };
    int front() const { return list.front(); }
    bool isEmpty() const { return list.isEmpty(); };
    void display() const { list.display(); };

private:
    LinkedList list;
};
#endif