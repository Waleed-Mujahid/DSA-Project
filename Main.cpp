#include <iostream>
#include "datatype.hpp"
#include "AVL_Tree.cpp"
#include "trie.cpp"
#include "functions.cpp"
#include <chrono>
#include "tempFile.cpp"

using namespace std;

int main()
{
    searchEngine obj;
    obj.readData();
    obj.browseCourses("web");
    return 0;
}

/*
using namespace std::chrono;

int main()
{
    searchEngine obj;
    auto start = high_resolution_clock::now();
    obj.readData();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);


    cout << "Time taken by function: "
         << (float) duration.count() / 1000000 << " seconds" << endl;

}*/