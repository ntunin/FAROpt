#pragma once
#include "OptimisationScreen.h"
class FullLimitMultyThreadPowerOptimisationHGScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	FullLimitMultyThreadPowerOptimisationHGScreen();
	~FullLimitMultyThreadPowerOptimisationHGScreen();
};

