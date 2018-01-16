#pragma once
#include "OneLimitDirectivityOptimisationAlgoritm.h"
#include "OptimisationEnvirounment.h"
#include "LamdaOptimisationAlgoritm.h"

class LamdaDirectivityOptimisationAlgoritm: 
	public OneLimitDirectivityOptimisationAlgoritm,
	public LamdaOptimisationAlgoritm {

public:
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	LamdaDirectivityOptimisationAlgoritm(OptimisationEnvirounment *envirounment);
	~LamdaDirectivityOptimisationAlgoritm();
};

