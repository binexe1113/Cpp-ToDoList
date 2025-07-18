#include <iostream>
#include<list>
#include <string>
#include<cctype>
#include "todo.h"

using namespace std;

int main(){
    list<Tasks> taskList;  
    bool running = true;
    int choice;

    do{
    cout<< "=== TO-DO LIST ==="<<endl;
    cout<<"1. View Tasks"<<endl;   
    cout<<"2. Add Task"<<endl;   
    cout<<"3. Edit Task"<<endl;   
    cout<<"4. Complete Task"<<endl;   
    cout<<"5. Delete Task"<<endl;   
    cout<<"6. Exit"<<endl;
    cout<<"Enter your choice: ";
    choice = ChoiceValidator();
    switch (choice){
        case 1:
            if(taskList.size()==0){
                cout<<"No tasks have been added.";
                system("pause");
                break;
            }
            for (const auto& task : taskList) {
                cout << "ID: " << task.id << ", Date: " << task.date << ", Description: " << task.description << endl;
                break;
            }
        case 2:
            if(AddTask(taskList)){
                cout<<"Task added suscefully!"<<endl;
            }else{
                cout<<"ERROR!"<<endl;
            }
            
    }
        

 }while(running);
}