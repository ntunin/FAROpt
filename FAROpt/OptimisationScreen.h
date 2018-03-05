#pragma once
#include "ConsoleScreen.h"
#include "OptimisationEnvirounment.h"
#include "FAROptimisationAlgoritm.h"
#include "ComplexMatrix.h"

class OptimisationScreen: public ConsoleScreen {
protected:
	void printAlgoritmResult(FAROptimisationAlgoritm *algoritm, OptimisationEnvirounment *envirounment);
	void apply();
	virtual void printHead() = 0;
	virtual FAROptimisationAlgoritm *getAgoritm(OptimisationEnvirounment *envirounment) = 0;
	ComplexMatrix *Y;
	int workingTime;
public:
	OptimisationScreen();
	~OptimisationScreen();
};

