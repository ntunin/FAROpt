#pragma once
#include "LamdaOptimisationScreen.h"
class OldLamdaOptimisationScreen :
	public LamdaOptimisationScreen
{
protected:
	void printHead();
	LamdaOptimisationAlgoritm *getAgoritm(OneSourceOptimisationEnvirounment *envirounment);
public:
	OldLamdaOptimisationScreen();
	~OldLamdaOptimisationScreen();
};

