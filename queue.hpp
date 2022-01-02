#pragma once
#include <iostream>
#include "datatype.hpp"
using namespace std;
class Heap_Node
{
public:
    float data;
    Course* node;
    Heap_Node* LeftChild;
    Heap_Node* RightChild;
    Heap_Node* Parent;
    Heap_Node(float value)
    {
        data = value;
        LeftChild = NULL;
        RightChild = NULL;
        Parent = NULL;
    }
};
struct QNode {
    Heap_Node* data;
    QNode* next;
    QNode(Heap_Node* d)
    {
        data = d;
        next = NULL;
    }
};

class Queue {
private:
    QNode* Front, * rear;
public:
    Queue()
    {
        Front = rear = NULL;
    }
    bool is_empty()
    {
        return (Front == NULL) ;
    }

    Heap_Node* front()
    {
        return Front->data;
    }
    void push(Heap_Node* x)
    {
        QNode* temp = new QNode(x);

        if (rear == NULL) {
            Front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }
    
   
    void pop()
    {
        
        if (Front == NULL)
            return;
        QNode* temp = Front;
        Front = Front->next;

        if (Front == NULL)
            rear = NULL;

        delete (temp);
    }
};



