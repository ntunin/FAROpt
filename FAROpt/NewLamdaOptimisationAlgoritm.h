#pragma once
#include "OneLimitOptimisationEnvirounment.h"
#include "OneLimitOptimisationAlgoritm.h"

class NewLamdaOptimisationAlgoritm: public OneLimitOptimisationAlgoritm
{
public:
	NewLamdaOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment);
	~NewLamdaOptimisationAlgoritm();
};

