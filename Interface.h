#ifndef INTEERFACE_H
#define INTEERFACE_H

#include "Menu.h"

#include "List.h"
#include "ListIterator.h"
#include "Algorithm.h"
#include "TextFile.h"
#include "BinaryFile.h"

#include <typeinfo.h>

bool compare(Footballer f1, Footballer f2)
{
	if (!strcmp(f1.getFirstName().c_str(), f2.getFirstName().c_str()) && f1.getPersonGender() == f2.getPersonGender())
		return true;
	return false;
}

template <class T>
class Interface
{
private:
	T object;
	List<T> list;
public:
	void menu();
};

template <class T>
void Interface<T>::menu()
{
	char nameOfMainMenu[] = "���� ������ � �������";
	char *mainMenuStrings[] = { "��������� ������ �� ���������� �����",
								"��������� ��������� � ��������� ����",
								"��������� ������ �� ��������� �����",
								"��������� ��������� � �������� ����",
								"�������� ������ � ������ ������",
								"�������� ������ � ����� ������",
								"������� ������ �� ������ ������",
								"������� ������ � ����� ������",
								"�������� ������",
								"���������� ������",
								"�������� � �������� ����� 2 ��������",
								"������������� ������",
								"����� �������",
								"����� min �������",
								"����� max �������",
								"��������� ���������� ������������ ����������",
								"�������� ��� ����������",
								"���������� �������� ������ � �������� �������",
								"�������� ������ � ������ �� ������",
								"������� ������ �� ������ �� ������",
								"�����" };
	Menu mainMenu(nameOfMainMenu, mainMenuStrings, sizeof(mainMenuStrings) / sizeof(char*));

	TextFile<T> textFile;
	BinaryFile<T> binaryFile;

	bool goBack = false;
	while (!goBack)
	{
		string fileName;
		goBack = false;
		bool isWrong = true;

		switch (mainMenu.menu()) {
		case 0: //������ �� ����������
			system("cls");

			cout << "* ������� ��� �����: ";

			isWrong = true;
			do {
				fflush(stdin);
				try
				{
					getline(cin, fileName);

					textFile.open(fileName, textFileOpenMode::in);
					list.clear();
					while (true) {
						object = textFile.read();
						if (textFile.eof())
							break;
						list.pushBack(object);
					}
					textFile.close();

					isWrong = false;
				}
				catch (FileException e)
				{
					if (e.getCode() == errorCodes::EndOfFileError)
						break;
					cout << e.what() << endl;
					cout << "1. ��������� ���� ����� �����\n"
						<< "2. ��������� � ����\n"
						<< "��� �����: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\n��������� ���� ����� �����: ";
				}
				catch (...)
				{
					cout << "�������� ����������� ����������.";
					exit(1);
				}
			} while (isWrong);
			break;
		case 1: //������ � ���������
			system("cls");

			cout << "* ������� ��� �����: ";

			isWrong = true;
			do {
				fflush(stdin);
				try
				{
					getline(cin, fileName);

					textFile.open(fileName, textFileOpenMode::out);
					textFile.clearFile();

					ListIterator<T> iterator(list);

					while (iterator != list.end()) {
						textFile.write(*iterator);
						++iterator;
					}
					textFile.close();

					cout << "[ ��������� ��������� ]\n";
					_getch();

					isWrong = false;
				}
				catch (FileException e)
				{
					cout << e.what() << endl;
					cout << "1. ��������� ���� ����� �����\n"
						<< "2. ��������� � ����\n"
						<< "��� �����: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\n��������� ���� ����� �����: ";
				}
				catch (...)
				{
					cout << "�������� ����������� ����������.";
					exit(1);
				}
			} while (isWrong);

			break;
		case 2: //������ �� ���������
			system("cls");

			cout << "* ������� ��� �����: ";

			isWrong = true;
			do {
				fflush(stdin);
				try
				{
					getline(cin, fileName);

					binaryFile.open(fileName, binaryFileOpenMode::inb);
					list.clear();
					while (true) {
						object = binaryFile.read();
						if (binaryFile.eof())
							break;
						list.pushBack(object);
					}
					binaryFile.close();

					isWrong = false;
				}
				catch (FileException e)
				{
					if (e.getCode() == errorCodes::EndOfFileError)
						break;
					cout << e.what() << endl;
					cout << "1. ��������� ���� ����� �����\n"
						<< "2. ��������� � ����\n"
						<< "��� �����: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\n��������� ���� ����� �����: ";
				}
				catch (...)
				{
					cout << "�������� ����������� ����������.";
					exit(1);
				}
			} while (isWrong);
			break;
		case 3: //������ � ��������
			system("cls");

			cout << "* ������� ��� �����: ";

			isWrong = true;
			do {
				fflush(stdin);
				try
				{
					getline(cin, fileName);

					binaryFile.open(fileName, binaryFileOpenMode::outb);
					binaryFile.clearFile();

					ListIterator<T> iterator;
					iterator = list.begin();

					while (iterator != list.end()) {
						binaryFile.write(*iterator);
						iterator++;
					}
					binaryFile.close();

					cout << "[ ��������� ��������� ]\n";
					_getch();

					isWrong = false;
				}
				catch (FileException e)
				{
					cout << e.what() << endl;
					cout << "1. ��������� ���� ����� �����\n"
						<< "2. ��������� � ����\n"
						<< "��� �����: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\n��������� ���� ����� �����: ";
				}
				catch (...)
				{
					cout << "�������� ����������� ����������.";
					exit(1);
				}
			} while (isWrong);

			break;
		case 4:
			system("cls");
			cin >> object;
			list.pushFront(object);
			break;
		case 5:
			system("cls");
			cin >> object;
			list.pushBack(object);
			break;
		case 6:
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
			}
			else {
				list.popFront();
				cout << "���� ������ �� ������.\n";
			}
			_getch();
			break;
		case 7:
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
			}
			else {
				list.popBack();
				cout << "���� ������ �� ������.\n";
			}
			_getch();
			break;
		case 8:
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
			}
			else {
				list.clear();
				cout << "������ ������.\n";
			}
			_getch();
			break;
		case 9: {
			system("cls");

			//for (ListIterator<T> iterator = list.begin(); iterator != list.end(); ++iterator)

			ListIterator<T> iterator = list.begin();

			while (iterator != list.end()) {
				cout << *iterator << endl;
				++iterator;
			}
			//list.printList();
			_getch();
			break;
		}
		case 10:
			system("cls");

			cout << "* ������� ��� �����: ";


			isWrong = true;
			do {
				fflush(stdin);
				try
				{
					getline(cin, fileName);

					binaryFile.open(fileName, binaryFileOpenMode::inb);
					
					cout << "������� ����� ������� �������: ";
					int firstNumber = numberInput<int>(1, INT_MAX);
					cout << "������� ����� ������� �������: ";
					int secondNumber = numberInput<int>(1, INT_MAX);
					
					if (binaryFile.swapTwoEntry(firstNumber, secondNumber))
						cout << "�������\n";
					else 
						cout << "������ �������������� ������\n";
					binaryFile.close();
					_getch();


					isWrong = false;
				}
				catch (FileException e)
				{
					if (e.getCode() == errorCodes::EndOfFileError)
						break;
					cout << e.what() << endl;
					cout << "1. ��������� ���� ����� �����\n"
						<< "2. ��������� � ����\n"
						<< "��� �����: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\n��������� ���� ����� �����: ";
				}
				catch (...)
				{
					cout << "�������� ����������� ����������.";
					exit(1);
				}
			} while (isWrong);

			break;
		case 11:
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
				_getch();
				break;
			}
			sort(list.begin(), list.end());
			cout << "[ ������ ������������ ]\n";
			_getch();
			break;
		case 12: {
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
				_getch();
				break;
			}

			/*T object("������", "������", "����������", Person::initDate(5, 5, 1998), male, "����");
			ListIterator<T> result = findElement(list.begin(), list.end(), object, compare);*/

			const type_info &t = typeid(T);
			const char *typeName = t.name();

			ListIterator<T> result;
			if (!strcmp(typeName, "class Footballer")) {
				Footballer footballer("", "������", "", Person::initDate(0, 1, 0), gender::male, "");
				result = findElement(list.begin(), list.end(), footballer);
			}
			else {
				T object = *(list.begin());
				result = findElement(list.begin(), list.end(), object);
			}

			//ListIterator<T> result = findElement(list.begin(), list.end(), T());
			cout << "������� ";
			if (result == list.end())
				cout << "�� ������.\n";
			else {
				cout << "������.\n";
				cout << *result << endl;
			}
			_getch();
			break;
		}
		case 13: {
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
				_getch();
				break;
			}
			ListIterator<T> result = findMin(list.begin(), list.end());
			cout << "\t\t\t[ ����������� ������� ������ ]\n" << *result << endl;
			_getch();
			break;
		}
		case 14: {
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
				_getch();
				break;
			}
			ListIterator<T> result = findMax(list.begin(), list.end());
			cout << "\t\t\t[ ������������ ������� ������ ]\n" << *result << endl;
			_getch();
			break;
		}
		case 15: {
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
				_getch();
				break;
			}
			T firstObject = *list.begin();
			fillData(list.begin(), list.begin() + 2, firstObject);
			fillData(list.begin() + 3, list.end(), firstObject);
			cout << "\t\t\t[ ������ ������������ ]\n";
			_getch();
			break;
		}
		case 16: {
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
				_getch();
				break;
			}
			bool result = equal(list.begin(), list.begin() + 2, list.begin() + 3);
			//bool result = equal(list.begin(), list.begin() + 2, list.begin() + 3, list.end());
			cout << "���������� ";
			if (result)
				cout << "�����.";
			else
				cout << "�� �����.";

			cout << endl;
			_getch();
			break;
		}
		case 17: {
			system("cls");
			if (list.isEmpty()) {
				cout << "������ ����!\n";
				_getch();
				break;
			}
			reverseElements(list.begin(), list.end());
			cout << "\t\t\t[ ������ ����������� � �������� ������� ]\n";
			_getch();
			break;
		}
		case 18: {
			system("cls");
			cout << "������� ����� �������, �� ����� �������� ����� �������� ����� ";
			int number = numberInputWithBrackets<int>(1, list.size() + 1) - 1;
			cout << "������� ����� ������:\n";
			cin >> object;
			list.insert(list.begin() + number, object);
			break;
		}
		case 19: {
			system("cls");
			cout << "������� ����� �������, ������� ���������� ������� ";
			int number = numberInputWithBrackets<int>(1, list.size()) - 1;
			list.erase(list.begin() + number);
			break;
		}
		case 20:
			goBack = true;
			break;
		}
	}
}

#endif