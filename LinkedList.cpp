#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "datatype.hpp"

LinkedList::LinkedList()
{
    first = NULL;
    last = NULL;
    loc = NULL;
    ploc = NULL;
    length = 0;
}
bool LinkedList::isEmpty()
{
    return first == NULL;
}
void LinkedList::printList(int numOfTimes, int val)
{
    int x = 0;
    Course *temp = first;
    if (isEmpty())
    {
        cout << "No results found."<< endl;
        return;
    }

    if (numOfTimes == 0)
    {
        while (temp->next != NULL)
        {
            if (val == 0)
                temp->PrintCourseData();
            else
                cout << temp->data.name << endl;
            temp = temp->next;
        }
    }
    else
    {
        for (size_t i = 0; i < numOfTimes && temp != NULL; i++)
        {
            if (val == 0)
                temp->PrintCourseData();
            else
                cout << temp->data.name << endl;;
            temp = temp->next;
        }
    }
    cout << endl;
}

void LinkedList::SearchList(std::string value)
{
    loc = first;
    ploc = NULL;
    while (loc != NULL && loc->data.name.compare(value))
    {
        ploc = loc;
        loc = loc->next;
    }
    if (loc != NULL && loc->data.name != value)
    {
        loc = NULL;
    }
}
void LinkedList::insertFront()
{
    Course *newCourse = new Course;
    newCourse->InsertUserCourseData();
    if (isEmpty())
    {
        first = newCourse;
        last = newCourse;
        newCourse->next = NULL;
    }
    else
    {
        newCourse->next = first;
        first = newCourse;
    }
    length++;
}

void LinkedList::insertFront(Course *obj)
{
    Course *newCourse = new Course;
    newCourse->data = obj->data;
    if (isEmpty())
    {
        first = newCourse;
        last = newCourse;
        newCourse->next = NULL;
    }
    else
    {
        newCourse->next = first;
        first = newCourse;
    }
}

void LinkedList::insert(Course *obj)
{
    Course *newCourse = new Course();
    newCourse->data = obj->data;
    SearchList(newCourse->data.name);

    if (loc == NULL)
    {
        if (isEmpty())
        {
            first = newCourse;
            last = newCourse;
        }
        else
        {
            last->next = newCourse;
            last = newCourse;
        }
    }
    else
    {
        loc->data.counter++;
    }
    length++;
}

void LinkedList::insertNewNode(Course *obj)
{
    Course *newCourse = new Course;
    string val = obj->data.name;
    SearchList(val);
    if (loc == NULL)
    {
        if (ploc == NULL)
            insertFront();
        else
        {
            newCourse->next = ploc->next;
            ploc->next = newCourse;
            if (ploc == last)
            {
                last = newCourse;
            }
        }
        length++;
    }
    else
    {
        //loc->counter++;
    }
}

void LinkedList::destroy()
{
    Course *temp = first;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        temp->next = NULL;
    }
    first = NULL;
    last = NULL;
    length = 0;
}
