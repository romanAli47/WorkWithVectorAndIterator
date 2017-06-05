#pragma warning (disable : 4005)

#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"

#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Menu::Menu(char *name, char **strings, int maxmp)
{
	menuPosition = 0;
	maxMenuPosition = maxmp;

	try {
		nameOfTheMenu = new char[strlen(name) + 1];
		strcpy(nameOfTheMenu, name);

		menuStrings = new char*[maxMenuPosition];
		for (int i = 0; i < maxMenuPosition; i++) {
			menuStrings[i] = new char[strlen(strings[i]) + 1];
			strcpy(menuStrings[i], strings[i]);
		}
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
		throw;
	}
}

Menu::~Menu()
{
	for (int i = 0; i < maxMenuPosition; i++)
		delete[] menuStrings[i];
	delete[] menuStrings;

	delete[] nameOfTheMenu;
}

int Menu::menu()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_SCREEN_BUFFER_INFO SCRN_INFO;
	//GetConsoleScreenBufferInfo(hStdOut, &SCRN_INFO);

	//FillConsoleOutputAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN, SCRN_INFO.dwSize.X*SCRN_INFO.dwSize.Y, SCRN_INFO.dwCursorPosition, NULL);

	menuPosition = 0;
	do {
		system("cls");
		//SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout.setf(ios::uppercase);
		cout << "\t\t---" << nameOfTheMenu << "---" << endl;
		cout.unsetf(ios::uppercase);
		//SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY);
		for (int i = 0; i < maxMenuPosition; i++) {
			if (menuPosition != i)
				cout << "\t";
			else
				cout << "      ";
			if (menuPosition == i)
				cout << "-> ";
			if (menuPosition != i)
				cout << "* ";
			cout << menuStrings[i] << endl;
		}
	} while (choice());
	return menuPosition;
}

bool Menu::choice()		//Return Enter if the user press Enter, else return false
{
	char ch;
	while (true) {
		ch = _getch();
		switch (ch) {
		case UpArrow:	//Up Arrow
			if (menuPosition > 0)
				menuPosition--;
			else
				menuPosition = maxMenuPosition - 1;
			return true;
			break;
		case DownArrow:	//Down Arrow
			if (menuPosition < maxMenuPosition - 1)
				menuPosition++;
			else
				menuPosition = 0;
			return true;
			break;
		case ENTER:	//Enter
			return false;
		case ESC: //Esc
			menuPosition = maxMenuPosition - 1;
			return false;
		default:
			break;
		}
	}
}