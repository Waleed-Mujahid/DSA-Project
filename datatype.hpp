#pragma once
#include <iostream>
#include <string>

// Creates various data types used to Implement AVL trees for our Dataset
// Course_Data stores all the data of one Course
// Course is a node which contains data and next pointer
// AVL trees are used to store Courses
// Stack is used to balance avl trees
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
};

class Course
{
public:
    int index;
    Course* next;  //for linked list use
    Course* lrank; //for heap
    Course* rrank;
    Course_data data;
    Course* LeftChild;
    Course* RightChild;
    void PrintCourseData() //function to print the data of the course
    {
        std::cout << "Course_ID: " << data.course_id << std::endl;
        std::cout << "Course title: " << data.name << std::endl;
        std::cout << "Link: " << data.url << std::endl;
        std::cout << "Category_ID: " << data.Category_id << std::endl;
        std::cout << "Price: " << data.price << std::endl;
        std::cout << "Number of students enrolled: " << data.subscribers << std::endl;
        std::cout << "Year published: " << data.publish_year << std::endl;
        std::cout << "Hours to complete: " << data.duration << std::endl;
        std::cout << "isPaid: " << data.isPaid << std::endl << std::endl;
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
    void SearchList(std::string); //searches through list linearly
    void insertFront();
    void insertNewNode(std::string);
    void insert(Course*);
    void deleteNode(std::string);
    void destroy(); //basic linked list functionalities
    int indexSubject(std::string);
    int stringToint(std::string);
    int indexLevel(std::string);
    void insertFile(std::string);
};

class stackNode // node to implement Stack datastructure
{
public:
    Course* ptr;
    stackNode* next;
    stackNode()
    {
        ptr = NULL;
        next = NULL;
    }
};

class stack
{
public:
    stackNode* start;
    stackNode* loc;
    stack()
    {
        start = NULL;
        loc = NULL;
    }

    bool isEmpty();
    Course* pop();
    void push(Course*);
};

class AVL_Tree
{
public:
    stack s; // Used to ballance AVL
    Course* root;
    Course* loc;
    Course* ploc;
    int len;
    AVL_Tree()
    {
        len = 0;
        root = NULL;
        loc = NULL;
        ploc = NULL;
    }
    bool IsEmpty();
    void search(Course*);
    void Insert(Course*);
    void PreOrder(Course*);
    void InOrder(Course*);
    void PostOrder(Course*);
    int height_of_tree(Course*);
    void destroyTree(Course*);
    void deleteNode(Course*);

    // functions to ballance AVL tree

    void leftRotation(Course*);
    void rightRotation(Course*); // Rotation functions
    void leftRightRotaion(Course*);
    void rightLeftRotaion(Course*);

    int depth_of_tree(Course*); // Returns depth of a node. used for ballancing an AVL tree
    void ballanceAVL(Course*, int);

    // File reading functions
    int indexSubject(string);
    int stringToint(string);
    int indexLevel(string);
    void insertFile(string);
};
