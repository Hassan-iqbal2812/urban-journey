#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdlib.h>
#include "task.hpp"
#include "controls.hpp"
#include "solutions.hpp"

// this file should handle all of the functionality of CLI
// E.g Handle the Argv[1]
// Print all command options
// Build commands :
// 	cl main.cpp cmd.cpp /std:c++17 /EHsc
// 	cl main.cpp cmd.cpp task.cpp /std:c++17 /EHsc <-- updated
// 	cl main.cpp cmd.cpp task.cpp /std:c++17 /EHsc User32.lib
//	cl main.cpp cmd.cpp task.cpp controls.cpp /std:c++17 /EHsc User32.lib
//	cl main.cpp cmd.cpp task.cpp controls.cpp solutions.cpp /std:c++17 /EHsc User32.lib
// 	We should try to move this all to "Cmake" 
// 	To messy to build from Command Line




using namespace std;
namespace cmd 
{
	const std::filesystem::path path{"c:\\Users\\Hassan.Iqbal\\Documents\\veolia\\Hassan_Dev\\LearnCpp\\Tasks"};
	void helpmessage()
	{
		cout << "************************************************" << endl;
		cout << "*main.exe [command]" << endl;
		cout << "*[-h]						  (help message)" 	<< endl; //Done
		cout << "*[-new] 	[task #]				   	  (new task)" 	<< endl; //Done
		cout << "*[-run] 	[task #]		 (will run task)" 	<< endl; 
		cout << "*[notes] 	[task #] 	(will show notes of task)" 	<< endl;
		cout << "*[-list]  (will show all tasks in directory)" 		<< endl;
		cout << "*[-list] [task #](will show notes of task)	" 		<< endl; 
		cout << "************************************************" << endl;
	}
	
//Maybe file_existing could get refactored
	bool file_existing(std::string task,const std::filesystem::path& p,std::filesystem::file_status s = std::filesystem::file_status{}) 
	{
		//[FIX]This is for the Directory that why its alwasy printing yes
		if(std::filesystem::status_known(s) ? std::filesystem::exists(s) :  std::filesystem::exists(p)){
			std::string file = p.u8string() + "\\Task"+ task + ".txt";		
			std::cout << "FILE Directory -> " << file << endl;	
			std::ifstream myfile(file);
			std::string line;
			if(myfile.is_open())
			{
				std::cout << "Printing Contents of file " << std::endl;
				while(getline(myfile,line))
				{
					cout<< line << endl;
				}
				myfile.close();
			}
			else {
				std::cout << "couldnt open || find the file \n";
				char answer;
				std::cout << "Would you like to create one?" << endl;
				std::cin >> answer;
			
				if(answer == 'Y' || answer == 'y'){
					std::cout << "Creating new file" << std::endl;	
					std::ofstream ofs(file); 
					
					ofs << "[NOTES]	:\n" << std::endl; 
					ofs << "[TASK] 	:\n" << std::endl;
					ofs << "[COMPLETED] : FALSE \n" << std::endl;					
					
					ofs.close();
					std::cout << "File created" << std::endl;
					return true;
				}
				else if (answer == 'N' || answer == 'n') {
					std::cout << "Quiting the program " << std::endl;
					return false;
				}
				else {
					std::cout << "Argument invalid" << std::endl;
					return false;
				}	
			}			
			return true;
		}	
		else{
			std::cout << "does not exsit" << endl;
	       		return false;}
	}

	void newTask(std::string task){
		std::filesystem::create_directories(path);
		if (;file_existing(task, path) == true ){ // Checked if the directory exisits.
			std::cout << "Found File or created file" << std::endl;	
		}
		else {
			std::cout << "Quitting Program ..." << std::endl;	

		}
	}

	bool solution_navigator(std::string taskNumber){
		
		std::filesystem::create_directories(path);
		std::string fn = "Task" + taskNumber + ".txt";
		
		if(;file_existing(taskNumber, path) == true ){
			std::cout << "Found File or created file" << std::endl;
			return true;	
		}
		else {
			std::cout << "Quitting Program ..." << std::endl;	
			return false;
		}		
		cout <<  "Tutorial : " <<  taskNumber << endl;	
	}
	
	// Pass as ref instead?
	void handleArgs(const std::string dir,int argc,char ** argv){
		
		cout << "argc : " << argc << endl;	
		if(argc > 1) {		
			if(std::string(argv[1]) == "-new"){		 
				if(argc < 3){
					cout << "Throw excetion not enough arguments" << endl; 
					return; 
				}
				newTask(argv[2]);
			}
			else if (std::string(argv[1]) == "-run")
			{
				solution::checkSolutionExists(std::string(argv[2]));
			}
			else if(std::string(argv[1]) == "-list"){
				
				if(argv[2] != NULL) {	
					solution_navigator(argv[2]);//Mb change -> file existing
				}
				else {
					std::vector<std::string> v = {};	
					for(const auto & entry : std::filesystem::directory_iterator(path))
					{
						const auto filenameStr = entry.path().filename().string();
						if(entry.is_directory())
						{
							std::cout << "Dir : " << filenameStr << "\n";
						}
						else if (entry.is_regular_file()){
							v.push_back(filenameStr);
						}
						else 
							std::cout << "??" << filenameStr << '\n'; 
					}	
					int taskNumber = controls::pickOption(v);
					std::cout << v[taskNumber] << std::endl;
					task task1 = {true,"TestString",4};
					//printTasks(task1);

				}
			}
			else{
				cout << "Printing" << argv[1] << endl;
				cout << "Help Message " << endl;
				helpmessage();
			}
		}
		else
		{
			cout << "Failed to parse any arguments" << endl; 
			helpmessage();
			
		}		
	}
}
