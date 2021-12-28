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
    binary_Heap max_heap;

public:
    searchEngine()
    {
    }
    void readFile(string);
    void searchExactCourse(string);
    void browseCourses(string);
    void searchCategoryWise(string);
    void splitString(string, LinkedList*);
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
    LinkedList *shortList = new LinkedList();
    splitString(str, shortList);
    // Linked list of courses returned, unsorted

    Course *temp = shortList->first;
    while (temp != NULL)
    {
        max_heap.insert(temp, temp->data.counter);
        temp = temp->next;
    }
    shortList->destroy(); // Destroy unsorted list

    // Creates sorted list
    max_heap.returnList(shortList);
    shortList->printList();
    shortList->destroy();
}

void searchEngine::searchCategoryWise(string str)
{

}

void searchEngine::splitString(string str, LinkedList * shortList)
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
