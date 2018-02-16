#pragma once
#include "OptimisationScreen.h"
class FullLimitMultyThreadPowerOptimisationGradientSAScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	FullLimitMultyThreadPowerOptimisationGradientSAScreen();
	~FullLimitMultyThreadPowerOptimisationGradientSAScreen();
};

