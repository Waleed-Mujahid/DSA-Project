#pragma once
#include <iostream>
#include "datatype.hpp"
#include "trie.cpp"
#include "binary_Heap.cpp"

class searchEngine
{    
    AVL_Tree tree;
    Trie prefix_tree;
public:
    searchEngine() {}
    void readFile(string);
    void searchExactCourse(string);
    void browseCourses(string);
    void searchCategoryWise(string);
};

void searchEngine::readFile(string str)
{
    tree.insertFile(str);
    prefix_tree.readAvl(tree.root);
}

void searchEngine::searchExactCourse(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    tree.searchCourse(str);
}

void searchEngine::browseCourses(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    prefix_tree.search(str);
}

void searchEngine::searchCategoryWise(string str)
{
    
}