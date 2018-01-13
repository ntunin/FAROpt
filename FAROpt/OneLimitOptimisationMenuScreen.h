#pragma once
#include "ConsoleScreen.h"
class OneLimitOptimisationMenuScreen :
	public ConsoleScreen
{
private:
	void printHead();
	void run();
public:
	OneLimitOptimisationMenuScreen();
	~OneLimitOptimisationMenuScreen();
};

