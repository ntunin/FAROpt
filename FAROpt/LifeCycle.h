#pragma once
#include "ConsoleScreen.h"

class LifeCycle: ConsoleScreen
{
private:
	bool finished = false;
	void exit();
	void printMain();
public:
	void run();
	LifeCycle();
	~LifeCycle();
};

