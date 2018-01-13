#pragma once
#include "OneLimitOptimisationEnvirounment.h"
#include "GradientAlgoritm.h"
#include "OneLimitVariationalOptimisationAlgoritm.h"

class OneLimitGradientOptimisationAlgoritm :
	public OneLimitVariationalOptimisationAlgoritm,
	public GradientAlgoritm {
public:
	void solveVariationalOptimisationTask();
	OneLimitGradientOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment);
	~OneLimitGradientOptimisationAlgoritm();
};

