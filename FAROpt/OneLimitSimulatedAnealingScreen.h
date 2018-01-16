#pragma once
#include "OptimisationScreen.h"
class OneLimitSimulatedAnealingScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	OneLimitSimulatedAnealingScreen();
	~OneLimitSimulatedAnealingScreen();
};

