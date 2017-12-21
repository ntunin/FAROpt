#pragma once
#include "NecOut.h"
#include "NecIn.h"
#include "ComplexMatrix.h"

class LamdaOptimisator
{
public:
	LamdaOptimisator();
	LamdaOptimisator(char *inFileName, int iDirect, int jDirect);
	~LamdaOptimisator();


	class Optimisation {
	public:
		void set_uAu(double uAu);
		void set_uBu(double uBu);
		void setD(double D);
		void setV(int n, double *vEx);
		double get_uAu();
		double get_uBu();
		double getD();
		ComplexVector *getV();
	private:
		double uAu;
		double uBu;
		double d;
		ComplexVector *v;
	};

	class NewOptimisation : Optimisation {
	public:
		NewOptimisation(LamdaOptimisator *optimisator);
		~NewOptimisation();
	};

	class OldOptimisation : Optimisation {
	public:
		OldOptimisation(LamdaOptimisator *optimisator);
		~OldOptimisation();
	};

	Optimisation *getNewOptimisation();
	Optimisation *getOldOptimisation();

	NecIn *getNecIn();



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
	NewOptimisation *newOptimisation;
	OldOptimisation *oldOptimisation;
};

