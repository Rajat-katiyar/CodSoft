#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

// Function to add a task to the list
void AddTask(std::vector<Task>& taskList, const std::string& description) {
    Task task;
    task.description = description;
    task.completed = false;
    taskList.push_back(task);
}

// Function to view tasks
void ViewTasks(const std::vector<Task>& taskList) {
    if (taskList.empty()) {
        std::cout << "No tasks to display." << std::endl;
    } else {
        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < taskList.size(); i++) {
            std::cout << i + 1 << ". ";
            if (taskList[i].completed) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << taskList[i].description << std::endl;
        }
    }
}

// Function to mark a task as completed
void MarkTaskCompleted(std::vector<Task>& taskList, int index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList[index - 1].completed = true;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

// Function to remove a task from the list
void RemoveTask(std::vector<Task>& taskList, int index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList.erase(taskList.begin() + index - 1);
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() {
    std::vector<Task> taskList;

    while (true) {
        std::cout << "To-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the task description: ";
                std::cin.ignore(); // Clear the input buffer
                std::string description;
                std::getline(std::cin, description);
                AddTask(taskList, description);
                break;
            case 2:
                ViewTasks(taskList);
                break;
            case 3:
                ViewTasks(taskList);
                std::cout << "Enter the task number to mark as completed: ";
                int taskNumber;
                std::cin >> taskNumber;
                MarkTaskCompleted(taskList, taskNumber);
                break;
            case 4:
                ViewTasks(taskList);
                std::cout << "Enter the task number to remove: ";
                int taskToRemove;
                std::cin >> taskToRemove;
                RemoveTask(taskList, taskToRemove);
                break;
            case 5:
                return 0; // Exit the program
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

