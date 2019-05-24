// ThesisKeylogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

int main()
{

	std::string username;
	std::cout << "Enter username\n";
	std::getline(std::cin, username);

	std::string outputFileName = "output - " + username + ".csv";

	remove(outputFileName.c_str());
	std::ofstream outputFile;
	outputFile.open(outputFileName.c_str());
	outputFile << "w,a,s,d,space,mouseX,mouseY\n";
	
	bool programEnd = false;
	int start = 0;
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	double runningFor = 0;
	double runtime = 6000;

	POINT cursor;
	LONG cursorTempX;
	LONG cursorTempY;
	
	std::cout << "\nBooting the game...";
	CreateProcess(L"kkrieger.exe",   // the path
		NULL,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);
	while (start < 2)
	{
		if (GetAsyncKeyState(VK_RETURN) != 0) {
			start++;
			PlaySound(TEXT("Ding.wav"), NULL, SND_FILENAME);
		}
		Sleep(1000);
		
	}

	GetCursorPos(&cursor);
	cursorTempX = cursor.x;
	cursorTempY = cursor.y;

	while (!programEnd)
	{
		system("cls");
		if (GetAsyncKeyState(0x57) != 0)
		{
			std::cout << "w";
			outputFile << "1,";

		}
		else
			outputFile << "0,";
		if (GetAsyncKeyState(0x41) != 0)
		{
			std::cout << "a";
			outputFile << "1,";

		}
		else
			outputFile << "0,";
		if (GetAsyncKeyState(0x53) != 0)
		{
			std::cout << "s";
			outputFile << "1,";

		}
		else
			outputFile << "0,";
		if (GetAsyncKeyState(0x44) != 0)
		{
			std::cout << "d";
			outputFile << "1,";

		}
		else
			outputFile << "0,";
		if (GetAsyncKeyState(VK_SPACE) != 0)
		{
			std::cout << "[space]";
			outputFile << "1,";

		}
		else
			outputFile << "0,";

		GetCursorPos(&cursor);//save cursor location
		outputFile << (cursorTempX - cursor.x) << ",";
		outputFile << (cursorTempY - cursor.y) << ",";

		cursorTempX = cursor.x;
		cursorTempY = cursor.y;

		outputFile << "\n";

		if (GetAsyncKeyState(0x50) != 0 || runningFor >= runtime)
		{
			programEnd = true;
			TerminateProcess(pi.hProcess, NULL);
		}
		Sleep(10);
		runningFor++;

	}
	outputFile.close();

	std::cout << "\n\n Thanks for participating in my thesis work. Press any key to close the program.";
	std::cin;
	
}

