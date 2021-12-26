#pragma once
#include <iostream>
#include "avl_tree.cpp"
#include "datatype.hpp"
#include "binary_Heap.cpp"
#include <algorithm>
#include <string>

using namespace std;

class trei_Node
{
public:
    char c;
    bool isWord;
    binary_Heap priority_Q;
    trei_Node *arrayPtr;
    trei_Node()
    {
        c = '\0';
        isWord = false;
    }
};

class Trie
{
public:
    trei_Node *root;
    Trie()
    {
        root = new trei_Node();
        root->arrayPtr = new trei_Node[26];
    }
    void insert(string, Course*);
    bool search(string, Course*);
    void readAvl(Course*);
    string splitString(string);
};

void Trie::insert(string str, Course* obj)
{
    trei_Node *current = root;
    for (size_t i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (isalpha(ch) == 0)
            continue;

        int index = ch - 'a';
        if (current->arrayPtr[index].c == '\0')
        {
            current = &current->arrayPtr[index];
            current->c = ch;
            current->arrayPtr = new trei_Node[26];
        }
        else
            current = &current->arrayPtr[index];

    }
    current->isWord = true;
    current->priority_Q.insert(obj);
}

bool Trie::search(string str, Course* temp)
{
    int index;
    trei_Node *current = root;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]))
            continue;

        index = str[i] - 'a';
        if (current->arrayPtr[index].c == '\0')
            return false;

        current = &current->arrayPtr[index];
    }
    if (current->isWord == true)
    {
        current->priority_Q.printList();
        return true;
    }
    
    return false;
}

void Trie::readAvl(Course* obj)
{
    string str;
    if (obj == NULL)
    {
        //Base Case
        return;
    }
    
    str = splitString( obj->data.name );
    insert(str, obj);

    readAvl(obj->LeftChild);
    readAvl(obj->RightChild);
}

string Trie::splitString(string str)
{
    int flag = -1;
    char ch;
    string subString = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        ch = str[i];
        if (isspace(ch))
            flag++;

        subString = subString + ch;
        if (flag == 1)
            break;        
    }

    return subString;
}
