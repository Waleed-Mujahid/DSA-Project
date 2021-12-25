#include <iostream>
#include "datatype.hpp"
#include "AVL_Tree.cpp"
#include "trie.cpp"
#include <chrono>

using namespace std;

int main()
{
    AVL_Tree udemy_dataset;
    udemy_dataset.insertFile("udemy_courses.csv");
   
    auto start = chrono::high_resolution_clock::now();
    Trie t;
    t.readAvl(udemy_dataset.root);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Trie time complexity: " << (float)duration.count() / 1000000 << " seconds" << endl;
}

// auto start = chrono::high_resolution_clock::now();
// AVL_Tree udemy_dataset;
// udemy_dataset.insertFile("udemy_courses.csv");
// auto stop = chrono::high_resolution_clock::now();
// auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
// cout << "AVL time complexity: " << (float)duration.count() / 1000000 << " seconds" << endl;
