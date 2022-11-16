#include <iostream>
#include "task.hpp"
using namespace std;

void printTasks(task task_print)
{
	std::cout << "Task Finished : " << std::boolalpha << task_print.completed << std::endl;
	std::cout << "Task notes : " << task_print.notes << std::endl;
	std::cout << "Task Question : " << task_print.questions << std::endl;	

}







