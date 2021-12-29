/*#pragma once 
#include <iostream>
#include "datatype.hpp"

using namespace std;

class Q_Node
{
public:
    int count;
    Course* course;
    Q_Node* lChild;
    Q_Node* rChild;
    Q_Node()
    {
        int count = 0;
        lChild = NULL;
        rChild = NULL;
    }
};

class binary_Heap
{
public:
    Q_Node* root;
    binary_Heap()
    {
        root = NULL;
    }
    bool isEmpty();
    void insert(Course *, int);
    void returnList(LinkedList *);
    Course *getMax();
};

bool binary_Heap::isEmpty()
{
    return root == NULL;
}

void binary_Heap::insert(Course *obj, int parameter)
{

    arrPtr[child].count = parameter;
    arrPtr[child].course = obj;
    parent = child / 2;

    do
    {
        if (arrPtr[child].count > arrPtr[parent].count)
            swap(arrPtr[child], arrPtr[parent]);

        child = parent;
        parent = child / 2;
    } while (parent >= 1);
}*/