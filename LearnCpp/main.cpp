#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "constants.h"
#include "cmd.hpp"

struct Foo{
	int large;
	int small;
	Foo() {
		std::cout << "Enter an integer : ";
		std::cin >> small;
		std::cout << "Enter a larger int : ";
		std::cin >> large;
	}
};

void solution(int small,int large){
	if(small > large){
		std::cout << "Swapping the values\n";
		{
			int n {small};
			small = large;
			large = n;		
		}
		std::cout << "f.small : " << small << "\n";
		std::cout << "f.large : " << large << "\n";	
	}	
}

void solution69()
{
	std::cout << "Enter a radius : " ;
       	int radius{};
	std::cin >> radius;

	std::cout << "The circumference us : " << 2.0 * radius * constants::pi << '\n';

}

bool passOrFail()
{
	static int s_passes {3};//By having it as a static it allows us to keep the variable
	--s_passes;	
	return (s_passes >= 0);
}



void solution6x()
{
	std::cout << "Question 1 : \n";
	{
		std::cout << "Enter a postive number : "; 
		int num{};
		std::cin >> num;
		if(num < 0)
		{
			std::cout << "Negative Number entered making postive \n";
			num = -num;
		}

		std::cout << "You Entered " << num << std::endl;
		num;
	}
	std::cout << "Question 2 : \n";	
	{
		std::cout << "How many students are in your class? \n";
		int students;
		std::cin >> students;

		if(students > constants::max_class_size)
		{
			std::cout << "There are too many students in this class\n"; 
		}
		else {
			std::cout << "this class isnt too large \n";
		}
	}
	std::cout << "Question 3 : \n";
	{
		std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");
	}	
}


void HeaderApplication(){

	std::cout << "Welcome to Learn Cpp with [E<] " << std::endl;

	std::cout << R"(
    ,---,.         
  ,'  .' |    ,--. 
,---.'   |   /  /| 
|   |   .'  '  / ' 
:   :  |-, /  / /  
:   |  ;/|/  / ,   
|   :   .'\ '\ \   
|   |  |-, \  \ '  
'   :  ;/|  \  . | 
|   |    \   \__\. 
|   :   .'         
|   | ,'           
`----'             
)" << '\n';		                   
}

int main(int argc,char ** argv)
{
	//1st we should check if any args have been passed
	const std::string task_directory= {"c:\\Users\\Hassan.Iqbal\\Documents\\veolia\\Hassan_Dev\\LearnCpp\\Tasks"};
	HeaderApplication();
	cmd::handleArgs(task_directory,argc,argv);	
	
	if (std::string(argv[1]) == "6.x")
	{
		solution6x();
	}
	if (std::string(argv[1]) == "6.9")
	{
		solution69();
	}
	std::cout << "***********************" << std::endl;	
	std::cout << "Closing the application" << std::endl;		
	return 0;
}
