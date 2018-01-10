#pragma once
#include "OneLimitOptimisationScreen.h"
class OldLamdaOptimisationScreen :
	public OneLimitOptimisationScreen
{
protected:
	void printHead();
	OneLimitOptimisationAlgoritm *getAgoritm(OneLimitOptimisationEnvirounment *envirounment);
public:
	OldLamdaOptimisationScreen();
	~OldLamdaOptimisationScreen();
};

