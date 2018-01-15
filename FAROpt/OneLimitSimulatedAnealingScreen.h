#pragma once
#include "OneLimitOptimisationScreen.h"
class OneLimitSimulatedAnealingScreen :
	public OneLimitOptimisationScreen
{
protected:
	void printHead();
	OneLimitOptimisationAlgoritm *getAgoritm(OneLimitOptimisationEnvirounment *envirounment);
public:
	OneLimitSimulatedAnealingScreen();
	~OneLimitSimulatedAnealingScreen();
};

