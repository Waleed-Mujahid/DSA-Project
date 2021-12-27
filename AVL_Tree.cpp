#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "datatype.hpp"
#include "trie.cpp"

using namespace std;

bool stack::isEmpty()
{
    return start == NULL;
}

void stack::push(Course *node)
{
    stackNode *NewNode = new stackNode();
    NewNode->ptr = node;
    NewNode->next = start;
    start = NewNode;
    len++;
}

Course *stack::pop()
{
    if (isEmpty())
        return nullptr;

    loc = start;
    Course *value;
    value = start->ptr;
    start = start->next;
    len--;
    delete loc;
    return value;
}

void AVL_Tree::ballanceAVL(Course *current, int depth_difference)
{

    if (depth_difference == 0 || depth_difference == -1 || depth_difference == 1)
        return; // AVL tree is already ballanced

    else if (depth_difference > 1) // Left subtree is more deep than right subtree of CURRENT NODE
    {

        loc = current->LeftChild;
        // Checks if single rotaion required or double
        if (depth_of_tree(loc->RightChild) > depth_of_tree(loc->LeftChild))
            leftRightRotaion(current);
        else
            rightRotation(current);
    }

    else // Right subtree is more deep than left subtree of CURRENT NODE
    {

        loc = current->RightChild;
        // Checks if single rotaion required or double
        if (depth_of_tree(loc->LeftChild) > depth_of_tree(loc->RightChild))
        {
            rightLeftRotaion(current);
        }
        else
        {
            leftRotation(current);
        }
    }
}

void AVL_Tree::leftRightRotaion(Course *x)
{
    leftRotation(x->LeftChild);
    rightRotation(x);
}

void AVL_Tree::rightLeftRotaion(Course *x)
{
    rightRotation(x->RightChild);
    leftRotation(x);
}

void AVL_Tree::leftRotation(Course *x)
{

    search(x); // Search for node X to get its logical predecessor
    Course *y = x->RightChild;

    // Put y in the place of X
    if (ploc == NULL)
        root = y;
    else if (ploc->RightChild == x)
        ploc->RightChild = y;
    else
        ploc->LeftChild = y;

    // Left rotation
    x->RightChild = y->LeftChild;
    y->LeftChild = x;
}

void AVL_Tree::rightRotation(Course *x)
{
    search(x); // Search for node X to get its logical predecessor
    Course *y = x->LeftChild;

    // Put y in the place of X
    if (ploc == NULL)
        root = y;
    else if (ploc->RightChild == x)
        ploc->RightChild = y;
    else
        ploc->LeftChild = y;

    // Right rotation
    x->LeftChild = y->RightChild;
    y->RightChild = x;
}

// Deletes entire BST
void AVL_Tree::destroyTree(Course *current)
{
    if (current != NULL) // Traverses tree in Post order
    {
        destroyTree(current->LeftChild);
        destroyTree(current->RightChild);

        if (current == root) // Root case
            root = NULL;

        current->LeftChild = NULL; // Sets child nodes to null
        current->RightChild = NULL;
        delete current; // Deletes node
    }
}

bool AVL_Tree::IsEmpty()
{
    //Returns true if no node is present(Tree is Empty)
    return root == NULL;
}

void AVL_Tree::searchCourse(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    if (IsEmpty())
        return;

    //Initialize loc and ploc
    ploc = NULL;
    loc = root;
    string temp_Comparison;

    //Traverse Tree to the end node or untill the value is found
    while (loc != NULL && loc->data.name != str)
    {
        ploc = loc;
        temp_Comparison = loc->data.name;

        //If value is greater than the value in current node go to right
        if (str > temp_Comparison)
            loc = loc->RightChild;

        else //Otherwise go to the left
            loc = loc->LeftChild;

    }

    if (loc != NULL)
        loc->PrintCourseData();
    else 
        cout << "Course not found." << endl;
}
void AVL_Tree::search(Course *obj)
{
    string str = obj->data.name;
    if (IsEmpty())
        return;

    //Initialize loc and ploc
    ploc = NULL;
    loc = root;
    string temp_Comparison;
    s.push(loc);

    //Traverse Tree to the end node or untill the value is found
    while (loc != NULL && loc->data.name != str)
    {
        ploc = loc;
        temp_Comparison = loc->data.name;

        //If value is greater than the value in current node go to right
        if (str > temp_Comparison)
            loc = loc->RightChild;

        else //Otherwise go to the left
            loc = loc->LeftChild;

        s.push(loc);
    }
}

void AVL_Tree::Insert(Course *obj)
{
    string str = obj->data.name;
    obj->data.course_id = ++len;

    search(obj); //Search Position for insertion
    //If value is not found then insert value
    if (loc == NULL)
    {
        //If tree is empty
        if (ploc == NULL)
            root = obj; //Newnode is pointed by root

        else
        {
            //Use ploc to insert the value
            if (str > ploc->data.name)
                ploc->RightChild = obj;
            else
                ploc->LeftChild = obj;
        }

        Course *temp = NULL;
        int depth_Diff = 0;

        while (!s.isEmpty())
        {
            temp = s.pop();
            if (temp != NULL)
                depth_Diff = -depth_of_tree(temp->RightChild) + depth_of_tree(temp->LeftChild);

            if (depth_Diff > 1 || depth_Diff < -1)
                break;
        }
        ballanceAVL(temp, depth_Diff);
    }
}

void AVL_Tree::PreOrder(Course *temp)
{

    if (temp == NULL)
    {
        //Base Case
        return;
    }
    //Print node
    temp->PrintCourseData();
    //Go to the left child recursively
    PreOrder(temp->LeftChild);
    //Then go to the right child recursively
    PreOrder(temp->RightChild);
}

void AVL_Tree::InOrder(Course *temp)
{

    if (IsEmpty())
        cout << endl
             << "Tree is empty." << endl;

    if (temp == NULL)
    {
        //Base Case
        return;
    }
    //Go to the left child recursively
    InOrder(temp->LeftChild);
    //Then print node
    temp->PrintCourseData();
    //Then go to the right child recursively
    InOrder(temp->RightChild);
}

void AVL_Tree::PostOrder(Course *temp)
{
    if (temp == NULL)
    {
        //Base Case
        return;
    }
    //Go to the left child recursively
    PostOrder(temp->LeftChild);
    //Then go to the right child recursively
    PostOrder(temp->RightChild);
    //Then print node
    temp->PrintCourseData();
}

int AVL_Tree::height_of_tree(Course *temp)
{
    if (temp == NULL)
    {
        //If traversal goes beyond leaf nodes
        return -1;
    }
    else
    {
        //return 1 + max height of left or right child
        return 1 + max(height_of_tree(temp->LeftChild), height_of_tree(temp->RightChild));
    }
}

int AVL_Tree::depth_of_tree(Course *temp)
{
    if (temp == NULL)
    {
        //If traversal goes beyond leaf nodes
        return -1;
    }
    else
    {
        //return 1 + max height of left or right child
        return 1 + max(depth_of_tree(temp->LeftChild), depth_of_tree(temp->RightChild));
    }
}

void AVL_Tree::deleteNode(Course *obj)
{
    string str = obj->data.name;
    search(obj);
    if (loc != NULL)
    {
        if (loc->LeftChild == NULL && loc->RightChild == NULL)
        {

            if (ploc == NULL)
                root = NULL;
            else if (ploc->LeftChild == loc)
                ploc->LeftChild = NULL;
            else
                ploc->RightChild = NULL;

            delete loc;
        }
        else if (loc->LeftChild == NULL && loc->RightChild != NULL)
        {
            if (ploc == NULL)
                root = loc->RightChild;
            else if (ploc->LeftChild == loc)
                ploc->LeftChild = loc->RightChild;
            else
                ploc->RightChild = loc->RightChild;

            delete loc;
        }
        else if (loc->LeftChild != NULL && loc->RightChild == NULL)
        {
            if (ploc == NULL)
                root = loc->LeftChild;
            else if (ploc->LeftChild == loc)
                ploc->LeftChild = loc->LeftChild;
            else
                ploc->RightChild = loc->LeftChild;

            delete loc;
        }
        else
        {
            Course *tploc = ploc;
            Course *tloc = loc;
            ploc = loc;
            loc = loc->LeftChild;

            while (loc->RightChild != NULL)
            {
                ploc = loc;
                loc = loc->RightChild;
            }

            if (tloc->LeftChild == loc)
                tloc->LeftChild = loc->LeftChild;
            else if (loc->LeftChild == NULL)
                ploc->RightChild = NULL;
            else
                ploc->RightChild = loc->LeftChild;

            loc->LeftChild = tloc->LeftChild;
            loc->RightChild = tloc->RightChild;

            if (tploc == NULL)
                root = loc;
            else if (tploc->LeftChild == tloc)
            {
                tploc->LeftChild = loc;
            }
            else
            {
                tploc->RightChild = loc;
            }
            delete tloc;
        }

        Course *temp = NULL;
        int depth_Diff = 0;
        s.pop(); // Deleted node stored in stack;
        while (!s.isEmpty())
        {
            temp = s.pop();
            if (temp != NULL)
            {
                depth_Diff = depth_of_tree(temp->LeftChild) - depth_of_tree(temp->RightChild);
            }
            if (depth_Diff > 1 || depth_Diff < -1)
                break;
        }
        ballanceAVL(temp, depth_Diff);
    }
    else
    {
        cout << "Value not found. Deleteion can not be done." << endl;
    }
}

int AVL_Tree::indexSubject(std::string str)
{
    if (str.compare("Business Finance"))
        return 1;
    else if (str.compare("Graphic Design"))
        return 2;
    else if (str.compare("Musical Instruments"))
        return 3;
    else if (str.compare("Web Development"))
        return 4;
    else
        return 5;
}

int AVL_Tree::stringToint(std::string str)
{
    int x;
    std::stringstream val(str);
    val >> x;
    return x;
}

int AVL_Tree::indexLevel(std::string str)
{
    if (str.compare("Beginner Level"))
        return 1;
    else if (str.compare("Intermediate Level"))
        return 2;
    else if (str.compare("Expert Level"))
        return 3;
    else
        return 4;
}

void AVL_Tree::insertFile(std::string s)
{
    std::ifstream myFile;
    myFile.open(s);
    string str = "";
    string line, str1, str2;
    int flag;
    while (myFile.good())
    {
        Course *newNode = new Course();
        flag = 1;
        line = "";
        getline(myFile, line, ',');
        for (int i = 0; i < line.length(); i++)
        {
            if (isalnum(line[i]) == 0 && isspace(line[i]) == 0 && ispunct(line[i]) == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
            newNode->data.name = line;
        else
        {
            getline(myFile, line, '\n');
            line = "";
        }
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        newNode->data.name = line;

        getline(myFile, line, ',');
        newNode->data.url = line;

        getline(myFile, line, ',');
        if (line.compare("TRUE"))
            newNode->data.isPaid = true;
        else
            newNode->data.isPaid = false;

        getline(myFile, line, ',');
        newNode->data.price = stringToint(line);

        getline(myFile, line, ',');
        newNode->data.subscribers = stringToint(line);

        getline(myFile, line, ',');
        newNode->data.difficulty_id = indexLevel(line);

        getline(myFile, line, ',');
        newNode->data.duration = stringToint(line);

        getline(myFile, line, ',');
        str1 = line.substr(0, 4);
        newNode->data.publish_year = stringToint(str1);

        getline(myFile, line, '\n');
        newNode->data.Category_id = indexSubject(line);
        Insert(newNode);
    }
}