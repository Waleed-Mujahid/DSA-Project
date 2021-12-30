#include <iostream>
#include "datatype.hpp"
#include "AVL_Tree.cpp"
#include "trie.cpp"
#include "functions.cpp"

using namespace std;

int main()
{
    searchEngine obj;
    obj.readData();
    obj.browseCourses("the web",10);
    return 0;
}