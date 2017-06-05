//#ifndef INTEERFACE_CPP
//#define INTEERFACE_CPP
//
//#include "Interface.h"
//
//template <class T>
//void Interface<T>::menu()
//{
//	char nameOfMainMenu[] = "���� ������ � �������";
//	char *mainMenuStrings[] = { "��������� ������ �� �����",
//								"��������� ���������",
//								"�������� ������ � ������ ������",
//								"�������� ������ � ����� ������",
//								"������� ������ �� ������ ������",
//								"������� ������ � ����� ������",
//								"�������� ������",
//								"���������� ������",
//								"�����" };
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
//			cout << "* ������� ��� �����: ";
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
//					cout << "1. ��������� ���� ����� �����\n"
//						<< "2. ��������� � ����\n"
//						<< "��� �����: ";
//					int choise = numberInput<int>(1, 2);
//					cin.get();
//					if (choise == 2)
//						break;
//					cout << "\n��������� ���� ����� �����: ";
//				}
//				catch (...)
//				{
//					cout << "�������� ����������� ����������.";
//					exit(1);
//				}
//			} while (isWrong);
//			break;
//		case 1:
//			system("cls");
//
//			cout << "* ������� ��� �����: ";
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
//					cout << "[ ��������� ��������� ]\n";
//					_getch();
//
//					isWrong = false;
//				}
//				catch (FileException e)
//				{
//					cout << e.what() << endl;
//					cout << "1. ��������� ���� ����� �����\n"
//						<< "2. ��������� � ����\n"
//						<< "��� �����: ";
//					int choise = numberInput<int>(1, 2);
//					cin.get();
//					if (choise == 2)
//						break;
//					cout << "\n��������� ���� ����� �����: ";
//				}
//				catch (...)
//				{
//					cout << "�������� ����������� ����������.";
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
//				cout << "������ ����!\n";
//			}
//			else {
//				list.popFront();
//				cout << "��������� ������ �� ������.\n";
//			}
//			_getch();
//			break;
//		case 5:
//			system("cls");
//			if (list.isEmpty()) {
//				cout << "������ ����!\n";
//			}
//			else {
//				list.popBack();
//				cout << "��������� ������ �� ������.\n";
//			}
//			_getch();
//			break;
//		case 6:
//			system("cls");
//			if (list.isEmpty()) {
//				cout << "������ ����!\n";
//			}
//			else {
//				list.clear();
//				cout << "������ ������.\n";
//			}
//			_getch();
//			break;
//		case 7:
//			system("cls");
//			if (list.isEmpty()) {
//				cout << "������ ����!\n";
//			}
//			else {
//				const int dashCount = 96;
//				cout << "\t\t\t\t\t[ ������ ����������� ]\n";
//				for (int i = 0; i < dashCount; i++) cout << '='; cout << endl;
//				cout << "|                     ���                    |  ���� ��������  | ��� |     ����� ����������    |\n";
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