#pragma once
#include "OneLimitOptimisationScreen.h"
class NewLamdaOptimisationScreen :
	public OneLimitOptimisationScreen
{
protected:
	void printHead(); 
	OneLimitOptimisationAlgoritm *getAgoritm(OneLimitOptimisationEnvirounment *envirounment);
public:
	NewLamdaOptimisationScreen();
	~NewLamdaOptimisationScreen();
};

