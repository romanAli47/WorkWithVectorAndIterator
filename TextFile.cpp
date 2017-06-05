//#ifndef TEXTFILE_CPP
//#define TEXTFILE_CPP
//
//#include "TextFile.h"
//
//template <class T>
//TextFile<T>::TextFile()
//{}
//
//template <class T>
//TextFile<T>::TextFile(string fileName, textFileOpenMode mode)
//{
//	this->fileName = fileName;
//	this->mode = mode;
//
//	int pos = this->fileName.find_last_of(".txt");
//	if (!(this->fileName.find(".txt") != string::npos && pos == this->fileName.length() - 1))
//		this->fileName += ".txt";
//
//	this->file.open(this->fileName, (this->mode == textFileOpenMode::in ? ios::in : ios::out));
//	if (!this->file)
//		throw FileException("Error", FileNotOpenError, "�� ������� ������� ����.");
//}
//
//template <class T>
//void TextFile<T>::open(string fileName, textFileOpenMode mode)
//{
//	if (file.is_open())
//		file.close();
//
//	this->fileName = fileName;
//	this->mode = mode;
//
//	int pos = this->fileName.find_last_of(".txt");
//	if (!(this->fileName.find(".txt") != string::npos && pos == this->fileName.length() - 1))
//		this->fileName += ".txt";
//
//	this->file.open(this->fileName, (this->mode == textFileOpenMode::in ? ios::in : ios::out | ios::app));
//	if (!this->file)
//		throw FileException("Error", FileNotOpenError, "�� ������� ������� ����.");
//}
//
//template <class T>
//void TextFile<T>::close()
//{
//	if (!this->file.is_open())
//		throw FileException("Error", FileNotOpenError, "���� �� ������.");
//	this->file.close();
//}
//
//template <class T>
//bool TextFile<T>::eof()
//{
//	if (!this->file.is_open())
//		throw FileException("Error", FileNotOpenError, "���� �� ������.");
//	return this->file.eof();
//}
//
//template <class T>
//T TextFile<T>::read()
//{
//	T distinationObject;
//
//	if (!this->file.is_open())
//		throw FileException("Error", FileNotOpenError, "���� �� ������.");
//	if (mode == textFileOpenMode::out)
//		throw FileException("Error", WrongFileModeError, "���������� ��������� ������ �� �����, ��� ��� �� ������ ��� ������.");
//	if (this->eof())
//		throw FileException("Error", EndOfFileError, "����� �����. ��� ������ ��� ������.");
//
//	this->file >> distinationObject;
//	if (this->eof())
//		throw FileException("Error", EndOfFileError, "����� �����. ��� ������ ��� ������.");
//	if (!this->file)
//		throw FileException("Error", FileReadingError, "������ ��� ������ ������ �� �����.");
//
//	return distinationObject;
//}
//
//template <class T>
//void TextFile<T>::write(const T &object)
//{
//	if (!this->file.is_open())
//		throw FileException("Error", FileNotOpenError, "���� �� ������.");
//	if (mode == textFileOpenMode::in)
//		throw FileException("Error", WrongFileModeError, "���������� �������� ������ � ����, ��� ��� �� ������ ��� ������.");
//
//	this->file << object;
//}
//
//template <class T>
//void TextFile<T>::clearFile()
//{
//	if (!this->file.is_open())
//		throw FileException("Error", FileNotOpenError, "���� �� ������.");
//	this->file.close();
//	this->file.open(this->fileName, ios::out);
//	this->file.close();
//	this->open(this->fileName, this->mode);
//}
//
//template<class T>
//void TextFile<T>::toBegin()
//{
//	if (!this->file.is_open())
//		throw FileException("Error", FileNotOpenError, "���� �� ������.");
//	this->file.seekg(ios_base::beg);
//	this->file.seekp(ios_base::beg);
//}
//
//template<class T>
//void TextFile<T>::toEnd()
//{
//	if (!this->file.is_open())
//		throw FileException("Error", FileNotOpenError, "���� �� ������.");
//	this->file.seekg(ios_base::end);
//	this->file.seekp(ios_base::end);
//}
//
//#endif