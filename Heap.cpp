#include<iostream>
#include"datatype.hpp"
using namespace std;

class Heap
{
public:
    Course* root;
    Course* ploc;
    Course* loc;
    Course* tploc;
    Course* tloc;
    Heap(){
        root,ploc,loc,tploc,tloc=NULL;
    }
    bool isEmpty()
    {
        return root==NULL;
    }
    void InsertfromFile();
    void UdemyInsert()
    {
        Course* temp= new Course;
        cout<<"Please enter the"<<endl;
        cout<<"Course name";
        cin>>temp->data.name;
        cout<<"\n Course Category";
    }


};