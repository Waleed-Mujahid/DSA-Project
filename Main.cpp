#include <iostream>
#include "datatype.hpp"
#include "AVL_Tree.cpp"
#include "trie.cpp"
#include "functions.cpp"

using namespace std;

int main()
{
    string str;
    searchEngine obj;
    obj.readData();
    cin >> str;
    obj.autoComplete("web f");
    return 0;
}