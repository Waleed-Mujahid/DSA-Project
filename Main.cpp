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
    obj.autoComplete("ar");
    return 0;
}