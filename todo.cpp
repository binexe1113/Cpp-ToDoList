#include <iostream>
#include<list>
#include <string>
#include<cctype>
#include<fstream>
#include<iomanip>
#include "todo.h"

using namespace std;

int ChoiceValidator(){
    string line;
    bool isValid = false;

    do{ 
    bool isAllDigits = true;
    getline(cin,line);
    if (line.size()==0){
        cout<<"Please enter a number";
        continue; 
    }
    for (int i =0;i<line.size();i++){
        if (isdigit(line[i]) == false){
            cout<< "Please enter only numbers between 1 and 6"<<endl;
            isAllDigits=false;
            break;
        }
    }
        if(isAllDigits==true){
            if(stoi(line)>6){
                cout<<"Please enter a number between 1 and 6"<<endl;
                continue;
            }
        }else{
            continue;
        }

        isValid=true;
    
    }while(isValid == false);
    return stoi(line);
    
}

bool AddTask(list<Tasks>& taskList) {
    string date, description;

    cout << "Enter the task's end date (e.g. 2025-07-17): ";
    getline(cin, date);

    cout << "Enter the task description: ";
    getline(cin, description);

    Tasks newTask(date, description);

    // Find correct insertion point
    auto it = taskList.begin();
    while (it != taskList.end() && it->date < newTask.date) {
        ++it;
    }

    taskList.insert(it, newTask);

    cout << "Task added in order by date.\n";
    return true;
}

void showList(list<Tasks>& taskList){
        for(auto i = taskList.begin(); i != taskList.end();i++){
            cout << "ID: " << i->id << ", Date: " << i->date << ", Description: " << i->description << endl;
            
            }
        }
    

void EditTask(list<Tasks>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks to edit.\n";
        return;
    }

    int editId;
    cout << "Enter the ID of the task to edit: ";
    cin >> editId;
    cin.ignore(); // discard newline

    for (auto& task : taskList) {
        if (task.id == editId) {
            string newDate, newDescription;

            cout << "Current Date: " << task.date << "\n";
            cout << "Enter new date (or press Enter to keep current): ";
            getline(cin, newDate);
            if (!newDate.empty()) {
                task.date = newDate;
            }

            cout << "Current Description: " << task.description << "\n";
            cout << "Enter new description (or press Enter to keep current): ";
            getline(cin, newDescription);
            if (!newDescription.empty()) {
                task.description = newDescription;
            }

            cout << "Task updated successfully.\n";
            return;
        }
    }

    cout << "Task with ID " << editId << " not found.\n";
}

void RemoveTask(list<Tasks>& taskList){
     if (taskList.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }
    int inputID;
    cout<<("Entere the ID of the task to remove: ");
    cin>>inputID;

    for(auto i = taskList.begin(); i != taskList.end();i++){
        if(i->id==inputID){
            taskList.erase(i);
            cout<<"Task removed suscefully"<<endl;
            return;
        }
    }
    cout<<"Task with ID: "<<inputID<< "Not found"<<endl;

} 

void CompleteTask(list<Tasks>& taskList){
     if (taskList.empty()) {
        cout << "No tasks to complete.\n";
        return;
    }
    int inputID;
    cout<<("Entere the ID of the task you completed: ");
    cin>>inputID;

    for(auto i = taskList.begin(); i != taskList.end();i++){
        if(i->id==inputID){
            taskList.erase(i);
            cout<<"Task removed suscefully"<<endl;
            return;
        }
    }
    cout<<"Task with ID: "<<inputID<< "Not found"<<endl;

} 

void SaveTasks(const list<Tasks>& taskList, const string& filename ) {
    json j = taskList;
    ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4); // pretty print
        file.close();
        cout << "Tasks saved to file.\n";
    } else {
        cerr << "Failed to open file for writing.\n";
    }
}

void LoadTasks(list<Tasks>& taskList, const string& filename ) {
    ifstream file(filename);
    if (file.is_open()) {
        json j;
        file >> j;
        file.close();
        taskList = j.get<list<Tasks>>();
        cout << "Tasks loaded from file.\n";
    } else {
        cerr << "File not found or failed to open.\n";
    }
}
