#pragma once
#include "ComplexMatrix.h"
#include "ComplexVector.h"
class Log
{
public:
	Log();
	virtual void print(ComplexMatrix &m) = 0;
	virtual void print(double **m, int size) = 0;
	virtual void print(ComplexVector &v) = 0;
	virtual void print(double *v, int size) = 0;
	virtual void print(std::string &m) = 0;
	virtual void print(const char *m) = 0;
	virtual void print(double d) = 0;
	virtual void reset() = 0;

	~Log();
};

