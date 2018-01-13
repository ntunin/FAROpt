#pragma once
#include "OneLimitOptimisationScreen.h"
class LamdaGainOptimisationScreen :
	public OneLimitOptimisationScreen
{
protected:
	void printHead();
	OneLimitOptimisationAlgoritm *getAgoritm(OneLimitOptimisationEnvirounment *envirounment);
public:
	LamdaGainOptimisationScreen();
	~LamdaGainOptimisationScreen();
};

