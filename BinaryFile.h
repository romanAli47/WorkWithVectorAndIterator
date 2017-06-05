#ifndef BINARYFILE_H
#define BINARYFILE_H

#include "File.h"

enum binaryFileOpenMode {inb, outb};

template <class T>
class BinaryFile : public File
{
private:
	binaryFileOpenMode mode;
public:
	BinaryFile();
	BinaryFile(string fileName, binaryFileOpenMode mode);
	void open(string fileName, binaryFileOpenMode mode);
	void close();
	bool eof();
	T read();
	void write(T &object);

	void clearFile();
	void toBegin();
	void toEnd();

	bool swapTwoEntry(int firstNumber, int secondNumber);
};

template <class T>
BinaryFile<T>::BinaryFile()
{}

template <class T>
BinaryFile<T>::BinaryFile(string fileName, binaryFileOpenMode mode)
{
	this->fileName = fileName;
	this->mode = mode;

	this->file.open(this->fileName, (this->mode == binaryFileOpenMode::inb ? ios::in : ios::out) | ios::binary);
	if (!this->file)
		throw FileException("Error", FileNotOpenError, "Не удалось открыть файл.");
}

template <class T>
void BinaryFile<T>::open(string fileName, binaryFileOpenMode mode)
{
	if (file.is_open())
		file.close();

	this->fileName = fileName;
	this->mode = mode;

	this->file.open(this->fileName, (this->mode == binaryFileOpenMode::inb ? ios::in : ios::out) | ios::binary);
	if (!this->file)
		throw FileException("Error", FileNotOpenError, "Не удалось открыть файл.");
}

template <class T>
void BinaryFile<T>::close()
{
	if (!this->file.is_open())
		throw FileException("Error", FileNotOpenError, "Файл не открыт.");
	this->file.close();
}

template <class T>
bool BinaryFile<T>::eof()
{
	if (!this->file.is_open())
		throw FileException("Error", FileNotOpenError, "Файл не открыт.");
	return this->file.eof();
}

template <class T>
T BinaryFile<T>::read()
{
	T distinationObject;

	if (!this->file.is_open())
		throw FileException("Error", FileNotOpenError, "Файл не открыт.");
	if (mode == binaryFileOpenMode::outb)
		throw FileException("Error", WrongFileModeError, "Невозможно прочитать данные из файла, так как он открыт для записи.");
	if (this->eof())
		throw FileException("Error", EndOfFileError, "Конец файла. Нет данных для чтения.");

	this->file.read(reinterpret_cast<char*>(&distinationObject), sizeof(T));

	if (this->eof())
		throw FileException("Error", EndOfFileError, "Конец файла. Нет данных для чтения.");
	if (!this->file)
		throw FileException("Error", FileReadingError, "Ошибка при чтении данных из файла.");

	return distinationObject;
}

template <class T>
void BinaryFile<T>::write(T &object)
{
	if (!this->file.is_open())
		throw FileException("Error", FileNotOpenError, "Файл не открыт.");
	if (mode == binaryFileOpenMode::inb)
		throw FileException("Error", WrongFileModeError, "Невозможно записать данные в файл, так как он открыт для чтения.");

	this->file.write(reinterpret_cast<char*>(&object), sizeof(T));
}

template <class T>
void BinaryFile<T>::clearFile()
{
	if (!this->file.is_open())
		throw FileException("Error", FileNotOpenError, "Файл не открыт.");

	this->file.close();
	this->file.open(this->fileName, ios::out | ios::binary);
	this->file.close();
	this->open(this->fileName, this->mode);
}

template<class T>
void BinaryFile<T>::toBegin()
{
	if (!this->file.is_open())
		throw FileException("Error", FileNotOpenError, "Файл не открыт.");
	this->file.seekg(ios_base::beg);
	this->file.seekp(ios_base::beg);
}

template<class T>
void BinaryFile<T>::toEnd()
{
	if (!this->file.is_open())
		throw FileException("Error", FileNotOpenError, "Файл не открыт.");
	this->file.seekg(ios_base::end);
	this->file.seekp(ios_base::end);
}

template<class T>
bool BinaryFile<T>::swapTwoEntry(int firstNumber, int secondNumber)
{
	if (!this->file.is_open())
		throw FileException("Error", FileNotOpenError, "Файл не открыт.");

	this->file.seekg(0, ios_base::end);
	int lastPosition = this->file.tellg();
	int elementsNumber = lastPosition / sizeof(T);

	if ((firstNumber < 1 || firstNumber > elementsNumber) || (secondNumber < 1 || secondNumber > elementsNumber))
		return false;

	T firstObject;
	T secondObject;
	firstNumber--;
	secondNumber--;

	this->file.seekg(sizeof(T) * firstNumber, ios_base::beg);
	this->file.read(reinterpret_cast<char*>(&firstObject), sizeof(T));

	this->file.seekg(sizeof(T) * secondNumber, ios_base::beg);
	this->file.read(reinterpret_cast<char*>(&secondObject), sizeof(T));

	this->close();

	this->file.open(this->fileName, ios::in | ios::out | ios::binary);
	
	this->file.seekp(sizeof(T) * firstNumber, ios_base::beg);
	this->file.write(reinterpret_cast<char*>(&secondObject), sizeof(T));

	this->file.seekp(sizeof(T) * secondNumber, ios_base::beg);
	this->file.write(reinterpret_cast<char*>(&firstObject), sizeof(T));

	return true;
}

#endif