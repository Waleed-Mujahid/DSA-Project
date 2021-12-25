#pragma once
#include <iostream>
#include "avl_tree.cpp"
#include "datatype.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class trei_Node
{
public:
    char c;
    bool isWord;
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
    void insert(string);
    bool search(string);
    void readAvl(Course*);
};

void Trie::insert(string str)
{
    //cout << str << endl;
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
}

bool Trie::search(string str)
{
    int index;
    trei_Node *current = root;
    for (size_t i = 0; i < str.length(); i++)
    {
        index = str[i] - 'a';
        if (current->arrayPtr[index].c == '\0')
            return false;

        current = &current->arrayPtr[index];
    }
    if (current->isWord == true)
        return true;
    
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
    
    insert(obj->data.name.substr(0,10));

    readAvl(obj->LeftChild);
    readAvl(obj->RightChild);
}