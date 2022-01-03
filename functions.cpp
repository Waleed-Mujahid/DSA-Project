#pragma once
#include <iostream>
#include "datatype.hpp"
#include "trie.cpp"
#include "binary_Heap.cpp"
#include "LinkedList.cpp"
#include <string>
#include <algorithm>
#include "tempFile.cpp"
#include "Hash.cpp"
class searchEngine
{
    AVL_Tree tree;
    LinkedList list;
    binary_Heap max_heap;
    Trie prefix_tree, autoTree;
    Hash_map map;
    void traverseAVL(int, Course *);
    void splitString(string, LinkedList *);

public:
    searchEngine()
    {
    }
    void readData();
    void searchExactCourse();
    void browseCourses(string, int, int);
    void autoComplete();
    void printCourses_A_Z();
    void searchFreeCourses(int);
    void readAvl(Course *);
    string returnInput();
    void searchCategoryWise();
};

void searchEngine::searchCategoryWise()
{
    string str = returnInput();
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    map.searchMap(str);
}

void searchEngine::readAvl(Course *obj)
{

    if (obj == NULL)
    {
        //Base Case
        return;
    }

    prefix_tree.splitString(obj->data.name, obj);
    autoTree.splitStringTwo(obj->data.name, obj);
    if (obj->data.isUdemy)
    {
        map.inserthash(obj->data.Category_id, obj);
        map.inserthash(obj->data.Category_id, obj);
    }
    readAvl(obj->LeftChild);
    readAvl(obj->RightChild);
}

string searchEngine::returnInput()
{
    int i = 0;
    char c;
    char str[100];
    cout << "Please search for your course:" << endl;
    do
    {
        c = getchar();
        str[i] = c;
        i++;
    } while (c != '\n');

    return str;
}

void searchEngine::traverseAVL(int parameter, Course *temp)
{
    if (temp == NULL)
        return;

    traverseAVL(parameter, temp->LeftChild);
    traverseAVL(parameter, temp->RightChild);

    if (temp->data.price == 0) // Inserts course only if it is free
        max_heap.insert(temp, temp->data.rating);
}

void searchEngine::searchFreeCourses(int count = 0)
{
    // Return free courses Max_heap wrt popularity
    traverseAVL(0, tree.root);
    LinkedList *shortList = new LinkedList();

    // Creates sorted list
    max_heap.returnList(shortList);
    shortList->printList(count, 0);
    shortList->destroy();
}

void searchEngine::printCourses_A_Z()
{
    // Traverse AVL alphabetically
    tree.InOrder(tree.root);
}

void searchEngine::readData()
{
    tree.insertUdemyDataset();    // Read data fom udemy.csv
    tree.insertCourseraDataset(); // Read data frin Coursera.csv
    readAvl(tree.root);           // Initialize Trie and Map with AVL tree
    //prefix_tree.readAvl(tree.root);
}

void searchEngine::searchExactCourse()
{
    string str = returnInput();
    // All courses are stored in lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    tree.searchCourse(str);
}

void searchEngine::browseCourses(string str, int count = 2, int val = 0)
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
    shortList->printList(count, val);
    shortList->destroy();
}

void searchEngine::autoComplete()
{
    string str = returnInput();

    cout << "Possible suggestions are : " << endl
         << endl;

    int flag = 1;
    size_t i = 0;
    for (; i < str.length(); i++)
    {
        if (str[i] == '\n') // Remove end line
        {
            str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
            break;
        }
        if (isspace(str[i]))
            flag = 0;
    }

    if (flag) // Single word autocomplete
    {
        prefix_tree.autoCompleteFunc(str.substr(0, i), flag);
        flag = 0;
    }
    else // Multiple words autocomplete
        flag = autoTree.autoCompleteFunc(str, flag);

    if (flag) // If above both returns NULL search again using other TRIE
        browseCourses(str, 3, 1);
}

void searchEngine::splitString(string str, LinkedList *shortList)
{
    // Splits a string at empty spaces
    // Used to search each word induvidually
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
