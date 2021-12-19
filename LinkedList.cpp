#pragma once
#include<iostream>
#include "datatype.hpp"

class LinkedList
{
    Course* first;
    Course* last;
    Course* loc;
    Course* ploc;
    int length;
    LinkedList()
    {
        first=NULL;
        last=NULL;
        loc=NULL;
        ploc=NULL;
        length=0;
    }
    bool isEmpty()
    {
        return length==0;
    }
    void printList()
    {
        int x=0;
        Course* temp=first;
        if(!isEmpty())
        {
            while(temp->next!=NULL)
            {
                temp->PrintCourseData();
                temp=temp->next;
            }
        }
    }
    void SearchList(std::string value)
    {
        loc=first;
        ploc=NULL;
        while(loc!=NULL && loc->data.name>value)
        {
            ploc=loc;
            loc=loc->next;
        }
        if(loc!=NULL && loc->data.name!=value)
        {
            loc=NULL;
        }
    }
    void insertFront()
    {
        Course* newCourse= new Course;
        newCourse->InsertUserCourseData();
        if(isEmpty())
        {
            first=newCourse;
            last=newCourse;
            newCourse->next=NULL;
        }
        else
        {
            newCourse->next=first;
            first=newCourse;
        }
        length++;
    }
    void insert(std::string value)
    {
        Course* newCourse= new Course;
        newCourse->InsertUserCourseData();
        SearchList(value);
        if(loc==NULL)
        {
            if(ploc==NULL)
            insertFront();
            else
            {
                newCourse->next=ploc->next;
                ploc->next=newCourse;
                if (ploc==last)
                {
                    last=newCourse;
                }
            }
            length++;
        }
        else
        {
            std::cout<<"Duplication of courses is not allowed"<<std::endl;
        }
    }
    void insertFile()
    {
        //<<<<<<<<<<<<<<<<<<<<<<<<
        //<<<<<<<<<<<<<<<<<<<<<<<<  code to be inserted here
        //<<<<<<<<<<<<<<<<<<<<<<<< 
    }
    void deleteNode(std::string value)
    {
        if(!isEmpty())
        {
            SearchList(value);
            if(loc!=NULL)
            {
                if(first==last)
                {
                    first=NULL;
                    last=NULL;
                }
                else if(ploc==NULL)
                {
                    first=first->next;
                    delete loc;
                    loc=first;
                }
                else if(loc->next)
                {
                    delete last;
                    last=ploc;
                    last->next=NULL;
                }
                else
                {
                    ploc->next=loc->next;
                    delete loc;
                }
                length--;
            }
            else
            {
                std::cout<<"Value Not Found"<<std::endl;
            }
        }
        else
        std::cout<<"No courses are in the structure"<<std::endl;
    }
    void destroy()
    {
        Course* temp;
        while(first!=NULL)
        {
            temp=first;
            first=first->next;
            delete temp;
        }
        last=NULL;
    }
};