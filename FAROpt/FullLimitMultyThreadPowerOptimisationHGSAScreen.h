#pragma once
#include "OptimisationScreen.h"
class FullLimitMultyThreadPowerOptimisationHGSAScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	FullLimitMultyThreadPowerOptimisationHGSAScreen();
	~FullLimitMultyThreadPowerOptimisationHGSAScreen();
};

