#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    int id;
    string description;
};

class ToDoList {
private:
    vector<Task> tasks;
    int next_id;

public:
    ToDoList() : next_id(1) {}

    void addTask(const string& description) {
        Task new_task = {next_id++, description};
        tasks.push_back(new_task);
        cout << "Task added successfully." << endl;
    }

    void displayTasks() const {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
            return;
        }

        cout << "To-Do List:" << endl;
        for (const auto& task : tasks) {
            cout << task.id << ". " << task.description << endl;
        }
    }

    void removeTask(int id) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->id == id) {
                tasks.erase(it);
                cout << "Task removed successfully." << endl;
                return;
            }
        }
        cout << "Task with ID " << id << " not found." << endl;
    }
};

int main() {
    ToDoList todo_list;
    int choice;

    do {
        cout << "To-Do List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Remove Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // to ignore the newline character left in the input buffer

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                getline(cin, description);
                todo_list.addTask(description);
                break;
            }
            case 2:
                todo_list.displayTasks();
                break;
            case 3: {
                int id;
                cout << "Enter task ID to remove: ";
                cin >> id;
                todo_list.removeTask(id);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}