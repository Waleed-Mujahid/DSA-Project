#pragma once
#include <iostream>
#include<chrono>
#include "datatype.hpp"
#include "trie.cpp"
//#include "binary_Heap.cpp"
#include "LinkedList.cpp"
#include <string>
#include <algorithm>
#include <chrono>
#include "tempFile.cpp"
#include "Hash.cpp"


class searchEngine
{
    AVL_Tree tree;
    LinkedList list;
    Heap *max_heap;
    Trie prefix_tree, autoTree;
    Hash_map map;
    void traverseAVL(int, Course *);
    void splitString(string, LinkedList *);

public:
    searchEngine()
    {
        max_heap = new Heap();
    }
    void readData();
    void searchExactCourse();
    void browseCourses(int, int);
    void autoComplete();
    void printCourses_A_Z();
    void searchFreeCourses(int, int);
    void readAvl(Course *);
    string returnInput();
    void searchCategoryWise();
};

void searchEngine::searchCategoryWise()
{
    string str = returnInput();
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '\n') // Remove end line
        {
            str = str.substr(0, (int)str.length() - 1);
            break;
        }
    }

    cout << endl
         << "Following courses are from : " << str << endl;
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    auto start = std::chrono::high_resolution_clock::now();

    map.searchMapC(str);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Time taken by function: " << (float)duration.count() / 1000000 << " seconds" << endl;
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
    else
    {
        string str = obj->data.tags[0];
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        map.inserthash2(map.HashFuncC(str), obj);

        str = obj->data.tags[0];
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        map.inserthash2(map.HashFuncC(str), obj);
    }
    readAvl(obj->LeftChild);
    readAvl(obj->RightChild);
}

string searchEngine::returnInput()
{
    cin.sync();
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

    if (temp->data.price == 0 && temp->data.isUdemy) // Inserts course only if it is free
        max_heap->insert(temp, temp->data.rating);

    traverseAVL(parameter, temp->LeftChild);
    traverseAVL(parameter, temp->RightChild);
}

void searchEngine::searchFreeCourses(int count = 0, int val = 0)
{
    auto start = std::chrono::high_resolution_clock::now();

    // Return free courses Max_heap wrt popularity
    traverseAVL(0, tree.root);
    LinkedList *shortList = new LinkedList();
    auto t1 = std::chrono::high_resolution_clock::now();
    // Creates sorted list
    max_heap->returnList(shortList);
    shortList->printList(count, val);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    shortList->destroy();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Time taken by function: " << (float)duration.count() / 1000000 << " seconds" << endl;
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
}

void searchEngine::searchExactCourse()
{

    string str = returnInput();
    str = str.substr(0, (int)str.length() - 1);
    cout << endl;
    string str = returnInput();
    auto start = std::chrono::high_resolution_clock::now();

    LinkedList *shortList = new LinkedList();
    Heap *tempHeap = new Heap();
    splitString(str, shortList);
    // Linked list of courses returned, unsorted
    // Binary heap used for sorting
    Course *temp = shortList->first;
    while (temp != NULL)
    {
        tempHeap->insert(temp, temp->data.counter);
        temp = temp->next;
    }

    shortList->destroy(); // Destroy unsorted list
    // Creates sorted list
    tempHeap->returnList(shortList);
    shortList->printList(3, 1);
    tree.searchCourse(str);
    shortList->destroy();
    free(tempHeap);
    
}

void searchEngine::autoComplete()
{
    string str = returnInput();
    cout << endl;
    auto start = std::chrono::high_resolution_clock::now();

    int flag = 1;
    size_t i = 0;
    auto t1 = std::chrono::high_resolution_clock::now();
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

    cout << "Possible suggestions for : " << str << " are:" << endl
         << endl;

    if (flag) // Single word autocomplete
    {
        prefix_tree.autoCompleteFunc(str.substr(0, i), flag);
        flag = 0;
    }
    else // Multiple words autocomplete
        flag = autoTree.autoCompleteFunc(str, flag);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Time taken by function: " << (float)duration.count() / 1000000 << " seconds" << endl;
    if (flag) // If above both returns NULL search again using other TRIE
        cout << "No results found. Please refine your search." << endl;
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    cout<<"Time taken for this is "<< duration.count()<<endl;
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
