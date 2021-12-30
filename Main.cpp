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
    //obj.browseCourses("web development",3);
    obj.autoComplete("web de");
    //obj.browseCourses("web");
    return 0;
}