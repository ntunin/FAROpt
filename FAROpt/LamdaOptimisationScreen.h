#pragma once
#include "ConsoleScreen.h"
#include "OneSourceOptimisationEnvirounment.h"
#include "LamdaOptimisationAlgoritm.h"

class LamdaOptimisationScreen: public ConsoleScreen {
protected:
	void printAlgoritmResult(LamdaOptimisationAlgoritm *algoritm);
	void apply();
	virtual void printHead() = 0;
	virtual LamdaOptimisationAlgoritm *getAgoritm(OneSourceOptimisationEnvirounment *envirounment) = 0;
public:
	LamdaOptimisationScreen();
	~LamdaOptimisationScreen();
};

