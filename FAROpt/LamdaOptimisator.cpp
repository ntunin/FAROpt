#include "stdafx.h"
#include "LamdaOptimisator.h"
#include <iostream>
#include <time.h>


#define PI 3.14159265359

using namespace std;
LamdaOptimisator::LamdaOptimisator() {

}

LamdaOptimisator::LamdaOptimisator(char *inFileName, int iDirect, int jDirect) {
	this->in = new NecIn();
	this->iDirect = iDirect;
	this->jDirect = jDirect;
	NecInParser(string(inFileName), in);
	this->sourceCount = (int)in->getEX()->size();
	this->fillOuts();
	this->fillY();
	this->fillA();
	this->fillB();
	this->fillGEx();
	this->newOptimisation = new NewOptimisation(this);
	this->oldOptimisation = new OldOptimisation(this);
}


void LamdaOptimisator::fillOuts() {
	this->outs = new NecOut*[this->sourceCount];
	OneSourceThread **threads = new OneSourceThread*[this->sourceCount];
	for (int i = 0; i < this->sourceCount; i++) {
		outs[i] = new NecOut;
		threads[i] = new OneSourceThread(in, outs[i], i);
	}
	for (int i = 0; i < this->sourceCount; i++) {
		threads[i]->wait();
	}

}


void LamdaOptimisator::fillY() {
	this->Y = new ComplexMatrix(this->sourceCount);
	for (int sourceNumber = 0; sourceNumber < this->sourceCount; sourceNumber++) {
		vector<NecOut::Source> sources = this->outs[sourceNumber]->getSources();
		for (int i = 0; i < sources.size(); i++) {
			if (abs(sources[i].getV().Re()) > 1e-9) {
				for (int j = 0; j < this->sourceCount; j++) {
					Complex I = sources[j].getI();
					Complex V = sources[i].getV();
					Complex c = sources[j].getI() / sources[i].getV();
					(*this->Y)[i][j] = c;
				}
				break;
			}
		}
		
	}
	Shared::bundle().log()->print("Y matrix:\n");
	Shared::bundle().log()->print(*Y);
}


void LamdaOptimisator::fillA() {
	RP *rp = this->in->getRP();
	this->thetaNumber = rp->getThetaNumber();
	this->phiNumber = rp->getPhiNumber();
	this->A = new Complex***[this->sourceCount];
	for (int i = 0; i < this->sourceCount; i++) {
		this->A[i] = new Complex**[this->sourceCount];
		vector<NecOut::RadiationPattern> rpI = this->outs[i]->getRadiationPatterns();
		for (int j = 0; j < this->sourceCount; j++) {
			this->A[i][j] = new Complex*[this->thetaNumber];
			vector<NecOut::RadiationPattern> rpJ = this->outs[j]->getRadiationPatterns();
			for (int k = 0; k < thetaNumber; k++) {
				this->A[i][j][k] = new Complex[this->phiNumber];
				for (int l = 0; l < phiNumber; l++) {
					int index = l * thetaNumber + k;
					Complex e3 = rpI[index].getE();
					Complex e2 = rpJ[index].getE();
					double re = e3.Re()* e2.Re() + e3.Im() * e2.Im();
					double im = -(e3.Im()*e2.Re()) + (e3.Re() * e2.Im());

					if ((i == 0) && (k == 1) && (l == 1)) {
						double r1 = (e3.Im()*e2.Re());
						double r2 = (e3.Re() * e2.Im());
						int a = 0;
					}
					this->A[i][j][k][l] = Complex(re, im);;
				}
			}
		}
	}
}

void LamdaOptimisator::fillB() {
	this->B = new ComplexMatrix(this->sourceCount);
	for (int i = 0; i < this->sourceCount; i++) {
		for (int j = 0; j < this->sourceCount; j++) {
			Complex summ;
			for (int k = 0; k < this->thetaNumber; k++) {
				double m = (k == this->thetaNumber - 1) ? 0.5 : 1;
				for (int l = 0; l < this->phiNumber; l++) {
					Complex a = this->A[i][j][k][l] * sin(PI * k / 36); //Why 36??? 
					a = a * m;
					summ += a;
				}
			}
			(*this->B)[i][j] = summ;
		}
	}

	Shared::bundle().log()->print("\n\nB matrix:\n");
	Shared::bundle().log()->print(*this->B);
}

void LamdaOptimisator::fillGEx() {
	ComplexVector g = ComplexVector(this->sourceCount);
	int patternNumber = this->thetaNumber * this->jDirect + this->iDirect;
	for (int i = 0; i < this->sourceCount; i++) {
		vector<NecOut::RadiationPattern> rp = this->outs[i]->getRadiationPatterns();
		Complex e = rp[patternNumber].getE().conj();
		g[i] = e;
	}

	this->gEx = g.extendDouble();
}

void inverse(int size, double **matrix, double **result);


void LamdaOptimisator::Optimisation::set_uAu(double uAu) {
	this->uAu = uAu;
}

void LamdaOptimisator::Optimisation::set_uBu(double uBu) {
	this->uBu = uBu;
}

void LamdaOptimisator::Optimisation::setD(double d) {
	this->d = d;
}

void LamdaOptimisator::Optimisation::setV(int n, double *vEx) {
	int size = n / 2;
	ComplexVector *v = new ComplexVector(size);
	for (int i = 0; i < size; i++) {
		(*v)[i] = Complex(vEx[i], vEx[i + size]);
	}
	this->v = v;
}


double LamdaOptimisator::Optimisation::get_uAu() {
	return this->uAu;
}

double LamdaOptimisator::Optimisation::get_uBu() {
	return this->uBu;
}

double LamdaOptimisator::Optimisation::getD() {
	return this->d;
}

ComplexVector* LamdaOptimisator::Optimisation::getV() {
	return this->v;
}

LamdaOptimisator::Optimisation *LamdaOptimisator::getNewOptimisation() {
	return (Optimisation *)this->newOptimisation;
}


LamdaOptimisator::Optimisation *LamdaOptimisator::getOldOptimisation() {
	return (Optimisation *)this->oldOptimisation;
}

NecIn *LamdaOptimisator::getNecIn() {
	return this->in;
}


LamdaOptimisator::NewOptimisation::NewOptimisation(LamdaOptimisator *optimisator) {
	RP *rp = optimisator->in->getRP();
	double dTheta = rp->getThetaInc() * PI / 180;
	int dSize = 2 * optimisator->sourceCount;
	double *Au = new double[dSize];
	double **B = optimisator->B->doubleExtend();	
	double **BInverse = optimisator->B->doubleExtend(); //Just need same size, values no metter
	inverse(dSize, B, BInverse); 

	double *vEx = new double[dSize];
	for (int i = 0; i < dSize; i++) {
		vEx[i] = 0;
		for (int j = 0; j < dSize; j++) {
			vEx[i] += BInverse[i][j] * optimisator->gEx[j];
		}
	}


	for (int i = 0; i < dSize; i++) {
		Au[i] = 0;
		for (int j = 0; j < dSize; j++) {
			double b = B[i][j];
			double v = vEx[j];
			double a = b * v;
			Au[i] += B[i][j] * vEx[j];
		}
	}

	double uBu = 0;
	for (int i = 0; i < dSize; i++) {
		uBu += vEx[i] * Au[i];
	}

	


	ComplexMatrix A = ComplexMatrix(optimisator->sourceCount);
	for (int i = 0; i < optimisator->sourceCount; i++) {
		for (int j = 0; j < optimisator->sourceCount; j++) {
			A[i][j] = optimisator->A[i][j][optimisator->iDirect][optimisator->jDirect];
		}
	}

	double **AEx = A.doubleExtend();
	for (int i = 0; i < dSize; i++) {
		Au[i] = 0;
		for (int j = 0; j < dSize; j++) {
			Au[i] += AEx[i][j] * vEx[j];
		}
	}

	double uAu = 0;
	for (int i = 0; i < dSize; i++) {
		uAu += vEx[i] * Au[i];
	}

	double d = 4 * PI*uAu / (uBu * dTheta * dTheta);

	this->setD(d);
	this->set_uAu(uAu);
	this->set_uBu(uBu);
	this->setV(dSize, vEx);

	for (int i = 0; i < dSize; i++) {
		delete[] B[i];
		delete[] BInverse[i];
		delete[] AEx[i];
	}
	delete[] Au;
	delete[] B;
	delete[] BInverse;
	delete[] AEx;
}

LamdaOptimisator::NewOptimisation::~NewOptimisation() {

}

LamdaOptimisator::OldOptimisation::OldOptimisation(LamdaOptimisator *optimisator) {
	RP *rp = optimisator->in->getRP();
	double dTheta = rp->getThetaInc() * PI / 180;
	int size = optimisator->sourceCount;
	int dSize = 2 * size;
	double *Au = new double[dSize];
	double **BInverse = optimisator->B->doubleExtend();
	double **B = optimisator->B->doubleExtend();
	double **BSave = optimisator->B->doubleExtend();
	ComplexMatrix Y = *optimisator->Y;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			double y = Y[i][j].Re();
			B[i][j] = y;
			B[i + size][j + size] = y;
			B[i][j + size] = 0;
			B[i + size][j] = 0;
		}
	}



	inverse(dSize, B, BInverse);

	double *vEx = new double[dSize];
	for (int i = 0; i < dSize; i++) {
		vEx[i] = 0;
		for (int j = 0; j < dSize; j++) {
			double b = BInverse[i][j];
			double g = optimisator->gEx[j];
			double dv = b * g;
			vEx[i] += BInverse[i][j] * optimisator->gEx[j];
		}
	}

	Shared::bundle().log()->print("\nVoltage:\n");
	Shared::bundle().log()->print(vEx, dSize);
	Shared::bundle().log()->print("\n");

	for (int i = 0; i < dSize; i++) {
		Au[i] = 0;
		for (int j = 0; j < dSize; j++) {
			Au[i] += BSave[i][j] * vEx[j];
		}
	}

	double uBu = 0;
	for (int i = 0; i < dSize; i++) {
		uBu += vEx[i]*Au[i];
	}

	ComplexMatrix A = ComplexMatrix(optimisator->sourceCount);
	for (int i = 0; i < optimisator->sourceCount; i++) {
		for (int j = 0; j < optimisator->sourceCount; j++) {
			A[i][j] = optimisator->A[i][j][optimisator->iDirect][optimisator->jDirect];
		}
	}

	double **AEx = A.doubleExtend();

	for (int i = 0; i < dSize; i++) {
		Au[i] = 0;
		for (int j = 0; j < dSize; j++) {
			Au[i] += AEx[i][j] * vEx[j];
		}
	}

	double uAu = 0;
	for (int i = 0; i < dSize; i++) {
		uAu += vEx[i] * Au[i];
	}

	double d = 4 * PI*uAu / (uBu * dTheta * dTheta);

	this->setD(d);
	this->set_uAu(uAu);
	this->set_uBu(uBu);
	this->setV(dSize, vEx);


	for (int i = 0; i < dSize; i++) {
		delete[] B[i];
		delete[] BInverse[i];
		delete[] BSave[i];
		delete[] AEx[i];
	}
	delete[] Au;
	delete[] B;
	delete[] BSave;
	delete[] BInverse;
	delete[] AEx;
}


LamdaOptimisator::OldOptimisation::~OldOptimisation() {

}


LamdaOptimisator::~LamdaOptimisator() {
	//delete this->Y;
	if (this->in) {
		RP *rp = this->in->getRP();
		this->thetaNumber = rp->getThetaNumber();
		this->phiNumber = rp->getPhiNumber();
		for (int i = 0; i < this->sourceCount; i++) {
			for (int j = 0; j < this->sourceCount; j++) {
				for (int k = 0; k < thetaNumber; k++) {
					delete this->A[i][j][k];
				}
				delete this->A[i][j];
			}
			delete this->A[i];
		}

		delete this->in;
		this->in = NULL;
	}

	if (this->A) {
		delete this->A;
		this->A = NULL;

	}
	if (this->B) {
		delete this->B;
		this->B = NULL;
	}

	if (this->gEx) {
		delete[] this->gEx;
		this->gEx = NULL;
	}

	if (this->outs) {
		delete[] this->outs;
		this->outs = NULL;
	}
	
	delete this->newOptimisation;
	delete this->oldOptimisation;
}


void inverse(int size, double **matrix, double **result) {
	double **augmentedmatrix = new double*[size];
	for (int i = 0; i < size; i++) {
		augmentedmatrix[i] = new double[2 * size];
		for (int j = 0; j < size; j++) {
			if (i == j) {
				augmentedmatrix[i][j + size] = 1;
			}
			else {
				augmentedmatrix[i][j + size] = 0;
			}
			augmentedmatrix[i][j] = matrix[i][j];
		}
	}

	for (int j = 0; j < size; j++) {
		int tmp = j;
		for (int i = j + 1; i < size; i++) {
			if (abs(augmentedmatrix[i][j]) > abs(augmentedmatrix[tmp][j])) {
				tmp = i;
			}
		}
		if (tmp != j) {
			for (int k = 0; k < 2 * size; k++) {
				double buf = augmentedmatrix[j][k];
				augmentedmatrix[j][k] = augmentedmatrix[tmp][k];
				augmentedmatrix[tmp][k] = buf;
			}
		}


		for (int i = 0; i < size; i++) {
			if (i != j)
			{
				double r = augmentedmatrix[i][j];
				for (int k = 0; k < 2 * size; k++) {
					augmentedmatrix[i][k] -= (augmentedmatrix[j][k] / augmentedmatrix[j][j])*r;
				}
			}
			else {
				double r = augmentedmatrix[i][j];
				for (int k = 0; k < 2 * size; k++) {
					augmentedmatrix[i][k] /= r;
				}
			}
		}



	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[i][j] = augmentedmatrix[i][j + size];
		}
	}

	for (int i = 0; i < size; i++) {
		delete[] augmentedmatrix[i];
	}

	delete[] augmentedmatrix;

}