#pragma once
#include <iostream>
#include "datatype.hpp"
#include <map>

void CopyFunc(Course **Obj1, Course **Obj2, int lim)
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
    void dictInsert(string ins, int *sz, Course **roots)
    {
        if (dict.find(ins) == dict.end())
        {
            cout << "Creating a new key value pair" << endl;
            *sz++;//size incremented
            Course **rootsN = new Course *[*sz];//new hash table of size+1
            CopyFunc(roots, rootsN, *sz - 1);//function that copies size-1 elements to hash table
            dict.insert({ins, rootsN[*sz]->data.Category_id});//inserts new key value pair
            Course **roots = new Course *[*sz];//reinitializes current root table
            CopyFunc(roots, rootsN, *sz);//copies content from new table to older one
        }
        else
        {
            cout << "Key Value pair already exists" << endl;
        }
    }
};

class Hash_map
{
public:
    Dictionary d1;
    int size = 4;                     //used in case more categories are added to the heap(to increase size)
    Course **roots = new Course *[4]; //current data set only has 4 categories so it is initialized at that
    Course *sub_root;  
    void HashFromFIle()
    {
        
    }               //sub roots are pointers pointing to the heaps that will be found in each category
    void HashFunc(string s)           //Hash function which will use dictionaries
    {

    }
    void deleteHash();        //deletes a particular hash value, resulting in the deletion of the entire heap belonging to that category
    void inserthash(string s) //to be used when adding new hash maps;
    {
        d1.dictInsert(s, &size, roots);
    }
};