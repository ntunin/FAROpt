#pragma once
#include "OneLimitGainOptimisationAlgoritm.h"
#include "OptimisationEnvirounment.h"
#include "LamdaOptimisationAlgoritm.h"

class LamdaGainOptimisationAlgoritm: 
	public OneLimitGainOptimisationAlgoritm,
	public LamdaOptimisationAlgoritm {

public:
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	LamdaGainOptimisationAlgoritm(OptimisationEnvirounment *envirounment);
	~LamdaGainOptimisationAlgoritm();
};

