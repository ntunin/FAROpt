#pragma once
#include "Scanner.h"
class PredefinedScanner :
	public Scanner
{
private:
	int index;
	int offset;
	std::vector<std::string> results;
	std::stringstream next();
public:
	int readInt(std::string message);
	int readInt();
	std::string readString();
	std::string readString(std::string message);
	double readDouble();
	double readDouble(std::string message);
	bool readBool();
	bool readBool(std::string message);
	PredefinedScanner();
	~PredefinedScanner();
};

