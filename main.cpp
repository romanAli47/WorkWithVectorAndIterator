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
//		cout << "Обработка исключения в " << str << endl;
//		throw;
//	}
//}
//
//void my_terminate()
//{
//	cout << "Сосбтвенная функция-обработчик\n";
//	exit(1);
//}
//
//void my_unexpected()
//{
//	cout << "Сосбтвенный неожиданный обработчик\n";
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

	//cout << 5.4321 << endl;          //Работа со своим манипулятором
	//cout << wp(10, 2) << 5.4321 << endl;
	//system("pause");

	//try {            //Перенаправление исключений
	//	reroutingExceptions();
	//}
	//catch (char *str) {
	//	cout << "Обработка исключения из " << str << " в main\n" << endl;
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

	char nameOfExitMenu[] = "Вы уверены?";
	char *exitMenuStrings[] = { "Да",
		                        "Нет" };
	Menu exitMenu(nameOfExitMenu, exitMenuStrings, sizeof(exitMenuStrings) / sizeof(char*));

	char nameOfMainMenu[] = "Главное меню";
	char *mainMenuStrings[] = { "Работать с данными футболистов",
		                        "Работать с данными теннисистов",
		                        "Выход" };
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

	list.pushBack(TennisPlayer("Михадюк", "Андрей", "Александрович", Person::initDate(3, 9, 1998), male, "Минск, ГЦОР"));
	list.pushBack(TennisPlayer("Рунец", "Кирилл", "Михайлович", Person::initDate(15, 12, 1997), male, "Минск, РЦОП"));
	list.pushBack(TennisPlayer("Иванова", "Инга", "Ивановна", Person::initDate(11, 2, 1998), female, "Минск, ГЦОР"));
	list.pushBack(TennisPlayer("Сидоров", "Антон", "Антонович", Person::initDate(14, 11, 1997), male, "Минск, ГЦОР"));
	list.pushBack(TennisPlayer("Прокофьевна", "Алина", "Афанасьевна", Person::initDate(25, 5, 1997), female, "Минск, РЦОП"));
	
	cout << "---------------------\n";
	list.print();
	cout << "---------------------\n";*/

	return 0;
}