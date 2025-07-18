#include <iostream>
#include<list>
#include <string>
#include<cctype>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

class Tasks {
    private:
        inline static int nextId = 1;
    public:
        string date;
        string description;
        int id;

        Tasks(string& userDate, string& userDescription)
            : id(nextId++), date(userDate), description(userDescription) {}

        Tasks() = default; // Needed for JSON

        void displayTask() {
            cout << "ID: " << id;
            cout << " | End Date: " << date;
            cout << " | Description: " << description << endl;
        }

        // For loading from file
        static void setNextId(int value) {
            nextId = value;
        }

        static int getNextId() {
            return nextId;
        }

        // JSON serialization
        friend void to_json(json& j, const Tasks& t) {
            j = json{{"id", t.id}, {"date", t.date}, {"description", t.description}};
        }

        friend void from_json(const json& j, Tasks& t) {
            j.at("id").get_to(t.id);
            j.at("date").get_to(t.date);
            j.at("description").get_to(t.description);
            if (t.id >= nextId)
                nextId = t.id + 1;  // keep nextId in sync
        }
};

int ChoiceValidator();

bool AddTask(list<Tasks>& taskList);

void showList(list<Tasks>& taskList);

void EditTask(list<Tasks>& taskList);

void CompleteTask(list<Tasks>& tasklist);

void RemoveTask(list<Tasks>& tasklist);

