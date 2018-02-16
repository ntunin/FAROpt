#pragma once
#include "Log.h"
#include <mutex> 
class FileLog :
	public Log
{
private:
	std::ofstream *file;
	std::mutex consoleMtx;
public:
	void print(ComplexMatrix &m);
	void print(double **m, int size);
	void print(ComplexVector &v);
	void print(double *v, int size);
	void print(std::string &m);
	void print(const char *m);
	void print(double d);
	void print(double d, int size);
	void reset();
	FileLog(std::string path);
	~FileLog();
};

