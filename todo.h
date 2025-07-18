#include <iostream>
#include<list>
#include <string>
#include<cctype>
using namespace std;

class Tasks{
    private:
        inline static int nextId = 1;
    public:
        string date;
        string description;
        int id;

        Tasks(string& userDate, string& userDescription):
            id(nextId++),date(userDate),description(userDescription){}
        void displayTask(){
            cout<<"ID: "<<id;
            cout<<"| End Date: "<<date;
            cout<<"| Description: "<<description<<endl;
        }
};

int ChoiceValidator();

bool AddTask(list<Tasks>& taskList);

void showList(list<Tasks>& taskList);

void EditTask(list<Tasks>& taskList);

void CompleteTask(list<Tasks>& tasklist);

void RemoveTask(list<Tasks>& tasklist);

