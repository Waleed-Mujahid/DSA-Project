#include <iostream>
#include "datatype.hpp"
#include "LinkedList.cpp"

int main()
{
    using namespace std;

    LinkedList courses;
    courses.insertFile("udemy_courses.csv");
    courses.printList();
}