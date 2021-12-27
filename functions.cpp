#pragma once
#include <iostream>
#include "datatype.hpp"
#include "trie.cpp"
#include "binary_Heap.cpp"
#include "LinkedList.cpp"
#include <string>
#include <algorithm>

class searchEngine
{    
    AVL_Tree tree;
    Trie prefix_tree;
    stack *st = new stack();
    LinkedList list;
    LinkedList *shortList;
public:
    searchEngine() {
        shortList = new LinkedList();
    }
    void readFile(string);
    void searchExactCourse(string);
    void browseCourses(string);
    void searchCategoryWise(string);
    void splitString(string);
    void searchFreeCourses();
    void printCourseNames();
};

void searchEngine::printCourseNames()
{
    list.printList();
}

void searchEngine::readFile(string str)
{
    tree.insertFile(str);
    prefix_tree.readAvl(tree.root);
    //list.insertFile(str);
}

void searchEngine::searchExactCourse(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    tree.searchCourse(str);
}

void searchEngine::browseCourses(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    splitString(str);
    shortList->printList();
}

void searchEngine::searchCategoryWise(string str)
{

}

void searchEngine::splitString(string str)
{
    char ch;
    string subString = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        ch = str[i];
        if (isspace(ch))
        {
            prefix_tree.search(subString, shortList);
            subString = "";
            continue;
        }

        subString = subString + ch;
    }
    prefix_tree.search(subString, shortList);
}
