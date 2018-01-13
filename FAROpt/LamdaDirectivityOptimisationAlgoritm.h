#pragma once
#include "OneLimitOptimisationEnvirounment.h"
#include "OneLimitOptimisationAlgoritm.h"
#include "OneLimitDirectivityOptimisationAlgoritm.h"

class LamdaDirectivityOptimisationAlgoritm: public OneLimitDirectivityOptimisationAlgoritm
{
public:
	void solveOptimisationTask(OneLimitOptimisationEnvirounment *envirounment);
	LamdaDirectivityOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment);
	~LamdaDirectivityOptimisationAlgoritm();
};

