#pragma once
#include "Scanner.h"
class FileScanner :
	public Scanner
{
private:
	std::ifstream *file;
public:
	int readInt(std::string message);
	int readInt();
	std::string readString();
	std::string readString(std::string message);
	double readDouble();
	double readDouble(std::string message);
	bool readBool();
	bool readBool(std::string message);
	FileScanner(std::string path);
	~FileScanner();
};

