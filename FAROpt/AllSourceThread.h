#pragma once
#include "ProcessRunner.h"
#include "NecIn.h"
#include "ComplexVector.h"

class AllSourceThread: public ProcessRunner
{
public:
	AllSourceThread(NecIn *in, ComplexVector *sources, const char *fileName, NecOut *out);
	~AllSourceThread(); 
	void dispatch();
	NecOut *getOut();
private:
	NecIn *in;
	ComplexVector *sources;
	std::string fileName;
	NecOut *out;
	int sourceNumber;
};

