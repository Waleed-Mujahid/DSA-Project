#include <iostream>
#include <string>


class Category
{
public:
    int index;
    std::string t_name;
    Course *Tnext;
};

class Course_data
{
public:
    std::string name;
    std::string url;
    int Category_id; //using h
    int price;
    int subscribers;
    int course_id;
    int publish_year;
    float duration;
    bool isPaid;
};

class Course
{
public:
   
    int index;
    Course *next;  //for linked list use
    Course *lrank; //for heap
    Course *rrank;
    Course_data data;
    void PrintCourseData()//function to print the data of the course
    {
        std::cout<< data.name <<std::endl;
        std::cout<< data.url<<std::endl;
        std::cout<< data.Category_id <<std::endl;
        std::cout<< data.price <<std::endl;
        std::cout<< data.subscribers <<std::endl;
        std::cout<< data.course_id <<std::endl;
        std::cout<< data.publish_year<<std::endl;
        std::cout<< data.duration<<std::endl;
        std::cout<< data.isPaid<<std::endl;
    }
    void InsertUserCourseData()//function to insert the data into the course
    {
        std::cin>>data.name;
        std::cin>>data.url;
        std::cin>>data.Category_id;
        std::cin>>data.price;
        std::cin>>data.subscribers;
        std::cin>>data.course_id;
        std::cin>>data.publish_year;
        std::cin>>data.duration;
        if(data.price!=0)
        data.isPaid==false;
    }
    void InsertFromFile()
    {

    }
};



class LinkedList
{
public:
    Course* first;
    Course* last;
    int length;
    Course* ploc;
    Course* loc;
    LinkedList();
    bool isEmpty();
    void printList();
    void SearchList(std::string);//searches through list linearly
    void insertFront();
    void insert();
    void insertFile();
    void deleteNode();
    void destroy();//basic linked list functionalities
};

void CreateResList()//When a word is searched, a smaller linked list 
//of the words that are hit in the search will be returned
{

}