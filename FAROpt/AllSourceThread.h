#pragma once
#include "LamdaOptimisator.h"
#include "ProcessRunner.h"

class AllSourceThread: public ProcessRunner
{
public:
	AllSourceThread(LamdaOptimisator *optimisator, LamdaOptimisator::Optimisation *optimisation, const char *fileName, NecOut *out);
	void run();
	~AllSourceThread();

	NecOut *getOut();
private:
	LamdaOptimisator *optimisator;
	LamdaOptimisator::Optimisation *optimisation;
	std::string fileName;
	NecOut *out;
	int sourceNumber;
};

