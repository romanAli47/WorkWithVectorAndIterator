#ifndef TENNISPLAYER_CPP
#define TENNISPLAYER_CPP

#include "TennisPlayer.h"

TennisPlayer::TennisPlayer() : Person()
{}

TennisPlayer::TennisPlayer(string ln, string fn, string mn, Date bd, gender gend, string tp) : Person(ln, fn, mn, bd, gend)
{
	strcpy(trainingPlace, tp.c_str());
	//trainingPlace = tp;
}

TennisPlayer::TennisPlayer(const TennisPlayer &t) : Person(t)
{
	strcpy(trainingPlace, t.trainingPlace);
	//trainingPlace = t.trainingPlace;
}

istream& operator>>(istream &strm, TennisPlayer &tennisPlayer)
{
	Person person;
	strm >> person;
	tennisPlayer = person;

	cout << ">> Введите место тренировок: ";
	string temp;
	getline(strm, temp);
	strcpy(tennisPlayer.trainingPlace, temp.c_str());

	return strm;
}

ostream& operator<<(ostream &strm, TennisPlayer &tennisPlayer)
{
	/*strm << (Person) tennisPlayer;
	strm << " Место тренировок: " << (!tennisPlayer.trainingPlace.empty() ? tennisPlayer.trainingPlace : "Not Defined") << endl;*/

	const int dashCount = 96;

	for (int i = 0; i < dashCount; i++) strm << '-'; strm << endl;

	strm << setfill(' ') << left <<
		"|" << tennisPlayer.lastName << " " << tennisPlayer.firstName << " " << tennisPlayer.middleName << resetiosflags(ios::left);
	for (int k = 0; k < 44 - 2 - strlen(tennisPlayer.lastName) - strlen(tennisPlayer.firstName) - strlen(tennisPlayer.middleName); k++)
		strm << " ";

	if (tennisPlayer.birthDay.day == 0 || tennisPlayer.birthDay.month == 0 || tennisPlayer.birthDay.year == 0)
		strm << "|   Not Defined   ";
	else
	{
		strm << "|    " << setw(2) << setfill('0') << tennisPlayer.birthDay.day << "."
			<< setw(2) << setfill('0') << tennisPlayer.birthDay.month << "."
			<< tennisPlayer.birthDay.year << "   ";
	}

	strm << "|" << "  " << left << (tennisPlayer.personGender == male ? "М  " : "Ж  ") <<
		"|" << setw(25) << setfill(' ') << (tennisPlayer.trainingPlace ? tennisPlayer.trainingPlace : "    Not Defined") << "|" << resetiosflags(ios::left);

	return strm;
}

fstream& operator >> (fstream &strm, TennisPlayer &tennisPlayer)
{
	char g;
	strm >> tennisPlayer.lastName;
	strm >> tennisPlayer.firstName;
	strm >> tennisPlayer.middleName;
	strm >> tennisPlayer.birthDay.day;
	strm >> tennisPlayer.birthDay.month;
	strm >> tennisPlayer.birthDay.year;
	strm >> g; strm.get();
	g == 'ж' ? tennisPlayer.personGender = female : tennisPlayer.personGender = male;

	string temp;
	getline(strm, temp, '#');
	strm.get();
	strcpy(tennisPlayer.trainingPlace, temp.c_str());

	/*getline(strm, tennisPlayer.trainingPlace, '#');
	strm.get();*/

	return strm;
}

fstream& operator<<(fstream &strm, const TennisPlayer &tennisPlayer)
{
	strm << tennisPlayer.lastName << " "
		<< tennisPlayer.firstName << " "
		<< tennisPlayer.middleName << " "
		<< tennisPlayer.birthDay.day << " "
		<< tennisPlayer.birthDay.month << " "
		<< tennisPlayer.birthDay.year << " "
		<< (tennisPlayer.personGender == male ? 'м' : 'ж') << " "
		<< tennisPlayer.trainingPlace << "#\n";

	return strm;
}

bool TennisPlayer::operator > (TennisPlayer &tennisPlayer)
{
	int compareLastName = strcmp(this->lastName, tennisPlayer.lastName);
	int compareFirstName = strcmp(this->firstName, tennisPlayer.firstName);
	int compareMiddleName = strcmp(this->middleName, tennisPlayer.middleName);
	if (compareLastName > 0 || (compareLastName == 0 && compareFirstName > 0) ||
		(compareLastName == 0 && compareFirstName == 0 && compareMiddleName > 0))
		return true;
	return false;
}

bool TennisPlayer::operator < (TennisPlayer &tennisPlayer)
{
	int compareLastName = strcmp(this->lastName, tennisPlayer.lastName);
	int compareFirstName = strcmp(this->firstName, tennisPlayer.firstName);
	int compareMiddleName = strcmp(this->middleName, tennisPlayer.middleName);
	if (compareLastName < 0 || (compareLastName == 0 && compareFirstName < 0) ||
		(compareLastName == 0 && compareFirstName == 0 && compareMiddleName < 0))
		return true;
	return false;
}

bool TennisPlayer::operator == (TennisPlayer &tennisPlayer)
{
	bool isEquals = true;

	isEquals = (!strcmp("", tennisPlayer.lastName) || !strcmp(this->lastName, "") ? true :
		!strcmp(this->lastName, tennisPlayer.lastName));
	if (!isEquals)
		return false;

	isEquals = (!strcmp("", tennisPlayer.firstName) || !strcmp(this->firstName, "") ? true :
		!strcmp(this->firstName, tennisPlayer.firstName));
	if (!isEquals)
		return false;

	isEquals = (!strcmp("", tennisPlayer.middleName) || !strcmp(this->middleName, "") ? true :
		!strcmp(this->middleName, tennisPlayer.middleName));
	if (!isEquals)
		return false;

	isEquals = (!strcmp("", tennisPlayer.trainingPlace) || !strcmp(this->trainingPlace, "") ? true :
		!strcmp(this->trainingPlace, tennisPlayer.trainingPlace));
	if (!isEquals)
		return false;

	isEquals = (tennisPlayer.birthDay.day == 0 || this->birthDay.day == 0 ? true :
		this->birthDay.day == tennisPlayer.birthDay.day);
	if (!isEquals)
		return false;
	isEquals = (tennisPlayer.birthDay.month == 0 || this->birthDay.month == 0 ? true :
		this->birthDay.month == tennisPlayer.birthDay.month);
	if (!isEquals)
		return false;
	isEquals = (tennisPlayer.birthDay.year == 0 || this->birthDay.year == 0 ? true :
		this->birthDay.year == tennisPlayer.birthDay.year);
	if (!isEquals)
		return false;

	isEquals = (tennisPlayer.personGender == gender::not_defined || this->personGender == gender::not_defined ? true :
		this->personGender == tennisPlayer.personGender);
	if (!isEquals)
		return false;

	return true;
}

bool TennisPlayer::operator != (TennisPlayer &tennisPlayer)
{
	if (*this == tennisPlayer)
		return false;
	return true;
}

TennisPlayer& TennisPlayer::operator=(Person& person)
{
	strcpy(this->lastName, person.getLastName().c_str());
	strcpy(this->firstName, person.getFirstName().c_str());
	strcpy(this->middleName, person.getMiddleName().c_str());
	this->birthDay = person.getBirthDay();
	this->personGender = person.getPersonGender();

	return *this;
}

#endif