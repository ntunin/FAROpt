#pragma once
#include "RandomGenerator.h"
#include <mutex>
#include "Task.h"

class WindowsRandomGenerator :
	public RandomGenerator
{
private:
	class GeneratorTask : public Task {
	private:
		std::mutex randMtx;
		int value;
		int squireIndex;
		bool running;
	public:
		int next();
		void stop();
		void execute();
	};
	GeneratorTask *task;
public:
	int next();
	void stop();
	WindowsRandomGenerator();
	~WindowsRandomGenerator();

};

