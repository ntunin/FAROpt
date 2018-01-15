#pragma once
#include "NecIn.h"
#include "ComplexMatrix.h"
#include "ComplexVector.h"
#include "NecOut.h"
#include "Complex.h"
#include "OptimisationEnvirounment.h"

class OneLimitOptimisationEnvirounment: public OptimisationEnvirounment
{
public:
	OneLimitOptimisationEnvirounment(NecIn *in, int theta, int phi);
	~OneLimitOptimisationEnvirounment();
	ComplexMatrix *getB();
	double *getGEx();
private:
	void fillB();
	void fillGEx();
	ComplexMatrix *B;
	double *gEx;
};

