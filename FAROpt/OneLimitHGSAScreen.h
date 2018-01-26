#pragma once
#include "OptimisationScreen.h"
class OneLimitHGSAScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	OneLimitHGSAScreen();
	~OneLimitHGSAScreen();
};

