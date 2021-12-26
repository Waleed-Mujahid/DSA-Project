#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "datatype.hpp"

using namespace std;

class q_Node
{
public:
    int subscribers;
    Course *course;
};

class binary_Heap
{
private:
    q_Node *arrPtr;
    int index, lChild, rChild, parent, size;

public:
    binary_Heap(int SIZE = 10)
    {
        index = 1;
        arrPtr = new q_Node[SIZE];
        size = SIZE;
        for (size_t i = 1; i < size; i++)
            arrPtr[i].subscribers = -9999;
    }
    bool isEmpty();
    bool isFull();
    void insert(Course *);
    void printList();
    Course *getMax();
    void increaseCapacity();
};

void binary_Heap::increaseCapacity()
{
    q_Node *temp = arrPtr;
    q_Node *newArray = new q_Node[2 * size];

    for (size_t i = 1; i < size; i++)
        newArray[i] = arrPtr[i];

    for (size_t i = size; i < size * 2; i++)
        newArray[i].subscribers = -9999;

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
    do
    {

        if (arrPtr[lChild].subscribers > arrPtr[rChild].subscribers)
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

    } while (arrPtr[lChild].subscribers != -9999 || arrPtr[rChild].subscribers != -9999);

    arrPtr[parent].subscribers = -9999;
    arrPtr[parent].course = NULL;
    index--;
    return temp;
}

void binary_Heap::printList()
{
    Course* temp = getMax();
    for (size_t i = 1; i < size; i++)
    {
        if (temp != NULL)
            temp->PrintCourseData();
        temp = getMax();
    }
    puts("");
}

bool binary_Heap::isEmpty()
{
    return index == 0;
}

void binary_Heap::insert(Course *obj)
{
    if (isFull())
        increaseCapacity();

    int child = ++index;
    arrPtr[child].subscribers = obj->data.subscribers;
    arrPtr[child].course = obj;
    parent = child / 2;

    do {        
        if (arrPtr[child].subscribers > arrPtr[parent].subscribers)
            swap( arrPtr[child], arrPtr[parent]);

        child = parent;
        parent = child / 2;
    } while (parent >= 1);

}