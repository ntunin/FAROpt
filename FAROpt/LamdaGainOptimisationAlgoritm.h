#pragma once
#include "OneLimitOptimisationAlgoritm.h"
#include "OneLimitOptimisationEnvirounment.h"

class LamdaGainOptimisationAlgoritm: public OneLimitOptimisationAlgoritm
{
public:
	LamdaGainOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment);
	~LamdaGainOptimisationAlgoritm();
};

