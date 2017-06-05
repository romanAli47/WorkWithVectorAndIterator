#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

#include "MyExceptions.h"
#include "Menu.h"
#include "TextFile.cpp"

enum gender { male, female, not_defined };

const int MIN_YEAR = 1900;
const int MAX_YEAR = 2016;

struct Date
{
	int day;
	int month;
	int year;
};

class Person
{
protected:
	char lastName[50];
	char firstName[50];
	char middleName[50];
	Date birthDay;
	gender personGender;
public:
	Person();
	Person(string ln, string fn, string mn, Date bd, gender gend);
	Person(const Person &p);

	string getLastName();
	string getFirstName();
	string getMiddleName();
	Date getBirthDay();
	gender getPersonGender();
	static Date initDate(int day, int month, int year);

	friend bool operator == (Date &date1, Date &date2);

	friend istream& operator>>(istream& strm, Person &person);
	friend ostream& operator<<(ostream &strm, Person &person);

	virtual void menu();
};

#endif

