#pragma once
#include "OptimisationScreen.h"
class FullLimitPowerOptimisationHGScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	FullLimitPowerOptimisationHGScreen();
	~FullLimitPowerOptimisationHGScreen();
};

