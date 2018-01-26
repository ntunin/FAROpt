#pragma once
#include "Scanner.h"
class ConsoleScanner :
	public Scanner
{
public:
	int readInt(std::string message);
	int readInt();
	std::string readString();
	std::string readString(std::string message);
	double readDouble();
	double readDouble(std::string message);
	bool readBool();
	bool readBool(std::string message);
	ConsoleScanner();
	~ConsoleScanner();
};

