#pragma once
#include "ConsoleScreen.h"
class FullLimitOptimisationMenuScreen :
	public ConsoleScreen
{
private:
	void printHead();
	void run();
public:
	FullLimitOptimisationMenuScreen();
	~FullLimitOptimisationMenuScreen();
};

