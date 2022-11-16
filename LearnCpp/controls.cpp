#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <vector>

using namespace std;

namespace controls
{
	void showConsoleCursor(bool showFlag)
	{
	
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(out,&cursorInfo);
		cursorInfo.bVisible = showFlag;
		SetConsoleCursorInfo(out,&cursorInfo);
	}
	void setCursorPosition(int x, int y)
	{
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		COORD coord = {(SHORT)x,(SHORT)y};
		SetConsoleCursorPosition(hOut,coord);
	}

	void clearScreen(){
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		COORD topLeft = {0,0};
		std::cout.flush();

		if(!GetConsoleScreenBufferInfo(hOut,&csbi))
		{
			std::cout << "Error trying : GetConsoleScreenBuffer" << std::endl;
		}
		DWORD len = csbi.dwSize.X * csbi.dwSize.Y;
		DWORD written;

		FillConsoleOutputCharacter(hOut,TEXT(' '),len,topLeft,&written);
		FillConsoleOutputAttribute(hOut,csbi.wAttributes,len,topLeft,&written);
		SetConsoleCursorPosition(hOut,topLeft);

	}

	int pickOption(vector<std::string> option)
	{
		
		
		clearScreen();
		showConsoleCursor(false);
		
		
		bool task_picker = false;
		int pick = 0;
		bool s_button_pressed = false;
		bool w_button_pressed = false;
		bool entr_button_pressed = false;
		do{
				setCursorPosition(0,0);
				if(GetAsyncKeyState('W') < 0 && w_button_pressed == false)
				{
					w_button_pressed = true;
				}
				if(GetAsyncKeyState('W') == 0 && w_button_pressed == true){
					w_button_pressed = false;
					if(pick != 0)
					{	
						pick--;
					}
				}

				if(GetAsyncKeyState('S') < 0 && s_button_pressed == false)
				{
					s_button_pressed = true;					
				}
				if(GetAsyncKeyState('S') == 0 && s_button_pressed == true){
					s_button_pressed = false;
					if(pick < option.size() - 1)
					{
						pick++;
					}
				}

				if(GetAsyncKeyState(VK_RETURN) < 0 && entr_button_pressed == false)
				{
					entr_button_pressed = true;
				}
				if(GetAsyncKeyState(VK_RETURN) == 0 && entr_button_pressed == true){
					entr_button_pressed = false;
						task_picker = true;	
				}
				
				for(int i = 0; i < option.size(); i++)
				{

					std::cout << option[i];	
					if(i == pick)
					{	
						std::cout  << " <";
					}
					else {
						std::cout << "  ";
					}							
					std::cout << "\n";
			}
			std::cout << "Pick : " << pick <<  std::endl;
			std::cout << "Pick a task to show" << std::endl; 
			std::cout << "Use the W & S character to move and Enter to select :)" << std::endl;
		}while(task_picker == false);
		
		return pick;
	}
}
