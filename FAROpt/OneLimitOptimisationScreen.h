#pragma once
#include "ConsoleScreen.h"
#include "OneLimitOptimisationEnvirounment.h"
#include "OneLimitOptimisationAlgoritm.h"

class OneLimitOptimisationScreen: public ConsoleScreen {
protected:
	void printAlgoritmResult(OneLimitOptimisationAlgoritm *algoritm);
	void apply();
	virtual void printHead() = 0;
	virtual OneLimitOptimisationAlgoritm *getAgoritm(OneLimitOptimisationEnvirounment *envirounment) = 0;
public:
	OneLimitOptimisationScreen();
	~OneLimitOptimisationScreen();
};

