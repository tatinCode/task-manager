/**
 * task.hpp:
 * 	header file for task.c, and is also the object that would hold task properties
 */
#include <string.h>
#include <iostream>

#ifndef _TASK
#define _TASK

class Task{
	private:
		std::string taskName;
        std::string tasks[3];

	public:
		Task();
		~Task();
		bool parseArgs(int argc, char* argv[]);
};

#endif
