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
    Trie prefix_tree, tags_Tree;
    stack *st = new stack();
    LinkedList list;
    binary_Heap max_heap;
    void traverseAVL(int, Course *);
    void splitString(string, LinkedList *);

public:
    searchEngine()
    {
    }
    void readData();
    void searchExactCourse(string);
    void browseCourses(string, int);
    void searchCategoryWise(string);
    void printCourses_A_Z();
    void searchFreeCourses();
};

void searchEngine::traverseAVL(int parameter, Course *temp)
{
    if (temp == NULL)
        return;

    traverseAVL(parameter, temp->LeftChild);
    traverseAVL(parameter, temp->RightChild);

    if (temp->data.price == 0 && temp->data.isUdemy)
        max_heap.insert(temp, temp->data.subscribers);
}

void searchEngine::searchFreeCourses()
{
    // Return free courses Max_heap wrt popularity
    traverseAVL(0, tree.root);
    LinkedList *shortList = new LinkedList();
    // Creates sorted list
    max_heap.returnList(shortList);
    shortList->printList(3);
    shortList->destroy();
}

void searchEngine::printCourses_A_Z()
{
    tree.InOrder(tree.root);
}

void searchEngine::readData()
{
    tree.insertUdemyDataset();
    tree.insertCourseraDataset();
    prefix_tree.readAvl(tree.root);
    //tags_Tree.create_Tags_Tree(tree.root);
    list.insertFile("udemy_courses.csv");
}

void searchEngine::searchExactCourse(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    tree.searchCourse(str);
}

void searchEngine::browseCourses(string str, int count = 2)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    LinkedList *shortList = new LinkedList();
    splitString(str, shortList);
    // Linked list of courses returned, unsorted

    // Binary heap used for sorting
    Course *temp = shortList->first;
    while (temp != NULL)
    {
        max_heap.insert(temp, temp->data.counter);
        temp = temp->next;
    }
    
    shortList->destroy(); // Destroy unsorted list

    // Creates sorted list
    max_heap.returnList(shortList);
    shortList->printList(count);
    shortList->destroy();
}

<<<<<<< HEAD
void searchEngine::searchCategoryWise(string str)
{
}

void searchEngine::splitString(string str, LinkedList *shortList)
=======
void searchEngine::splitString(string str, LinkedList * shortList)
>>>>>>> ed8cef12d5f19343642f2571b3c62ec55ca95f3f
{
    char ch;
    string subString = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        ch = str[i];
        if (isspace(ch))
        {
            prefix_tree.search(subString, shortList);
            //tags_Tree.search(subString, shortList);
            subString = "";
            continue;
        }

        subString = subString + ch;
    }
    prefix_tree.search(subString, shortList);
    //tags_Tree.search(subString, shortList);
}

