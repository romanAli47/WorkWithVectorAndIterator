#ifndef MYEXCEPTIONS_CPP
#define MYEXCEPTIONS_CPP

#include "MyExceptions.h"

#include <stdio.h>

Exception::Exception(string type, errorCodes code)
{
	this->type = type;
	this->code = code;
}

string Exception::what() const
{
	stringstream s;
	s << type << " " << code << ".";

	return s.str();
}

errorCodes Exception::getCode() const
{
	return code;
}

InputValidationException::InputValidationException(string type, errorCodes code, string message) : Exception(type, code)
{
	this->message = message;
}

string InputValidationException::what() const
{
	return Exception::what() + " " + message;
}

ContainerException::ContainerException(string type, errorCodes code, string message) : Exception(type, code)
{
	this->message = message;
}

string ContainerException::what() const
{
	return Exception::what() + " " + message;
}

FileException::FileException(string type, errorCodes code, string message) : Exception(type, code)
{
	this->message = message;
}

string FileException::what() const
{
	return Exception::what() + " " + message;
}

//�������� �������
string stringInput() throw (InputValidationException)
{
	string result;
	bool isWrong = true;

	do {
		fflush(stdin);
		bool wasEnglishCharacter = false;
		bool wasRussianCharacter = false;
		try
		{
			getline(cin, result);
			if (result.empty()) {
				throw InputValidationException("Error", EmptyStringError, "������ �� ����� ���� ������.");
			}
			for (int i = 0; i < result.size(); i++) {
				bool isLetter = false;
				if ((result[i] >= '�' && result[i] <= '�') || (result[i] >= '�' && result[i] <= '�')) {
					wasRussianCharacter = true;
					isLetter = true;
				}
				else if ((result[i] >= 'A' && result[i] <= 'Z') || (result[i] >= 'a' && result[i] <= 'z')) {
					wasEnglishCharacter = true;
					isLetter = true;
				}

				if (wasRussianCharacter && wasEnglishCharacter)
					throw InputValidationException("Error", DifferentLanguagesError, "�� ������ ������������ ��� ����� ���� ������ ����������, ���� ������ ������� ����.");

				if (!isLetter && !(result[i] == ' ' || result[i] == '-'))
					throw InputValidationException("Error", WrongSymbolError, "�� ������ ������������ ��� ����� ���� ������ ����������, ���� ������ ������� ���� � ������� '-' � ' '.");
			}
			isWrong = false;
		}
		catch (InputValidationException e)
		{
			cout << e.what() << endl;
			cout << "��������� ����: ";
		}
		catch (...)
		{
			cout << "�������� ����������� ����������.";
			exit(1);
		}
	} while (isWrong);

	return result;
}

string stringWithNumbersInput() throw (InputValidationException)
{
	string result;
	bool isWrong = true;

	do {
		fflush(stdin);
		bool wasEnglishCharacter = false;
		bool wasRussianCharacter = false;
		try
		{
			getline(cin, result);
			if (result.empty()) {
				throw InputValidationException("Error", EmptyStringError, "������ �� ����� ���� ������.");
			}
			for (int i = 0; i < result.size(); i++) {
				bool isLetter = false;
				if ((result[i] >= '�' && result[i] <= '�') || (result[i] >= '�' && result[i] <= '�')) {
					wasRussianCharacter = true;
					isLetter = true;
				}
				else if ((result[i] >= 'A' && result[i] <= 'Z') || (result[i] >= 'a' && result[i] <= 'z')) {
					wasEnglishCharacter = true;
					isLetter = true;
				}

				if (wasRussianCharacter && wasEnglishCharacter)
					throw InputValidationException("Error", DifferentLanguagesError, "�� ������ ������������ ��� ����� ���� ������ ����������, ���� ������ ������� ����.");
				if (!isLetter && !(result[i] == ' ' || result[i] == '-' || (result[i] >= '0' && result[i] <= '9')))
					throw InputValidationException("Error", WrongSymbolError, "�� ������ ������������ ��� ����� ���� ������ ����������, ���� ������ ������� ����, ����� � ������� '-' � ' '.");
			}
			isWrong = false;
		}
		catch (InputValidationException e)
		{
			cout << e.what() << endl;
			cout << "��������� ����: ";
		}
		catch (...)
		{
			cout << "�������� ����������� ����������.";
			exit(1);
		}
	} while (isWrong);

	return result;
}

string wordInput() throw (InputValidationException)
{
	string result;
	bool isWrong = true;

	do {
		fflush(stdin);
		bool wasEnglishCharacter = false;
		bool wasRussianCharacter = false;
		try
		{
			getline(cin, result);
			if (result.empty()) {
				throw InputValidationException("Error", EmptyStringError, "������ �� ����� ���� ������.");
			}
			for (int i = 0; i < result.size(); i++) {
				bool isLetter = false;
				if ((result[i] >= '�' && result[i] <= '�') || (result[i] >= '�' && result[i] <= '�')) {
					wasRussianCharacter = true;
					isLetter = true;
				}
				else if ((result[i] >= 'A' && result[i] <= 'Z') || (result[i] >= 'a' && result[i] <= 'z')) {
					wasEnglishCharacter = true;
					isLetter = true;
				}

				if (wasRussianCharacter && wasEnglishCharacter)
					throw InputValidationException("Error", DifferentLanguagesError, "�� ������ ������������ ��� ����� ���� ������ ����������, ���� ������ ������� ����.");

				if (!isLetter && result[i] != '-')
					throw InputValidationException("Error", WrongSymbolError, "�� ������ ������������ ��� ����� ���� ������ ����������, ���� ������ ������� ���� � ������ '-'.");
			}
			isWrong = false;
		}
		catch (InputValidationException e)
		{
			cout << e.what() << endl;
			cout << "��������� ����: ";
		}
		catch (...)
		{
			cout << "�������� ����������� ����������.";
			exit(1);
		}
	} while (isWrong);

	return result;
}

string nameInput() throw (InputValidationException)
{
	string result = wordInput();

	bool isNewPart = true;

	for (int i = 0; i < result.size(); i++) {
		if (result[i] == '-') {
			isNewPart = true;
			continue;
		}

		if (isNewPart) {
			if ((result[i] >= '�' && result[i] <= '�'))
				result[i] -= 32;
			else
				result[i] = toupper(result[i]);
			isNewPart = false;
		}
		else {
			if ((result[i] >= '�' && result[i] <= '�'))
				result[i] += 32;
			else
				result[i] = tolower(result[i]);
		}
	}

	return result;
}
#endif