#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "datatype.hpp"

using namespace std;

class q_Node
{
public:
    int count;
    Course *course;
};

class binary_Heap
{
private:
    q_Node *arrPtr;
    int index, lChild, rChild, parent, size;

public:
    binary_Heap(int SIZE = 5)
    {
        index = 1;
        size = SIZE;
        arrPtr = new q_Node[size] ();

        for (size_t i = 1; i < size; i++)
            arrPtr[i].count = -9999;
    }
    bool isEmpty();
    bool isFull();
    void insert(Course *, float);
    void returnList(LinkedList *);
    Course *getMax();
    void increaseCapacity();
};

void binary_Heap::increaseCapacity()
{
    q_Node *temp = arrPtr;
    q_Node *newArray = new q_Node[2 * size] ();

    for (size_t i = 1; i < size; i++)
        newArray[i] = arrPtr[i];

    for (size_t i = size; i < size * 2; i++)
        newArray[i].count = -9999;

    size = size * 2;
    arrPtr = newArray;
    delete temp;
}

bool binary_Heap::isFull()
{
    return index + 1 == size;
}

Course *binary_Heap::getMax()
{
    if (isEmpty())
        return NULL;

    Course *temp = arrPtr[1].course;
    parent = 1;
    lChild = parent * 2, rChild = parent * 2 + 1;

    int flag = 0;
    do
    {
        if (arrPtr[lChild].count > arrPtr[rChild].count)
            flag = 1;

        else if (arrPtr[lChild].count == arrPtr[rChild].count)
        {
            if (arrPtr[lChild].course == NULL || arrPtr[rChild].course == NULL)
                flag = 0;

            else if (arrPtr[lChild].course->data.subscribers > arrPtr[rChild].course->data.subscribers)
                flag = 1;
            else 
                flag = 0;
        }
        else 
            flag = 0;


        if (flag)
        {
            arrPtr[parent] = arrPtr[lChild];
            parent = lChild;
            lChild = parent * 2, rChild = parent * 2 + 1;
        }
        else
        {
            arrPtr[parent] = arrPtr[rChild];
            parent = rChild;
            lChild = parent * 2, rChild = parent * 2 + 1;
        }

        if (parent > size || lChild > size || rChild > size)
            break;

    } while (arrPtr[lChild].count != -9999 || arrPtr[rChild].count != -9999);

    arrPtr[parent].count = -9999;
    arrPtr[parent].course = NULL;
    index--;
    return temp;
}

void binary_Heap::returnList(LinkedList *obj)
{
    Course *temp = getMax();
    while(!isEmpty())
    {
        if (temp != NULL)
        {
            obj->insert(temp);
        }
        temp = getMax();
    }
}

bool binary_Heap::isEmpty()
{
    return index == 0;
}

void binary_Heap::insert(Course *obj, float parameter)
{
    if (isFull())
        increaseCapacity();

    int child = ++index;
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
}   