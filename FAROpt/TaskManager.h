#pragma once
#include "Task.h"
class TaskManager
{
public:
	virtual void execute(Task *task) = 0;
	virtual void wait(Task *task) = 0;
	TaskManager();
	~TaskManager();
};

