#pragma once
#include "ConsoleScreen.h"
#include "OptimisationEnvirounment.h"
#include "FAROptimisationAlgoritm.h"

class OptimisationScreen: public ConsoleScreen {
protected:
	void printAlgoritmResult(FAROptimisationAlgoritm *algoritm);
	void apply();
	virtual void printHead() = 0;
	virtual FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment) = 0;
public:
	OptimisationScreen();
	~OptimisationScreen();
};

