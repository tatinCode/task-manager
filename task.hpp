/**
 * task.hpp:
 * 	header file for task.c, and is also the object that would hold task properties
 */
#include <string.h>
#include <vector>
#include <iostream>

#ifndef _TASK_HPP
#define _TASK_HPP

struct task{
	int id;
	std::string description;
	bool status;
};

void addTask(const std::string &description);
void listTasks();
void deleteTask(int id);
void markDone(int id);
void unmarkDone(int id);

std::vector<task> loadTasks();
void saveTasks(const std::vector<task> &tasks);

#endif
