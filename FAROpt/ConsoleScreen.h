#pragma once
#include "ComplexVector.h"

class ConsoleScreen
{
public:
	ConsoleScreen();
	~ConsoleScreen();
	void reset();
	void print(std::string message);
	void print(const char *message);
	void print(ComplexVector *v);
	void print(int size, double *v);
	void print(int size, double **m);
	void print(double d);
	std::string readString(std::string message);
	int readInt(std::string message);
};

