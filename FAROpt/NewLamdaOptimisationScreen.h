#pragma once
#include "LamdaOptimisationScreen.h"
class NewLamdaOptimisationScreen :
	public LamdaOptimisationScreen
{
protected:
	void printHead(); 
	LamdaOptimisationAlgoritm *getAgoritm(OneSourceOptimisationEnvirounment *envirounment);
public:
	NewLamdaOptimisationScreen();
	~NewLamdaOptimisationScreen();
};

