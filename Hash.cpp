#pragma once
#include <iostream>
#include "datatype.hpp"
#include <map>
#include "binary_Heap.cpp"
#include "tempFile.cpp"

class Hash_map
{
public:
    LinkedList *l1;
    int size = 0; //used in case more categories are added to the heap(to increase size)
    Heap *hashPtr;
    Course *sub_root;
    Hash_map()
    {
        hashPtr = new Heap[5];
    }
    int HashFunc(string str) //Hash function which will use dictionaries
    {
        if (str.compare("business finance"))
            return 1;
        else if (str.compare("graphic design"))
            return 2;
        else if (str.compare("musical instruments"))
            return 3;
        else if (str.compare("web development"))
            return 4;
        else
            return 5;
    }

    void deleteHash(string str)
    {

    }                         //deletes a particular hash value, resulting in the deletion of the entire heap belonging to that category
    void inserthash(int index, Course* obj) //to be used when adding new hash maps;
    {
        hashPtr[index - 1].insert(obj, obj->data.rating);
    }

    void searchMap(string str)
    {
        int index = HashFunc(str);
        LinkedList* newList = new LinkedList();
        hashPtr[index - 1].returnList(newList);
        newList->printList(5,0);
    }
};