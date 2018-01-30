#pragma once
#include "OptimisationScreen.h"
class FullLimitPowerOptimisationGradientSAScreen :
	public OptimisationScreen {
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	FullLimitPowerOptimisationGradientSAScreen();
	~FullLimitPowerOptimisationGradientSAScreen();
};

