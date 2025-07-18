#include <iostream>
#include<list>
#include <string>
#include<cctype>
#include<fstream>
#include "todo.h"

using namespace std;

int main(){
    list<Tasks> taskList;  
    system("cls");
    LoadTasks(taskList,"tasks.json");
    bool running = true;
    int choice;

    do{
    cout<< "====== TO-DO LIST ======"<<endl;
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
        system("cls");
            if(taskList.size()==0){
                cout<<"No tasks have been added.";
                system("pause");
                break;
            }
            cout<<"==============Tasks list=============="<<endl;
            showList(taskList);
            cout<<"======================================"<<endl;
            system("pause");
            break;

        case 2:
            system("cls");
            if(AddTask(taskList)){
                cout<<"Task added suscefully!"<<endl;
                system("pause");
                break;
            }else{
                cout<<"ERROR!"<<endl;
                system("pause");
                break;
            }
        case 3:
            system("cls");
            cout<<"==============Tasks list=============="<<endl;
            showList(taskList);
            cout<<"======================================"<<endl;
            EditTask(taskList);
            system("pause");
            break;

        case 4:
            system("cls");
            cout<<"==============Tasks list=============="<<endl;
            showList(taskList);
            cout<<"======================================"<<endl;
            CompleteTask(taskList);
            system("pause");
            break;

        case 5:
            system("cls");
            cout<<"==============Tasks list=============="<<endl;
            showList(taskList);
            cout<<"======================================"<<endl;
            RemoveTask(taskList);
            system("pause");
            break;

        case 6:
            system("cls");
            SaveTasks(taskList,"tasks.json");
            cout<<"Tasks saved sucsefully.";
            cout<<"\nGoodbye.";
            system("pause");
            running=false;
            


            
    }
        

 }while(running);
 return 0;
}