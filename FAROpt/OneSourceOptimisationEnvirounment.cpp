#include "stdafx.h"
#include "OneSourceOptimisationEnvirounment.h"
#define PI 3.14159265359

using namespace std;

OneSourceOptimisationEnvirounment::OneSourceOptimisationEnvirounment(NecIn *in, int theta, int phi) {
	this->in = in;
	RP *rp = in->getRP();
	int thetaInc = rp->getThetaInc();
	int phiInc = rp->getPhiInc();
	this->iDirect = theta / thetaInc;
	this->jDirect = phi / phiInc;
	this->sourceCount = (int)in->getEX()->size();
	this->fillOuts();
	this->fillY();
	this->fillA();
	this->fillB();
	this->fillGEx();
}



void OneSourceOptimisationEnvirounment::fillOuts() {
	this->outs = new NecOut*[this->sourceCount];
	OneSourceThread **threads = new OneSourceThread*[this->sourceCount];
	Shared::bundle().log()->print("Please wait while nec2 making calculations for one source enabled mod. \n");
	for (int i = 0; i < this->sourceCount; i++) {
		outs[i] = new NecOut;
		threads[i] = new OneSourceThread(in, outs[i], i);
	}
	for (int i = 0; i < this->sourceCount; i++) {
		threads[i]->wait();
	}
	Shared::bundle().log()->print("\n");

}


void OneSourceOptimisationEnvirounment::fillY() {
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


void OneSourceOptimisationEnvirounment::fillA() {
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

void OneSourceOptimisationEnvirounment::fillB() {
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

void OneSourceOptimisationEnvirounment::fillGEx() {
	ComplexVector g = ComplexVector(this->sourceCount);
	int patternNumber = this->thetaNumber * this->jDirect + this->iDirect;
	for (int i = 0; i < this->sourceCount; i++) {
		vector<NecOut::RadiationPattern> rp = this->outs[i]->getRadiationPatterns();
		Complex e = rp[patternNumber].getE().conj();
		g[i] = e;
	}

	this->gEx = g.extendDouble();
}

OneSourceOptimisationEnvirounment::~OneSourceOptimisationEnvirounment()
{
}

NecIn *OneSourceOptimisationEnvirounment::getIn() {
	return in;
}

int OneSourceOptimisationEnvirounment::getSourceCount() {
	return this->sourceCount;
}


ComplexMatrix *OneSourceOptimisationEnvirounment::getB() {
	return this->B;
}


double *OneSourceOptimisationEnvirounment::getGEx() {
	return this->gEx;
}

Complex ****OneSourceOptimisationEnvirounment::getA() {
	return this->A;
}

int OneSourceOptimisationEnvirounment::getIDirect() {
	return this->iDirect;
}

int OneSourceOptimisationEnvirounment::getJDirect() {
	return this->jDirect;
}

ComplexMatrix *OneSourceOptimisationEnvirounment::getY() {
	return this->Y;
}