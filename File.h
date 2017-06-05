#ifndef FILE_H
#define FILE_H

#include "MyExceptions.h"

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class File
{
protected:
	string fileName;
	fstream file;
public:
	virtual void close() = 0;
};

#endif