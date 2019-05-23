// ThesisKeylogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <fstream>

int main()
{
	std::ofstream outputFile;
	outputFile.open("output.csv");
	outputFile << "w,a,s,d,space,mouseX,mouseY\n";
	bool programEnd = false;
	int gatherStart = 0;
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	POINT cursor;
	LONG cursorTempX;
	LONG cursorTempY;
	
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
	while (gatherStart < 2)
	{
		if (GetAsyncKeyState(VK_RETURN) != 0) {
			gatherStart++;
			PlaySound(TEXT("Ding.wav"), NULL, SND_FILENAME);
		}
		Sleep(1000);
		if (gatherStart == 2)
			PlaySound(TEXT("Notify.wav"), NULL, SND_FILENAME);
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

		if (GetAsyncKeyState(0x50) != 0)
		{
			programEnd = true;
			TerminateProcess(pi.hProcess, NULL);
		}
		Sleep(10);
	}
	outputFile.close();
	
}

