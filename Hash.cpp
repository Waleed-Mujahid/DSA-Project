#pragma once
#include <cstring>
#include <iostream>
#include "datatype.hpp"

//#include "binary_Heap.cpp"
#include "tempfile.cpp"
using namespace std;

class Hash_map
{
public:
    LinkedList *l1;
    int size = 5;   //used in case more categories are added to the heap(to increase size)
    Heap *hashPtr;  //for udemy courses
    Heap *hashPtr2; //for coursera courses
    Hash_map()
    {
        hashPtr = new Heap[size];
        hashPtr2 = new Heap[100];
    }
    int HashFunc(string str) //Hash function for udemy data set
    {
        if (str.compare("business finance") == 0)
            return 1;   
        else if (str.compare("graphic design") == 0)
            return 2;
        else if (str.compare("musical instruments") == 0)
            return 3;
        else if (str.compare("web development") == 0)
            return 4;
        else
            return 5;
    }
    int HashFuncC(string str) //Hash function for coursera
    {
        int ascii = 0;
        int length = 0;
        char c;
        size_t i = 0;
        for (; i < str.length(); i++)
        {
            if(isspace(str[i]))
                break;
        }
        length = i;

        for (int i = 0; i < length; i++)
        {
            ascii = ascii += (int)str[i];
        }
        int hashval = ascii % 100;
        return hashval;
    }
    void inserthash(int index, Course *obj) //to be used when adding new hash maps;
    {
        hashPtr[index - 1].insert(obj, obj->data.rating);
    }
    void inserthash2(int index, Course *obj) //to be used when adding new hash maps;
    {
        hashPtr2[index].insert(obj, obj->data.rating);
    }

    void searchMap(string str) //searchesudemy courses
    {
        int index = HashFunc(str);
        LinkedList *newList = new LinkedList();
        hashPtr[index - 1].returnList(newList);
        cout << "Display first how many results?(Press 0 if you wish to display all)" << endl;
        int count = 0;
        cin >> count;
        newList->printList(count, 0);
    }
    void searchMapC(string str) //searches coursera courses
    {
        int index = HashFuncC(str);
        string str1  = hashPtr2[index].root->node->data.tags[0];
        size_t i = 0;
        for (; i < str.length(); i++)
        {
            if(isspace(str[i]))
                break;
        }
        str1 = str1.substr(0,i);
        transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
        if (str != str1)
        {
            cout << "No results found. Please refine your query." << endl;
            return;
        }

        LinkedList *newList = new LinkedList();
        hashPtr2[index].returnList(newList);
        cout << "Display first how many results?(Press 0 if you wish to display all)" << endl;
        int count = 0;
        cin >> count;
        newList->printList(count, 0);
    }
};