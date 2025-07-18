# 📋 TO-DO List Console Application

A simple command-line To-Do list manager written in C++. It allows users to create, view, edit, complete, and remove tasks, with data persistence using JSON files.

## 🚀 Features

- ✅ Add tasks with description and due date
- 📆 Automatically orders tasks by date
- 📝 Edit tasks by ID
- ✔️ Mark tasks as complete (removes them)
- ❌ Remove tasks
- 💾 Saves tasks in a JSON file (`tasks.json`)
- 🔄 Loads tasks on startup
- 📌 Task IDs auto-increment and persist across sessions

## 📂 File Structure

- `main.cpp` — Program entry point and menu loop
- `todo.h` — Task class and function declarations
- `todo.cpp` — Core logic and task management implementation
- `LICENSE.md` — MIT License
- `tasks.json` *(runtime)* — Automatically generated task data file

## 🛠️ Dependencies

- C++17 or later
- [nlohmann/json](https://github.com/nlohmann/json) (included via `#include "json.hpp"`)

## 🧪 How to Run

1. **Clone or download the repository**
2. **Compile the program** using a C++ compiler. Example with g++:

   ```bash
   g++ -std=c++17 main.cpp todo.cpp -o todo
   ```

3. **Run the program**:

   ```bash
   ./todo
   ```

## 📦 Example Menu

```
====== TO-DO LIST ======
1. View Tasks
2. Add Task
3. Edit Task
4. Complete Task
5. Delete Task
6. Exit
```

## 📄 License

This project is licensed under the MIT License — see the [LICENSE.md](./LICENSE.md) file for details.
