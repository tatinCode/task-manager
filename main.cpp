/**
 * main.cpp:
 * 	meant to hold the main functions for this task manager CLI
 * 	tool.
 * 	This is a project recommended by ChatGPT4o
 */
#include <iostream>
#include <string>
#include <cctype>	//for to lower

#include task.h

int main(int argc, char* argv[]) {
    Task task = new Task();

	if(argc < 2 || argc > 3 && std::string(argv[2]) != "list"){
		std::cout << "not enough arguments, must complete ./task <command> <string>\n";
		return -1;

	}

	//for debugging
	for(int i = 0; i < argc; i++){
		printf("Argument #%d: %s\n", i, argv[i]);
	}


	


	return 0;
}
