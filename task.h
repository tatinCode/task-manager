/**
 * task.h:
 * 	header file for task.c, and is also the object that would hold task properties
 */
#include <iostream>

class Task{
	private:
		std::string taskName;

	public:
		bool parseArgs(char* argv[]);
}

public bool parseArgs(char* argv[]);
