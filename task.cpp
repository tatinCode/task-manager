#include <iostream>
#include <fstream>
#include <sstream>

#include "task.hpp"

void addTask(const std::string& description){
    std::vector<task> tasks = loadTasks();

    int newId;
    if(tasks.empty()){
        newId = 0;
    }
    else{
        newId = tasks.back().id + 1;
    }

    task newTask{newId, description, false};

    tasks.push_back(newTask);
    saveTasks(tasks);   //to save the file

    std::cout << "Task added with ID: " << newId << "\n";
}

void listTasks(){
    std::vector<task> tasks = loadTasks();

    if(tasks.empty()){
        std::cout << "No task found!\nreturning...";
        return;
    }

    //std::cout << "\nPrinting All Tasks...\n\n";
    //std::cout << "id\t Description \t\t Done?\n";

    printf("\n%-4s| %-25s| %s\n", "ID", "Description", "Done");
    printf("----+-------------------------+------\n");

    for(const auto& task:tasks){
        //std::cout << task.id << "\t|" << task.description << "\t|";

        printf("%-4d| %-25s", task.id, task.description.c_str());

        if(task.status){
            //std::cout << "  x\t";
            printf("|  %s\n", "x");
        }
        else{
            //std::cout << "   \t";
            printf("|  %s\n", " ");
        }
    }

}

void deleteTask(int id){
    std::vector<task> tasks = loadTasks();
    if(id < 0 || id > static_cast<int>(tasks.size())){
        std::cout << "Id out of bounds\n";
        return;
    }

    bool found = false;

    for(size_t i = 0; i < tasks.size(); i++){
        if(tasks[i].id == id){
            std::cout << "\nSuccessfully deleted task: " << tasks[i].description << "\n";
            tasks.erase(tasks.begin() + i);
            found = true;
            break;
        }
    }

    if(!found){
        std::cout << "\nFailed to delete with id: " << id << "\n";
        return;
    }

    for(size_t i = 0; i < tasks.size(); i++){
        tasks[i].id = static_cast<int>(i);
    }

    saveTasks(tasks);
}

void markDone(int id){
    std::vector<task> tasks = loadTasks();

    if(id < 0 || id >= static_cast<int>(tasks.size())){
        std::cout << "Id out of bounds\n";
        return;
    }

    for(size_t i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].id == id)
        {
            std::cout << "\nSuccessfully marked task: " << tasks[i].description << "\n";
            tasks[i].status = true;
            saveTasks(tasks);
            return;
        }
    }

    std::cout << "\nFailed to mark task with id: " << id << "\n";
}

void unmarkDone(int id){
    std::vector<task> tasks = loadTasks();
    if(id < 0 || id > static_cast<int>(tasks.size())){
        std::cout << "Id out of bounds\n";
        return;
    }

    for(size_t i = 0; i < tasks.size(); i++){
        if (tasks[i].id == id)
        {
            std::cout << "\nSuccessfully unmarked task: " << tasks[i].description << "\n";
            tasks[i].status = false;
            saveTasks(tasks);
            return;
        }
    }

    std::cout << "\nFailed to unmark task with id: " << id << "\n";
}

std::vector<task> loadTasks(){
    std::vector<task> tasks;
    std::string line;

    std::ifstream file("task.txt");
    if(!file){
        std::cout << "task.txt doesn't exist yet. Creating a new one...\n";
        return tasks;
    }

    while(std::getline(file,line)){
        if(line.empty()){
            continue;
        }

        std::istringstream ss(line);
        std::string idStr;      //for the id
        std::string desc;       //for the description
        std::string doneStr;    //for marking whats done

        std::getline(ss,idStr, '|');
        std::getline(ss,desc, '|');
        std::getline(ss,doneStr, '|');

        task t;
        t.id = std::stoi(idStr);
        t.description = desc;
        t.status = (doneStr == "1");

        tasks.push_back(t);
    }

    file.close();

    return tasks;
}

void saveTasks(const std::vector<task> &tasks){
    std::ofstream file("task.txt", std::ios::trunc);    //overwrites new file
    if(!file){
        std::cout << "failed to open task.txt.\n";
        return;
    }

    for(const task& t:tasks){
        file << t.id << "|" << t.description << "|";

        if(t.status){
            file << "1";
        }
        else{
            file << "0";
        }
        file << "\n";
    }

    file.close();
}
