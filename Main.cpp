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
    obj.readFile("udemy_courses.csv");
    //obj.searchExactCourse("mortgage acceleration");
    obj.browseCourses("forex trading");
}