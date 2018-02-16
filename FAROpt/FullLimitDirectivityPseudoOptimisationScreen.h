#pragma once
#include "OptimisationScreen.h"
#include "FAROptimisationAlgoritm.h"
#include "OptimisationEnvirounment.h"

class FullLimitDirectivityPseudoOptimisationScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	FullLimitDirectivityPseudoOptimisationScreen();
	~FullLimitDirectivityPseudoOptimisationScreen();
};

