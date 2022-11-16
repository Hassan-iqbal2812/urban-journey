#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

namespace solution {
	
	
	int s75(int x, int y, char op)
	{
		
		switch (op) {
			case '*':
				return x * y;
			case '+':
				return x + y;
			case '-':
				return x - y;
			case '%':
				return x % y;
			default:
				return 0;
		}
	}
	
	void s69(){
		cout << "Enter a radius : " ;
		int radius{};
		cin >> radius;
		cout << "The circumference us : " << 2.0 * radius * constants::pi << '\n';
	}
	
	bool passOrFail()
	{
		static int s_passes {3};//By having it as a static it allows us to keep the variable
		--s_passes;	
		return (s_passes >= 0);
	}
	
	void s6x(){
	
		cout << "Question 1 : \n";
		{
			cout << "Enter a postive number : "; 
			int num{};
			cin >> num;
			if(num < 0)
			{
				cout << "Negative Number entered making postive \n";
				num = -num;
			}
			cout << "You Entered " << num << std::endl;
			num;
		}
		cout << "Question 2 : \n";	
		{
			cout << "How many students are in your class? \n";
			int students;
			cin >> students;
	
			if(students > constants::max_class_size)
			{
				cout << "There are too many students in this class\n"; 
			}
			else {
				cout << "this class isnt too large \n";
			}
		}
		cout << "Question 3 : \n";
		{
			cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
			cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
			cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
			cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
			cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");
		}	
	}
	
	bool checkSolutionExists(std::string solution)
	{
		cout << "The solution we are looking for " << solution << endl;
		
		if (solution == "6.x")
		{
			s6x();
		}
		if (solution == "6.9")
		{
			s69();
		}
		if (solution == "7.5")
		{
			std::cout << "Result " << s75(2,1,'+') << std::endl;
			std::cout << "Result " << s75(2,1,'-') << std::endl;
			std::cout << "Result " << s75(2,2,'*') << std::endl;
			std::cout << "Result " << s75(2,2,'%') << std::endl;
		}
		
		return true;
	}
}
