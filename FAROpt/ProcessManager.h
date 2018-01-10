#pragma once
#include <queue>
#include "ProcessRunner.h"
#include <mutex> 

class ProcessManager {
private: 
	std::queue<ProcessRunner *> queuedRunners;
	int countOfDispatched;
	void ping();
public:
	virtual int getCoresCount() = 0;
	void run(ProcessRunner *runner);
	ProcessManager();
	~ProcessManager();
};

