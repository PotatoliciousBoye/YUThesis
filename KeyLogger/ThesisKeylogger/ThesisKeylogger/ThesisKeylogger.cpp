// ThesisKeylogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdlib.h>
#include <Windows.h>
#include <iostream>

int main()
{
	while (true)
	{
		system("cls");
		if (GetAsyncKeyState(0x57) != 0)
		{
			std::cout << "w";
		}
		if (GetAsyncKeyState(0x41) != 0)
		{
			std::cout << "a";
		}
		if (GetAsyncKeyState(0x53) != 0)
		{
			std::cout << "s";
		}
		if (GetAsyncKeyState(0x44) != 0)
		{
			std::cout << "d";
		}
		if (GetAsyncKeyState(VK_SPACE) != 0)
		{
			std::cout << "[space]";
		}
		Sleep(10);
	}
	
}
