#pragma once
#include "OneLimitOptimisationAlgoritm.h"
#include "OneLimitOptimisationEnvirounment.h"

class OldLamdaOptimisationAlgoritm: public OneLimitOptimisationAlgoritm
{
public:
	OldLamdaOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment);
	~OldLamdaOptimisationAlgoritm();
};

