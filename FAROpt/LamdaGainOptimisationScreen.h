#pragma once
#include "OptimisationScreen.h"
class LamdaGainOptimisationScreen :
	public OptimisationScreen
{
protected:
	void printHead();
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	LamdaGainOptimisationScreen();
	~LamdaGainOptimisationScreen();
};

