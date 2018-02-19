#include "stdafx.h"
#include "WindowsRandomGenerator.h"

using namespace std;

WindowsRandomGenerator::WindowsRandomGenerator() {
	task = new GeneratorTask;
	Shared::bundle().taskManager()->execute(task);
}

void WindowsRandomGenerator::stop() {
	task->stop();
}

int WindowsRandomGenerator::next() {
	return task->next();
}

void WindowsRandomGenerator::GeneratorTask::execute() {
	unique_lock<mutex> lck(randMtx, defer_lock);
	lck.lock();
	running = true;
	lck.unlock();
	while (running) {
		lck.lock();
		value = rand();
		lck.unlock();
	}
}

void WindowsRandomGenerator::GeneratorTask::stop() {
	unique_lock<mutex> lck(randMtx, defer_lock);
	lck.lock();
	running = false;
	lck.unlock();
}

int WindowsRandomGenerator::GeneratorTask::next() {
	unique_lock<mutex> lck(randMtx, defer_lock);
	lck.lock();
	int v = value;
	value = rand();
	lck.unlock();
	return v;
}


WindowsRandomGenerator::~WindowsRandomGenerator()
{
}
