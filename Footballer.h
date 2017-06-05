#ifndef FOOTBALLER_H
#define FOOTBALLER_H

#include "Person.h"
#include "List.h"

class Footballer : public Person
{
protected:
	char clubName[50];
public:
	Footballer();
	Footballer(string ln, string fn, string mn, Date bd, gender gend, string cn);
	Footballer(const Footballer &f);

	friend istream& operator >> (istream &strm, Footballer &footballer);
	friend ostream& operator<<(ostream &strm, Footballer &footballer);

	friend fstream& operator >> (fstream &strm, Footballer &footballer);
	friend fstream& operator << (fstream &strm, const Footballer &footballer);

	bool operator > (Footballer &footballer);
	bool operator < (Footballer &footballer);

	bool operator == (Footballer &footballer);
	bool operator != (Footballer &footballer);

	Footballer& operator=(Person& person);
};

template <>
void List<Footballer>::printList()
{
	if (this->isEmpty()) {
		cout << "Список пуст!\n";
	}
	else {
		const int dashCount = 101;
		cout << "\t\t\t\t\t[ Список футболистов ]\n";
		for (int i = 0; i < dashCount; i++) cout << '='; cout << endl;
		cout << "|                     ФИО                    |  Дата рождения  | Пол |             Клуб             |\n";
		
		node<Footballer> *temp = head;
		while (temp != NULL) {
			cout << *(temp->data) << endl;
			temp = temp->next;
		}

		for (int i = 0; i < dashCount; i++) cout << '='; cout << endl;
	}
}

#endif