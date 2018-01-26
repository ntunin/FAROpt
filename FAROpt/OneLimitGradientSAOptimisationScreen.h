#pragma once
#include "OptimisationScreen.h"
class OneLimitGradientSAOptimisationScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	OneLimitGradientSAOptimisationScreen();
	~OneLimitGradientSAOptimisationScreen();
};

