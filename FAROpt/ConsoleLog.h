#pragma once
#include "Log.h"
#include <mutex> 


class ConsoleLog :
	public Log
{
public:
	ConsoleLog();
	void print(ComplexMatrix &m);
	void print(double **m, int size);
	void print(ComplexVector &v);
	void print(double *v, int size);
	void print(std::string &m);
	void print(const char *m);
	void print(double d);
	void reset();
	~ConsoleLog();
};

