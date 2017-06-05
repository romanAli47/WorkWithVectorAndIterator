//#ifndef INTEERFACE_CPP
//#define INTEERFACE_CPP
//
//#include "Interface.h"
//
//template <class T>
//void Interface<T>::menu()
//{
//	char nameOfMainMenu[] = "Меню работы с данными";
//	char *mainMenuStrings[] = { "Прочитать данные из файла",
//								"Сохранить изменения",
//								"Добавить данные в начало списка",
//								"Добавить данные в конец списка",
//								"Удалить данные из начала списка",
//								"Удалить данные с конца списка",
//								"Очистить список",
//								"Посмотреть список",
//								"Назад" };
//	Menu mainMenu(nameOfMainMenu, mainMenuStrings, sizeof(mainMenuStrings) / sizeof(char*));
//
//	TextFile<T> textFile;
//
//	bool goBack = false;
//	while (!goBack)
//	{
//		string fileName;
//		goBack = false;
//		bool isWrong = true;
//
//		switch (mainMenu.menu()) {
//		case 0:
//			system("cls");
//
//			cout << "* Введите имя файла: ";
//
//			isWrong = true;
//			do {
//				fflush(stdin);
//				try
//				{
//					getline(cin, fileName);
//
//					textFile.open(fileName, textFileOpenMode::in);
//					while (true) {
//						object = textFile.read();
//						if (textFile.eof())
//							break;
//						list.pushBack(object);
//					}
//					textFile.close();
//
//					isWrong = false;
//				}
//				catch (FileException e)
//				{
//					if (e.getCode() == errorCodes::EndOfFileError)
//						break;
//					cout << e.what() << endl;
//					cout << "1. Повторить ввод имени файла\n"
//						<< "2. Вернуться в меню\n"
//						<< "Ваш выбор: ";
//					int choise = numberInput<int>(1, 2);
//					cin.get();
//					if (choise == 2)
//						break;
//					cout << "\nПовторите ввод имени файла: ";
//				}
//				catch (...)
//				{
//					cout << "Возникло неизвестное исключение.";
//					exit(1);
//				}
//			} while (isWrong);
//			break;
//		case 1:
//			system("cls");
//
//			cout << "* Введите имя файла: ";
//
//			isWrong = true;
//			do {
//				fflush(stdin);
//				try
//				{
//					getline(cin, fileName);
//
//					textFile.open(fileName, textFileOpenMode::out);
//					textFile.clearFile();
//
//					while (!list.isEmpty()) {
//						object = list.popFront();
//						textFile.write(object);
//					}
//					textFile.close();
//
//					cout << "[ Изменения сохранены ]\n";
//					_getch();
//
//					isWrong = false;
//				}
//				catch (FileException e)
//				{
//					cout << e.what() << endl;
//					cout << "1. Повторить ввод имени файла\n"
//						<< "2. Вернуться в меню\n"
//						<< "Ваш выбор: ";
//					int choise = numberInput<int>(1, 2);
//					cin.get();
//					if (choise == 2)
//						break;
//					cout << "\nПовторите ввод имени файла: ";
//				}
//				catch (...)
//				{
//					cout << "Возникло неизвестное исключение.";
//					exit(1);
//				}
//			} while (isWrong);
//
//			break;
//		case 2:
//			system("cls");
//			cin >> object;
//			list.pushFront(object);
//			break;
//		case 3:
//			system("cls");
//			cin >> object;
//			list.pushBack(object);
//			break;
//		case 4:
//			system("cls");
//			if (list.isEmpty()) {
//				cout << "Список пуст!\n";
//			}
//			else {
//				list.popFront();
//				cout << "Теннисист удален из списка.\n";
//			}
//			_getch();
//			break;
//		case 5:
//			system("cls");
//			if (list.isEmpty()) {
//				cout << "Список пуст!\n";
//			}
//			else {
//				list.popBack();
//				cout << "Теннисист удален из списка.\n";
//			}
//			_getch();
//			break;
//		case 6:
//			system("cls");
//			if (list.isEmpty()) {
//				cout << "Список пуст!\n";
//			}
//			else {
//				list.clear();
//				cout << "Список очищен.\n";
//			}
//			_getch();
//			break;
//		case 7:
//			system("cls");
//			if (list.isEmpty()) {
//				cout << "Список пуст!\n";
//			}
//			else {
//				const int dashCount = 96;
//				cout << "\t\t\t\t\t[ Список теннисистов ]\n";
//				for (int i = 0; i < dashCount; i++) cout << '='; cout << endl;
//				cout << "|                     ФИО                    |  Дата рождения  | Пол |     Место тренировок    |\n";
//				list.showList();
//				for (int i = 0; i < dashCount; i++) cout << '='; cout << endl;
//			}
//			_getch();
//			break;
//		case 8:
//			goBack = true;
//			break;
//		}
//	}
//}
//
//#endif