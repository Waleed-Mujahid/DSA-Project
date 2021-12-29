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
    void insert(string, Course *);
    bool search(string, LinkedList*);
    void readAvl(Course *);
    void splitString(string, Course*);
};

void Trie::insert(string str, Course *obj)
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
    current->priority_Q.insert(obj, obj->data.subscribers);
}

bool Trie::search(string str, LinkedList* obj)
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
        current->priority_Q.returnList(obj);
        return true;
    }

    return false;
}

void Trie::readAvl(Course *obj)
{
    string str;
    if (obj == NULL)
    {
        //Base Case
        return;
    }

    splitString(obj->data.name, obj);

    readAvl(obj->LeftChild);
    readAvl(obj->RightChild);
}

void Trie::splitString(string str, Course* obj)
{
    int flag = 0;
    char ch;
    string subString = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        ch = str[i];
        if (isspace(ch))
        {
            insert(subString, obj);
            subString = "";
            continue;
        }

        subString = subString + ch;
    }
}
