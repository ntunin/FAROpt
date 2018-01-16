#pragma once
#include "OptimisationScreen.h"
class LamdaDirectivityOptimisationScreen :
	public OptimisationScreen
{
protected:
	void printHead(); 
	FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment);
public:
	LamdaDirectivityOptimisationScreen();
	~LamdaDirectivityOptimisationScreen();
};

