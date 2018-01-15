#pragma once
#include "NecIn.h"
#include "ComplexMatrix.h"
#include "ComplexVector.h"
#include "NecOut.h"
#include "Complex.h"
class OptimisationEnvirounment
{

public:
	~OptimisationEnvirounment();
	NecIn *getIn();
	int getSourceCount();
	Complex ****getA();
	ComplexMatrix *getY();
	int getIDirect();
	int getJDirect();
protected:
	void optimisationEnvirounmentSetup(NecIn *in, int theta, int ph);
	void fillOuts();
	void fillY();
	void fillA();
	NecIn *in;
	NecOut **outs;
	int sourceCount;
	ComplexMatrix *Y;
	Complex ****A;
	int thetaNumber;
	int phiNumber;
	int iDirect;
	int jDirect;
};

