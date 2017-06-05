#pragma warning (disable : 4005)

#include <iostream>
using namespace std;
#include <string>
#include <Windows.h>
#include <conio.h>
#include <new>


#include "TennisPlayer.h"
#include "Footballer.h"
#include "Interface.h"
#include "MyExceptions.h"

//void reroutingExceptions()
//{
//	try {
//		throw "reroutingExceptions()";
//	}
//	catch (char *str) {
//		cout << "��������� ���������� � " << str << endl;
//		throw;
//	}
//}
//
//void my_terminate()
//{
//	cout << "����������� �������-����������\n";
//	exit(1);
//}
//
//void my_unexpected()
//{
//	cout << "����������� ����������� ����������\n";
//	exit(1);
//}
//
//void function() throw(float)
//{
//	throw 1.;
//}
//
//class manip
//{
//private:
//	int n;
//	int m;
//	ostream &(*f)(ostream &, int, int);
//public:
//	manip(ostream &(*ff)(ostream &, int, int), int nn, int mm) : f(ff), n(nn), m(mm)
//	{}
//
//	friend ostream& operator<<(ostream &s, const manip& obj)
//	{
//		return obj.f(s, obj.n, obj.m);
//	}
//};
//
//ostream& f(ostream &s, int n, int m)
//{
//	s.width(n);
//	s.flags(ios::fixed);
//	s.precision(m);
//	return s;
//}
//
//manip wp(int n, int m)
//{
//	return manip(f, n, m);
//}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//cout << 5.4321 << endl;          //������ �� ����� �������������
	//cout << wp(10, 2) << 5.4321 << endl;
	//system("pause");

	//try {            //��������������� ����������
	//	reroutingExceptions();
	//}
	//catch (char *str) {
	//	cout << "��������� ���������� �� " << str << " � main\n" << endl;
	//	exit(1);
	//}

	/*
	set_terminate(my_terminate);
	try { //Terminate
		throw 1.;
	}
	catch (float e) {
		cout << "Caught float " << e << endl;
		exit(1);
	}*/

	/*set_unexpected(my_unexpected);

	try {
	function();
	}
	catch (float e) {
	cout << "Caught float " << e << endl;
	}*/

	char nameOfExitMenu[] = "�� �������?";
	char *exitMenuStrings[] = { "��",
		                        "���" };
	Menu exitMenu(nameOfExitMenu, exitMenuStrings, sizeof(exitMenuStrings) / sizeof(char*));

	char nameOfMainMenu[] = "������� ����";
	char *mainMenuStrings[] = { "�������� � ������� �����������",
		                        "�������� � ������� �����������",
		                        "�����" };
	Menu mainMenu(nameOfMainMenu, mainMenuStrings, sizeof(mainMenuStrings) / sizeof(char*));

	bool goBack = false;
	while (!goBack)
	{
		goBack = false;
		switch (mainMenu.menu()) {
		case 0: {
			Interface<Footballer> footballerInterface;
			footballerInterface.menu();
			break;
		}
		case 1: {
			Interface<Footballer> tennisPlayerInterface;
			tennisPlayerInterface.menu();
			break;
		}
		case 2:
			if (!exitMenu.menu())
				goBack = true;
			break;
		}
	}

	/*List<TennisPlayer> list;

	list.pushBack(TennisPlayer("�������", "������", "�������������", Person::initDate(3, 9, 1998), male, "�����, ����"));
	list.pushBack(TennisPlayer("�����", "������", "����������", Person::initDate(15, 12, 1997), male, "�����, ����"));
	list.pushBack(TennisPlayer("�������", "����", "��������", Person::initDate(11, 2, 1998), female, "�����, ����"));
	list.pushBack(TennisPlayer("�������", "�����", "���������", Person::initDate(14, 11, 1997), male, "�����, ����"));
	list.pushBack(TennisPlayer("�����������", "�����", "�����������", Person::initDate(25, 5, 1997), female, "�����, ����"));
	
	cout << "---------------------\n";
	list.print();
	cout << "---------------------\n";*/

	return 0;
}