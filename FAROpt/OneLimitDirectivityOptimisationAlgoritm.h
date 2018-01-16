#pragma once
#include "OneLimitOptimisationAlgoritm.h"

class OneLimitDirectivityOptimisationAlgoritm :
	public OneLimitOptimisationAlgoritm
{
protected:
	double **calculateB(OptimisationEnvirounment *envirounment);
public:
	OneLimitDirectivityOptimisationAlgoritm();
	~OneLimitDirectivityOptimisationAlgoritm();

};

