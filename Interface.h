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
	char nameOfMainMenu[] = "Меню работы с данными";
	char *mainMenuStrings[] = { "Прочитать данные из текстового файла",
								"Сохранить изменения в текстовый файл",
								"Прочитать данные из бинарного файла",
								"Сохранить изменения в бинарный файл",
								"Добавить данные в начало списка",
								"Добавить данные в конец списка",
								"Удалить данные из начала списка",
								"Удалить данные с конца списка",
								"Очистить список",
								"Посмотреть список",
								"Поменять в бинарном файле 2 элемента",
								"Отсортировать список",
								"Найти элемент",
								"Найти min элемент",
								"Найти max элемент",
								"Заполнить промежутки определнными значениями",
								"Сравнить два промежутка",
								"Расставить элементы списка в обратном порядке",
								"Добавить данные в список по номеру",
								"Удалить данные из списка по номеру",
								"Назад" };
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
		case 0: //Четние из текстового
			system("cls");

			cout << "* Введите имя файла: ";

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
					cout << "1. Повторить ввод имени файла\n"
						<< "2. Вернуться в меню\n"
						<< "Ваш выбор: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\nПовторите ввод имени файла: ";
				}
				catch (...)
				{
					cout << "Возникло неизвестное исключение.";
					exit(1);
				}
			} while (isWrong);
			break;
		case 1: //Запись в текстовый
			system("cls");

			cout << "* Введите имя файла: ";

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

					cout << "[ Изменения сохранены ]\n";
					_getch();

					isWrong = false;
				}
				catch (FileException e)
				{
					cout << e.what() << endl;
					cout << "1. Повторить ввод имени файла\n"
						<< "2. Вернуться в меню\n"
						<< "Ваш выбор: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\nПовторите ввод имени файла: ";
				}
				catch (...)
				{
					cout << "Возникло неизвестное исключение.";
					exit(1);
				}
			} while (isWrong);

			break;
		case 2: //Четние из бинарного
			system("cls");

			cout << "* Введите имя файла: ";

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
					cout << "1. Повторить ввод имени файла\n"
						<< "2. Вернуться в меню\n"
						<< "Ваш выбор: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\nПовторите ввод имени файла: ";
				}
				catch (...)
				{
					cout << "Возникло неизвестное исключение.";
					exit(1);
				}
			} while (isWrong);
			break;
		case 3: //Запись в бинарный
			system("cls");

			cout << "* Введите имя файла: ";

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

					cout << "[ Изменения сохранены ]\n";
					_getch();

					isWrong = false;
				}
				catch (FileException e)
				{
					cout << e.what() << endl;
					cout << "1. Повторить ввод имени файла\n"
						<< "2. Вернуться в меню\n"
						<< "Ваш выбор: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\nПовторите ввод имени файла: ";
				}
				catch (...)
				{
					cout << "Возникло неизвестное исключение.";
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
				cout << "Список пуст!\n";
			}
			else {
				list.popFront();
				cout << "Узел удален из списка.\n";
			}
			_getch();
			break;
		case 7:
			system("cls");
			if (list.isEmpty()) {
				cout << "Список пуст!\n";
			}
			else {
				list.popBack();
				cout << "Узел удален из списка.\n";
			}
			_getch();
			break;
		case 8:
			system("cls");
			if (list.isEmpty()) {
				cout << "Список пуст!\n";
			}
			else {
				list.clear();
				cout << "Список очищен.\n";
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

			cout << "* Введите имя файла: ";


			isWrong = true;
			do {
				fflush(stdin);
				try
				{
					getline(cin, fileName);

					binaryFile.open(fileName, binaryFileOpenMode::inb);
					
					cout << "Введите номер первого объекта: ";
					int firstNumber = numberInput<int>(1, INT_MAX);
					cout << "Введите номер второго объекта: ";
					int secondNumber = numberInput<int>(1, INT_MAX);
					
					if (binaryFile.swapTwoEntry(firstNumber, secondNumber))
						cout << "Поменял\n";
					else 
						cout << "Введен несуществующий индекс\n";
					binaryFile.close();
					_getch();


					isWrong = false;
				}
				catch (FileException e)
				{
					if (e.getCode() == errorCodes::EndOfFileError)
						break;
					cout << e.what() << endl;
					cout << "1. Повторить ввод имени файла\n"
						<< "2. Вернуться в меню\n"
						<< "Ваш выбор: ";
					int choise = numberInput<int>(1, 2);
					cin.get();
					if (choise == 2)
						break;
					cout << "\nПовторите ввод имени файла: ";
				}
				catch (...)
				{
					cout << "Возникло неизвестное исключение.";
					exit(1);
				}
			} while (isWrong);

			break;
		case 11:
			system("cls");
			if (list.isEmpty()) {
				cout << "Список пуст!\n";
				_getch();
				break;
			}
			sort(list.begin(), list.end());
			cout << "[ Список отсортирован ]\n";
			_getch();
			break;
		case 12: {
			system("cls");
			if (list.isEmpty()) {
				cout << "Список пуст!\n";
				_getch();
				break;
			}

			/*T object("Петров", "Кирилл", "Алексеевич", Person::initDate(5, 5, 1998), male, "Реал");
			ListIterator<T> result = findElement(list.begin(), list.end(), object, compare);*/

			const type_info &t = typeid(T);
			const char *typeName = t.name();

			ListIterator<T> result;
			if (!strcmp(typeName, "class Footballer")) {
				Footballer footballer("", "Кирилл", "", Person::initDate(0, 1, 0), gender::male, "");
				result = findElement(list.begin(), list.end(), footballer);
			}
			else {
				T object = *(list.begin());
				result = findElement(list.begin(), list.end(), object);
			}

			//ListIterator<T> result = findElement(list.begin(), list.end(), T());
			cout << "Элемент ";
			if (result == list.end())
				cout << "не найден.\n";
			else {
				cout << "найден.\n";
				cout << *result << endl;
			}
			_getch();
			break;
		}
		case 13: {
			system("cls");
			if (list.isEmpty()) {
				cout << "Список пуст!\n";
				_getch();
				break;
			}
			ListIterator<T> result = findMin(list.begin(), list.end());
			cout << "\t\t\t[ Минимальный элемент списка ]\n" << *result << endl;
			_getch();
			break;
		}
		case 14: {
			system("cls");
			if (list.isEmpty()) {
				cout << "Список пуст!\n";
				_getch();
				break;
			}
			ListIterator<T> result = findMax(list.begin(), list.end());
			cout << "\t\t\t[ Максимальный элемент списка ]\n" << *result << endl;
			_getch();
			break;
		}
		case 15: {
			system("cls");
			if (list.isEmpty()) {
				cout << "Список пуст!\n";
				_getch();
				break;
			}
			T firstObject = *list.begin();
			fillData(list.begin(), list.begin() + 2, firstObject);
			fillData(list.begin() + 3, list.end(), firstObject);
			cout << "\t\t\t[ Данные перезаписаны ]\n";
			_getch();
			break;
		}
		case 16: {
			system("cls");
			if (list.isEmpty()) {
				cout << "Список пуст!\n";
				_getch();
				break;
			}
			bool result = equal(list.begin(), list.begin() + 2, list.begin() + 3);
			//bool result = equal(list.begin(), list.begin() + 2, list.begin() + 3, list.end());
			cout << "Промежутки ";
			if (result)
				cout << "равны.";
			else
				cout << "не равны.";

			cout << endl;
			_getch();
			break;
		}
		case 17: {
			system("cls");
			if (list.isEmpty()) {
				cout << "Список пуст!\n";
				_getch();
				break;
			}
			reverseElements(list.begin(), list.end());
			cout << "\t\t\t[ Данные расставлены в обратном порядке ]\n";
			_getch();
			break;
		}
		case 18: {
			system("cls");
			cout << "Введите номер элемент, на место которого нужно добавить новый ";
			int number = numberInputWithBrackets<int>(1, list.size() + 1) - 1;
			cout << "Введите новые данные:\n";
			cin >> object;
			list.insert(list.begin() + number, object);
			break;
		}
		case 19: {
			system("cls");
			cout << "Введите номер элемент, который необходимо удалить ";
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