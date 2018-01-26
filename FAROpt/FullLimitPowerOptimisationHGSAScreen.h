#pragma once
#include "OptimisationScreen.h"
class FullLimitPowerOptimisationHGSAScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	FullLimitPowerOptimisationHGSAScreen();
	~FullLimitPowerOptimisationHGSAScreen();
};

