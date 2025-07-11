/**
 * main.cpp:
 * 	meant to hold the main functions for this task manager CLI
 * 	tool.
 * 	This is a project recommended by ChatGPT4o
 */
#include <iostream>
#include <string>
#include <cctype>	//for to lower

#include "task.hpp"

void eval(char* argv[]);

int main(int argc, char* argv[]) {

	if(argc < 2){
		std::cout << "not enough arguments, must complete ./task <command> <string>\n";
		std::cout << "Usage: ./task [add | list | mark | unmark | delete] [arguments or id]\n";
		return -1;

	}

	//for debugging
	//for(int i = 0; i < argc; i++){
	//	printf("Argument #%d: %s\n", i, argv[i]);
	//}

	//listTasks();

	eval(argv);

	listTasks();

	return 0;
}

void eval(char* argv[]){
	std::string cmd = argv[1];

	if(cmd == "add"){
		addTask(argv[2]);
	}
	else if(cmd == "list"){
		listTasks();
	}
	else if(cmd == "mark"){
		try{
			int id = std::stoi(argv[2]);
			markDone(id);
		}catch(...){
			std::cout << "Invalid ID\n";
		}
	}
	else if(cmd == "unmark"){
		try{
			int id = std::stoi(argv[2]);
			unmarkDone(id);
		}catch(...){
			std::cout << "Invalid ID\n";
		}
	}
	else if(cmd == "delete" || cmd == "remove"){
		try{
			int id = std::stoi(argv[2]);
			deleteTask(id);
		}catch(...){
			std::cout << "Invalid ID\n";
		}
	}
	else{
		std::cout << "Unkown Command: " << argv[1] << "\n";
		std::cout << "Usage: ./task [add | list | mark | unmark | delete] [arguments or id]\n";
	}
}