#include <iostream>
#include "functions.cpp"


using namespace std;

int main()
{
    searchEngine obj;
    obj.readData();
    obj.autoComplete();
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