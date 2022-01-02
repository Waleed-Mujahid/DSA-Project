#pragma once
#include <iostream>
#include "datatype.hpp"
#include <map>
#include "binary_Heap.cpp"
void CopyFunc(binary_Heap **Obj1, binary_Heap **Obj2, int lim)
{
    for (int i = 0; i < lim; i++)
    {
        Obj2[i] = Obj1[i];
    }
}

class Dictionary
{
public:
    map<string, int> dict;
    void dictInsert(string ins, int *sz, binary_Heap **roots)
    {
        if (dict.find(ins) == dict.end())//searches for the string in the dictionary to avoid repitition 
        {
            cout << "Creating a new key value pair" << endl;
            *sz++;                                         //size incremented
            binary_Heap **rootsN = new binary_Heap *[*sz]; //new hash table of size+1
            CopyFunc(roots, rootsN, *sz - 1);
            dict.insert({ins, *sz}); //inserts new key value pair                                                     //function that copies size-1 elements to hash table
            binary_Heap **roots = new binary_Heap *[*sz];                      //reinitializes current root table
            CopyFunc(roots, rootsN, *sz);                                      //copies content from new table to older one
        }                                                                      //dict.insert({ins, rootsN[*sz]->arrPtr->course->data.Category_id}); //inserts new key value pair

        else
        {
            cout << "Key Value pair already exists" << endl;
        }
    }
};

class Hash_map
{
public:
    LinkedList *l1;
    Dictionary d1;
    int size = 0;                            //used in case more categories are added to the heap(to increase size)
    binary_Heap **roots = new binary_Heap *; //current data set only has 4 categories so it is initialized at that
    Course *sub_root;
    void HashFromFIle() //inserts category ids from file.
    {
        //Waleed, do your thing
    }                       //sub roots are pointers pointing to the heaps that will be found in each category
    void HashFunc(string s) //Hash function which will use dictionaries
    {
        std::cout << "Hashing user input" << endl;
        if (d1.dict.find(s) != d1.dict.end())
        {
            int pos = distance(d1.dict.begin(), d1.dict.find(s));
            roots[pos]->returnList(l1); //points to first value of heap, tho we don't have heap data type yet
            cout<<"Filter results to how many numbers? Enter 0 to print all"<<endl;
            int count;
            cin>>count;
            l1->printList(count,0);
        }
    }
    void deleteHash(string str)
    {
        std::cout << "Hashing user input" << endl;
        if (d1.dict.find(str) != d1.dict.end())
        {
            int pos = distance(d1.dict.begin(), d1.dict.find(str));
            cout<<"Are you sure you want to delete this category entirely?(y/n)"<<endl;
            char dec;
            cin>>dec;
            if(dec=='n')
            return;
            roots[pos]->destroy(roots[pos]->arrPtr);
        }
    }        //deletes a particular hash value, resulting in the deletion of the entire heap belonging to that category
    void inserthash(string s) //to be used when adding new hash maps;
    {
        d1.dictInsert(s, &size, roots);
    }
};
