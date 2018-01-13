#pragma once
#include "OneLimitOptimisationScreen.h"
class LamdaDirectivityOptimisationScreen :
	public OneLimitOptimisationScreen
{
protected:
	void printHead(); 
	OneLimitOptimisationAlgoritm *getAgoritm(OneLimitOptimisationEnvirounment *envirounment);
public:
	LamdaDirectivityOptimisationScreen();
	~LamdaDirectivityOptimisationScreen();
};

