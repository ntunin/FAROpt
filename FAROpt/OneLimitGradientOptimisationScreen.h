#pragma once
#include "OptimisationScreen.h"
class OneLimitGradientOptimisationScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	OneLimitGradientOptimisationScreen();
	~OneLimitGradientOptimisationScreen();
};

