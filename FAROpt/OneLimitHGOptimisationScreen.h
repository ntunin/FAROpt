#pragma once
#include "OptimisationScreen.h"
class OneLimitHGOptimisationScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	OneLimitHGOptimisationScreen();
	~OneLimitHGOptimisationScreen();
};

