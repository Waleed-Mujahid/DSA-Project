#pragma once
#include <iostream>
#include <string>

class Course_data
{
public:
    std::string name;
    std::string url;
    int Category_id;   // using h
    int difficulty_id; // Beginner, advanced etc
    int price;
    int subscribers;
    int course_id;
    int publish_year;
    float duration;
    bool isPaid;
    static int courseCount;
};

int Course_data::courseCount = 0;

class Course
{
public:
    int index;
    Course *next;  //for linked list use
    Course *lrank; //for heap
    Course *rrank;
    Course_data data;
    void PrintCourseData() //function to print the data of the course
    {
        std::cout << "Course_ID: " << data.course_id << std::endl;
        std::cout << "Course title: " << data.name << std::endl;
        std::cout << "Link: " << data.url << std::endl;
        std::cout << "Category_ID: " << data.Category_id << std::endl;
        std::cout << "Price" << data.price << std::endl;
        std::cout << "Number of students enrolled: " << data.subscribers << std::endl;
        std::cout << "Year published: " << data.publish_year << std::endl;
        std::cout << "Hours to complete: " << data.duration << std::endl;
        std::cout << "isPaid: " << data.isPaid << std::endl<< std::endl;
    }
    void InsertUserCourseData() //function to insert the data into the course
    {
        std::cin >> data.name;
        std::cin >> data.url;
        std::cin >> data.Category_id;
        std::cin >> data.price;
        std::cin >> data.subscribers;
        std::cin >> data.course_id;
        std::cin >> data.publish_year;
        std::cin >> data.duration;
        if (data.price != 0)
            data.isPaid == false;
    }
    void InsertFromFile()
    {
    }
};

class LinkedList
{
public:
    Course *first;
    Course *last;
    int length;
    Course *ploc;
    Course *loc;
    LinkedList();
    bool isEmpty();
    void printList();
    void SearchList(std::string); //searches through list linearly
    void insertFront();
    void insertNewNode(std::string);
    void insert(Course *);
    void insertFile(std::string);
    void deleteNode(std::string);
    void destroy(); //basic linked list functionalities
    int indexSubject(std::string);
    int stringToint(std::string);
    int indexLevel(std::string);
};

class Category
{
public:
    int index;
    std::string t_name;
    Course *Tnext;
};

//void CreateResList() //When a word is searched, a smaller linked list
//of the words that are hit in the search will be returned
//{
//}