#pragma once
#include "NecIn.h"
#include "NecOut.h"
#include "ProcessRunner.h"
#include <thread>
#include <string>

class OneSourceThread: public ProcessRunner
{
public:
	OneSourceThread();
	OneSourceThread(NecIn *in, NecOut *out, int sourceNumber);
	~OneSourceThread();
	std::string createName(std::thread::id id, int number);
	void removeFile(std::string &name);
	void dispatch();
private:
	NecIn *in;
	NecOut *out;
	int sourceNumber;
	void randomize();	
};

