#include <iostream>
#include "datatype.hpp"
#include "AVL_Tree.cpp"
#include "trie.cpp"
#include "functions.cpp"
#include <chrono>
#include "tempFile.cpp"

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

}
    /*
    int i = 0;
    char c;
    char str[100];
    cout << "Please search for your course:" << endl;
    do
    {
        c = getchar();
        str[i] = c;
        i++;
    } while (c != '\n');
    
    obj.autoComplete(str);
    return 0;
}
*/