#pragma once
#include "TaskManager.h"
class WindowsTaskManager :
	public TaskManager
{
private:
	std::vector<std::thread *> threads;
	int indexOf(Task *task);
public:
	void execute(Task *task);
	void wait(Task *task);
	WindowsTaskManager();
	~WindowsTaskManager();
};

