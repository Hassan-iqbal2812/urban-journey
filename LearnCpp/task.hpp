#ifndef TASK_H
#define TASK_H

#include <string>

struct task {
	mutable bool completed;
	mutable std::string notes;
	mutable int questions; // mb this would be better as and array instead. 

};
void printTasks(task task_print);
#endif 
