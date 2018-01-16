#pragma once
#include "OneLimitOptimisationAlgoritm.h"
class OneLimitGainOptimisationAlgoritm :
	public OneLimitOptimisationAlgoritm
{
protected:
	double **calculateB(OptimisationEnvirounment *envirounment);
public:
	OneLimitGainOptimisationAlgoritm();
	~OneLimitGainOptimisationAlgoritm();
};

