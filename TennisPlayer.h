#ifndef TENNISPLAYER_H
#define TENNISPLAYER_H

#include "Person.h"
#include "List.h"

class TennisPlayer : public Person
{
protected:
	char trainingPlace[50];
public:
	TennisPlayer();
	TennisPlayer(string ln, string fn, string mn, Date bd, gender gend, string tp);
	TennisPlayer(const TennisPlayer &t);

	friend istream& operator>>(istream &strm, TennisPlayer &tennisPlayer);
	friend ostream& operator<<(ostream &strm, TennisPlayer &tennisPlayer);

	friend fstream& operator >> (fstream &strm, TennisPlayer &tennisPlayer);
	friend fstream& operator << (fstream &strm, const TennisPlayer &tennisPlayer);

	bool operator > (TennisPlayer &tennisPlayer);
	bool operator < (TennisPlayer &tennisPlayer);

	bool operator == (TennisPlayer &tennisPlayer);
	bool operator != (TennisPlayer &tennisPlayer);

	TennisPlayer& operator=(Person& person);
};

template <>
void List<TennisPlayer>::printList()
{
	if (this->isEmpty()) {
		cout << "Список пуст!\n";
	}
	else {
		const int dashCount = 96;
		cout << "\t\t\t\t\t[ Список теннисистов ]\n";
		for (int i = 0; i < dashCount; i++) cout << '='; cout << endl;
		cout << "|                     ФИО                    |  Дата рождения  | Пол |     Место тренировок    |\n";
		
		node<TennisPlayer> *temp = head;
		while (temp != NULL) {
			cout << *(temp->data) << endl;
			temp = temp->next;
		}

		for (int i = 0; i < dashCount; i++) cout << '='; cout << endl;
	}
}

#endif