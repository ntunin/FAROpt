#pragma once
#include "OneSourceOptimisationEnvirounment.h"
#include "LamdaOptimisationAlgoritm.h"

class NewLamdaOptimisationAlgoritm: public LamdaOptimisationAlgoritm
{
public:
	NewLamdaOptimisationAlgoritm(OneSourceOptimisationEnvirounment *envirounment);
	~NewLamdaOptimisationAlgoritm();
};

