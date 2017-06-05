#pragma warning( disable : 4290 )

#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include "TemplateFunction.h"

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

enum errorCodes { 
	              DifferentLanguagesError = 101, 
	              WrongSymbolError, 
	              EmptyStringError,
				  RangeError,
				  FileNotOpenError,
				  WrongFileModeError,
				  EndOfFileError,
				  FileReadingError
				};

class Exception
{
protected:
	string type;
	errorCodes code;
public:
	Exception(string type, errorCodes code);
	virtual string what() const;
	virtual errorCodes getCode() const;
};

class InputValidationException : public Exception
{
private:
	string message;
public:
	InputValidationException(string type, errorCodes code, string message);

	string what() const;
};

class ContainerException : public Exception
{
private:
	string message;
public:
	ContainerException(string type, errorCodes code, string message);

	string what() const;
};

class FileException : public Exception
{
private:
	string message;
public:
	FileException(string type, errorCodes code, string message);

	string what() const;
};

//Объявление функций
string stringInput() throw (InputValidationException);   //Алма-КТЖ; АБ Аргир
string stringWithNumbersInput() throw (InputValidationException);   //Алма-КТЖ; АБ Аргир; Авеллино 1912
string wordInput() throw (InputValidationException);   //word; Word; wOrD; слово; СлоВо; все-таки
string nameInput() throw (InputValidationException);   //Mikhadziuk, Dunin-Marcinkiewicz, Михадюк, Дунин-Мартинекевич

#endif




















#pragma warning (disable : 4018)