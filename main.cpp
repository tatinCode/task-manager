/**
 * main.cpp:
 * 	meant to hold the main functions for this task manager CLI
 * 	tool.
 * 	This is a project recommended by ChatGPT4o
 */
#include <iostream>
#include <string>
#include <cctype>	//for to lower

int main(int argc, char* argv[]) {

	if(argc < 2 && std::string(argv[2]) != "list"){
		std::cout << "not enough arguments, must complete ./task <command> <string>\n";
		return -1;
	}

	//variables
	for(int i = 0; i < argc; i++){
		printf("Argument #%d: %s\n", i, argv[i]);
	}
	


	return 0;
}
