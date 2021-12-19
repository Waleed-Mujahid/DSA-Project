#include <iostream>
#include <string>

class Category
{
public:
    int index;
    std::string t_name;
    Course *Tnext;
};


class Course
{
public:
    std::string name;
    std::string url;
    int index;
    Course *next;  //for linked list use
    Course *lrank; //for heap
    Course *rrank;
    int Category_id; //using h
    float rating;
    int price;
    int subscribers;
    int course_id;
    int publish_year;
    float duration;
};

int main()
{
    using namespace std;
}