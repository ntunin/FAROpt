#pragma once
#include "NecIn.h"
#include "ComplexMatrix.h"
#include "ComplexVector.h"
#include "NecOut.h"
#include "Complex.h"
class OptimisationEnvirounment
{

public:
	OptimisationEnvirounment(NecIn *in, int theta, int ph, std::string fileName);
	~OptimisationEnvirounment();
	NecIn *getIn();
	void setName(std::string name);
	std::string getName();
	int getSourceCount();
	Complex ****getA();
	ComplexMatrix *getY();
	int getIDirect();
	int getJDirect();
	NecOut **getOuts();
protected:
	std::string name;
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

