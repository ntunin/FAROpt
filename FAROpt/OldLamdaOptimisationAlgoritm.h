#pragma once
#include "LamdaOptimisationAlgoritm.h"
#include "OneSourceOptimisationEnvirounment.h"

class OldLamdaOptimisationAlgoritm: public LamdaOptimisationAlgoritm
{
public:
	OldLamdaOptimisationAlgoritm(OneSourceOptimisationEnvirounment *envirounment);
	~OldLamdaOptimisationAlgoritm();
};

