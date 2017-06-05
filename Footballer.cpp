#include "Footballer.h"

Footballer::Footballer() : Person()
{}

Footballer::Footballer(string ln, string fn, string mn, Date bd, gender gend, string cn) : Person(ln, fn, mn, bd, gend)
{
	strcpy(clubName, cn.c_str());
	//clubName = cn;
}

Footballer::Footballer(const Footballer &f) : Person(f)
{
	strcpy(clubName, f.clubName);
	//clubName = f.clubName;
}

istream& operator>>(istream &strm, Footballer &footballer)
{
	Person person;
	strm >> person;
	footballer = person;

	cout << ">> Введите название клуба: ";
	//footballer.clubName = stringWithNumbersInput();
	string cn = stringWithNumbersInput();
	strcpy(footballer.clubName, cn.c_str());

	return strm;
}

ostream& operator<<(ostream &strm, Footballer &footballer)
{
	/*strm << (Person) footballer;
	strm << " Клуб: " << (!footballer.clubName.empty() ? footballer.clubName : "Not Defined") << endl;*/
	const int dashCount = 101;

	for (int i = 0; i < dashCount; i++) strm << '-'; strm << endl;

	strm << setfill(' ') << left <<
		"|" << footballer.lastName << " " << footballer.firstName << " " << footballer.middleName << resetiosflags(ios::left);
	for (int k = 0; k < 44 - 2 - strlen(footballer.lastName) - strlen(footballer.firstName) - strlen(footballer.middleName); k++)
		strm << " ";

	if (footballer.birthDay.day == 0 || footballer.birthDay.month == 0 || footballer.birthDay.year == 0)
		strm << "|   Not Defined   ";
	else
	{
		strm << "|    " << setw(2) << setfill('0') << footballer.birthDay.day << "."
			<< setw(2) << setfill('0') << footballer.birthDay.month << "."
			<< footballer.birthDay.year << "   ";
	}

	strm << "|" << "  " << left << (footballer.personGender == male ? "М  " : "Ж  ") <<
		"|" << setw(30) << setfill(' ') << (footballer.clubName ? footballer.clubName : "    Not Defined") << "|" << resetiosflags(ios::left);

	return strm;
}

fstream& operator >> (fstream &strm, Footballer &footballer)
{
	char g;
	strm >> footballer.lastName;
	strm >> footballer.firstName;
	strm >> footballer.middleName;
	strm >> footballer.birthDay.day;
	strm >> footballer.birthDay.month;
	strm >> footballer.birthDay.year;
	strm >> g; strm.get();
	g == 'ж' ? footballer.personGender = female : footballer.personGender = male;
	
	string temp;
	getline(strm, temp, '#');
	strm.get();
	strcpy(footballer.clubName, temp.c_str());

	/*getline(strm, footballer.clubName, '#');
	strm.get();*/

	return strm;
}

fstream& operator<<(fstream &strm, const Footballer &footballer)
{
	strm << footballer.lastName << " "
		 << footballer.firstName << " "
		 << footballer.middleName << " "
		 << footballer.birthDay.day << " "
		 << footballer.birthDay.month << " "
		 << footballer.birthDay.year << " "
		 << (footballer.personGender == male ? 'м' : 'ж') << " "
		 << footballer.clubName << "#\n";

	return strm;
}

bool Footballer::operator > (Footballer &footballer)
{
	int compareLastName = strcmp(this->lastName, footballer.lastName);
	int compareFirstName = strcmp(this->firstName, footballer.firstName);
	int compareMiddleName = strcmp(this->middleName, footballer.middleName);
	if (compareLastName > 0 || (compareLastName == 0 && compareFirstName > 0) ||
		(compareLastName == 0 && compareFirstName == 0 && compareMiddleName > 0))
		return true;
	return false;
}

bool Footballer::operator < (Footballer &footballer)
{
	int compareLastName = strcmp(this->lastName, footballer.lastName);
	int compareFirstName = strcmp(this->firstName, footballer.firstName);
	int compareMiddleName = strcmp(this->middleName, footballer.middleName);
	if (compareLastName < 0 || (compareLastName == 0 && compareFirstName < 0) ||
		(compareLastName == 0 && compareFirstName == 0 && compareMiddleName < 0))
		return true;
	return false;
}

bool Footballer::operator == (Footballer &footballer)
{
	bool isEquals = true;

	isEquals = (!strcmp("", footballer.lastName) || !strcmp(this->lastName, "") ? true :
		!strcmp(this->lastName, footballer.lastName));
	if (!isEquals)
		return false;

	isEquals = (!strcmp("", footballer.firstName) || !strcmp(this->firstName, "") ? true :
		!strcmp(this->firstName, footballer.firstName));
	if (!isEquals)
		return false;

	isEquals = (!strcmp("", footballer.middleName) || !strcmp(this->middleName, "") ? true :
		!strcmp(this->middleName, footballer.middleName));
	if (!isEquals)
		return false;

	isEquals = (!strcmp("", footballer.clubName) || !strcmp(this->clubName, "") ? true :
		!strcmp(this->clubName, footballer.clubName));
	if (!isEquals)
		return false;

	isEquals = (footballer.birthDay.day == 0 || this->birthDay.day == 0 ? true :
		this->birthDay.day == footballer.birthDay.day);
	if (!isEquals)
		return false;
	isEquals = (footballer.birthDay.month == 0 || this->birthDay.month == 0 ? true :
		this->birthDay.month == footballer.birthDay.month);
	if (!isEquals)
		return false;
	isEquals = (footballer.birthDay.year == 0 || this->birthDay.year == 0 ? true :
		this->birthDay.year == footballer.birthDay.year);
	if (!isEquals)
		return false;

	isEquals = (footballer.personGender == gender::not_defined || this->personGender == gender::not_defined ? true :
		this->personGender == footballer.personGender);
	if (!isEquals)
		return false;

	return true;
}

bool Footballer::operator != (Footballer &footballer)
{
	if (*this == footballer)
		return false;
	return true;
}

Footballer& Footballer::operator=(Person& person)
{
	strcpy(this->lastName, person.getLastName().c_str());
	strcpy(this->firstName, person.getFirstName().c_str());
	strcpy(this->middleName, person.getMiddleName().c_str());
	this->birthDay = person.getBirthDay();
	this->personGender = person.getPersonGender();

	return *this;
}