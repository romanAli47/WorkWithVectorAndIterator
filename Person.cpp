#include "Person.h"

Person::Person()
{
	birthDay.day = 1;
	birthDay.month = 1;
	birthDay.year = MAX_YEAR;
	personGender = male;
}

Person::Person(string ln, string fn, string mn, Date bd, gender gend)
{
	strcpy(lastName, ln.c_str());
	strcpy(firstName, fn.c_str());
	strcpy(middleName, mn.c_str());
	/*lastName = ln;
	firstName = fn;
	middleName = mn;*/
	birthDay = bd;
	personGender = gend;
}

Person::Person(const Person &p)
{
	strcpy(lastName, p.lastName);
	strcpy(firstName, p.firstName);
	strcpy(middleName, p.middleName);
	/*lastName = p.lastName;
	firstName = p.firstName;
	middleName = p.middleName;*/

	birthDay = p.birthDay;
	personGender = p.personGender;
}

string Person::getLastName()
{
	return lastName;
}

string Person::getFirstName()
{
	return firstName;
}

string Person::getMiddleName()
{
	return middleName;
}

Date Person::getBirthDay()
{
	return birthDay;
}

gender Person::getPersonGender()
{
	return personGender;
}

Date Person::initDate(int day, int month, int year)
{
	Date date;
	date.day = day;
	date.month = month;
	date.year = year;

	return date;
}

bool operator==(Date &date1, Date &date2)
{
	if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year)
		return true;
	return false;
}

istream& operator>>(istream &strm, Person &person)
{
	string g = "";
	string temp;

	cout << ">> ������� �������: ";
	temp = nameInput();
	strcpy(person.lastName, temp.c_str());
	//person.lastName = nameInput();

	cout << ">> ������� ���: ";
	temp = nameInput();
	strcpy(person.firstName, temp.c_str());
	//person.firstName = nameInput();

	cout << ">> ������� ��������: ";
	temp = nameInput();
	strcpy(person.middleName, temp.c_str());
	//person.middleName = nameInput();

	cout << "\n>> ������� ���� ��������\n";
	cout << "    * ���";
	person.birthDay.year = numberInputWithBrackets<int>(MIN_YEAR, MAX_YEAR);

	cout << "    * �����";
	person.birthDay.month = numberInputWithBrackets<int>(1, 12);

	cout << "    * ����";
	person.birthDay.day = numberInputWithBrackets<int>(1, 31);
	//while (true) {
	//	cin >> person.birthDay.day;
	//	if (cin.peek() == '\n')
	//		if ((person.birthDay.day >= 1 && person.birthDay.day <= 31 && (person.birthDay.month == 1 ||
	//			person.birthDay.month == 3 ||
	//			person.birthDay.month == 5 ||
	//			person.birthDay.month == 7 ||
	//			person.birthDay.month == 8 ||
	//			person.birthDay.month == 10 ||
	//			person.birthDay.month == 12)) ||
	//			(person.birthDay.day >= 1 && person.birthDay.day <= 30 && (person.birthDay.month == 4 ||
	//				person.birthDay.month == 6 ||
	//				person.birthDay.month == 9 ||
	//				person.birthDay.month == 11)) ||
	//				(person.birthDay.month == 2 && person.birthDay.day >= 1 && person.birthDay.day <= 28))
	//			break;
	//		else
	//			cout << "��������� ���� �� �������� � ����� ���������� ����� ������!\n";
	//	else
	//		cout << "������� ������ ���� ��������. �� ������ ���� ����� ������!\n";
	//	cout << "��������� ����: ";
	//	cin.clear();
	//	while (cin.get() != '\n'); //fflush(stdin);
	//}
	cin.get();

	cout << ">> ������� ��� (� - �������, � - �������): ";
	do {
		getline(cin, g);
		//cin >> g;
		if (g == "�" || g == "�") {
			(g == "�" ? person.personGender = male : person.personGender = female);
			break;
		}
		else {
			cout << "��� ������ �������. ��������� ����: ";
			fflush(stdin);
			//while (cin.get() != '\n');
		}
	} while (true);
	fflush(stdin);

	return strm;
}

ostream& operator<<(ostream &strm, Person &person)
{
	strm << " �������: " << (person.lastName ? person.lastName : "Not Defined") << endl;
	strm << " ���: " << (person.firstName ? person.firstName : "Not Defined") << endl;
	strm << " ��������: " << (person.middleName ? person.middleName : "Not Defined") << endl;
	strm << " ���� ��������: "	<< setw(2) << setfill('0') << person.birthDay.day << "."
								<< setw(2) << setfill('0') << person.birthDay.month << "."
														   << person.birthDay.year << endl;
	strm << " ���: " << (person.personGender == male ? "�������" : "�������") << endl;

	return strm;
}

void Person::menu()
{}