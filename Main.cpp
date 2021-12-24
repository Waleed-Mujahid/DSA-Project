#include <iostream>
#include "datatype.hpp"
#include "AVL_Tree.cpp"

using namespace std;

int main()
{
    AVL_Tree tree;
    tree.insertFile("udemy_Courses.csv");
    tree.InOrder(tree.root);
}
