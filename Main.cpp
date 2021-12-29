#include <iostream>
#include "datatype.hpp"
#include "AVL_Tree.cpp"
#include "trie.cpp"
#include "functions.cpp"
#include <chrono>

using namespace std;

int main()
{
    searchEngine obj;
    obj.readData();
    obj.searchFreeCourses();
}