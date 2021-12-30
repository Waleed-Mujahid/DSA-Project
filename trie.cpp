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
    void readAvl(Course *, int);
    void splitString(string, Course *);
    void splitStringTwo(string, Course *);
    int check(string);
    int autoCompleteFunc(string, int);
    bool isLastNode(trei_Node *);
    int recursiveAutoCmp(string, trei_Node *, int);
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

int Trie::autoCompleteFunc(string str, int val)
{
    int index;
    trei_Node *current = root;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]))
            continue;

        index = str[i] - 'a';
        if (current->arrayPtr[index].c == '\0')
            return 1;
        current = &current->arrayPtr[index];
    }
    return recursiveAutoCmp(str, current, val);
}

int Trie::recursiveAutoCmp(string str, trei_Node *current, int val)
{
    if (isLastNode(current))
    {
        if (val == 0)
        {
            LinkedList *list = new LinkedList();
            current->priority_Q.returnList(list);
            list->printList(2, 1);
            if (list->isEmpty())
                return 1;
        }
        else
        {
            cout << str + autocomplete << endl;
            autocomplete = "";
        }
        return 0;
    }

    for (size_t i = 0; i < 26; i++)
    {
        if (current->arrayPtr[i].c != '\0')
        {
            autocomplete = autocomplete + current->arrayPtr[i].c;
            recursiveAutoCmp(str, &current->arrayPtr[i], val);
        }
    }
}

void Trie::readAvl(Course *obj, int val = 0)
{

    if (obj == NULL)
    {
        //Base Case
        return;
    }

    if (val == 0)
        splitString(obj->data.name, obj);
    else
        splitStringTwo(obj->data.name, obj);

    readAvl(obj->LeftChild, val);
    readAvl(obj->RightChild, val);
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

void Trie::splitStringTwo(string str, Course *obj)
{

    int flag = -1;
    char ch;
    string subString = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        ch = str[i];
        if (isspace(ch))
        {
            flag++;
            continue;
        }

        subString = subString + ch;
    }
    insert(subString, obj);
}
