#pragma once
#include "NecIn.h"
#include "ComplexMatrix.h"
#include "ComplexVector.h"
#include "NecOut.h"
#include "Complex.h"

class OneLimitOptimisationEnvirounment
{
public:
	OneLimitOptimisationEnvirounment(NecIn *in, int theta, int phi);
	~OneLimitOptimisationEnvirounment();
	NecIn *getIn();
	int getSourceCount();
	ComplexMatrix *getB();
	double *getGEx();
	Complex ****getA();
	ComplexMatrix *getY();
	int getIDirect();
	int getJDirect();
private:
	void fillOuts();
	void fillY();
	void fillA();
	void fillB();
	void fillGEx();
	NecIn *in;
	NecOut **outs;
	int sourceCount;
	ComplexMatrix *Y;
	Complex ****A;
	ComplexMatrix *B;
	double *gEx;
	int thetaNumber;
	int phiNumber;
	int iDirect;
	int jDirect;
};

