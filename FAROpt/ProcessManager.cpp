#include "stdafx.h"
#include "ProcessManager.h"
#include <mutex> 

using namespace std;

mutex processManagerMtx;

ProcessManager::ProcessManager() {
	this->countOfDispatched = 0;
}


ProcessManager::~ProcessManager()
{
}


void ProcessManager::run(ProcessRunner *runner) {
	unique_lock<mutex> lck(processManagerMtx, defer_lock);
	lck.lock();
	this->queuedRunners.push(runner);
	lck.unlock();
	this->ping();
}

void ProcessManager::ping() {
	if (this->queuedRunners.size() == 0) {
		return;
	}
	ProcessRunner *runner = NULL;
	unique_lock<mutex> lck(processManagerMtx, defer_lock);
	lck.lock();
	int coresCount = this->getCoresCount();
	if (countOfDispatched < coresCount) {
		runner = this->queuedRunners.front();
		this->queuedRunners.pop();
	}
	lck.unlock();
	if (runner != NULL) {
		lck.lock();
		this->countOfDispatched++;
		lck.unlock();
		runner->dispatch();
		lck.lock();
		this->countOfDispatched--;
		lck.unlock();
		this->ping();
	}
}

