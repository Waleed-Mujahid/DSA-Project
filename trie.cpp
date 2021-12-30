#pragma once
#include <iostream>
#include "avl_tree.cpp"
#include "datatype.hpp"
#include "binary_Heap.cpp"

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
    string autocomplete;
    Trie()
    {
        autocomplete = "";
        root = new trei_Node();
        root->arrayPtr = new trei_Node[26];
    }

    void insert(string, Course *);
    bool search(string, LinkedList *);
    void readAvl(Course *);
    void splitString(string, Course *);
    void create_Tags_Tree(Course *);
    int check(string);
    void autoCompleteFunc(string);
    bool isLastNode(trei_Node *);
    void recursiveAutoCmp(string, trei_Node *);
};

bool Trie::isLastNode(trei_Node *root)
{
    for (int i = 0; i < 26; i++)
        if (root->arrayPtr[i].c != '\0')
            return 0;
    return 1;
}


int Trie::check(string str)
{
    int flag = 1;
    string array[5] = {"the", "for", "in", "and", "at"};
    for (size_t i = 0; i < 5; i++)
    {
        if (array[i] == str)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

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
    if (check(str))
    {
        current->priority_Q.insert(obj, obj->data.rating);
    }
}

bool Trie::search(string str, LinkedList *obj)
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

// introd
void Trie::autoCompleteFunc(string str)
{
    int index;
    trei_Node *current = root;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]))
            continue;

        index = str[i] - 'a';
        if (current->arrayPtr[index].c == '\0')
            return;
        current = &current->arrayPtr[index];
    }
    recursiveAutoCmp(str, current);
}

void Trie::recursiveAutoCmp(string str, trei_Node *current)
{
    if (isLastNode(current))
    {
        cout << str + autocomplete << endl;
        autocomplete = "";
        return;
    }

    for (size_t i = 0; i < 26; i++)
    {
        if (current->arrayPtr[i].c != '\0')
        {
            autocomplete = autocomplete + current->arrayPtr[i].c;
            recursiveAutoCmp(str, &current->arrayPtr[i]);
        }
    }
}

void Trie::create_Tags_Tree(Course *obj)
{
    if (obj == NULL)
    {
        //Base Case
        return;
    }

    create_Tags_Tree(obj->LeftChild);
    create_Tags_Tree(obj->RightChild);

    if (obj->data.isUdemy == 0)
    {
        splitString(obj->data.tags[0], obj);
        splitString(obj->data.tags[1], obj);
    }
}

void Trie::readAvl(Course *obj)
{

    if (obj == NULL)
    {
        //Base Case
        return;
    }

    splitString(obj->data.name, obj);
    if (obj->data.isUdemy == 0)
    {
        //splitString(obj->data.tags[0], obj);
        //splitString(obj->data.tags[1], obj);
    }

    readAvl(obj->LeftChild);
    readAvl(obj->RightChild);
}

void Trie::splitString(string str, Course *obj)
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
