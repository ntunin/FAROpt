#pragma once
#include "OneLimitOptimisationScreen.h"
class OneLimitGradientOptimisationScreen :
	public OneLimitOptimisationScreen
{
protected:
	void printHead();
	OneLimitOptimisationAlgoritm *getAgoritm(OneLimitOptimisationEnvirounment *envirounment);
public:
	OneLimitGradientOptimisationScreen();
	~OneLimitGradientOptimisationScreen();
};

