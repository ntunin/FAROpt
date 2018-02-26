#include "stdafx.h"
#include "HGSAAlgoritm.h"
#include <math.h>

HGSAAlgoritm::HGSAAlgoritm() {
}

void HGSAAlgoritm::getRandomOffset(double *xM, double *x, int size, double radius) {
	for (int i = 0; i < size; i++) {
		xM[i] = x[i] + Shared::bundle().randomGenerator()->next() % ((int)(2 * radius * 1e3))/1e3 - radius ;
	}
}

void HGSAAlgoritm::coppyValues(double *x, double *xM, int size) {
	for (int i = 0; i < size; i++) {
		x[i] = xM[i];
	}
}

void push(double **stack, double *newVector, int stackSize, int vectorSize) {
	for (int i = 0; i < stackSize-1; i++) {
		for (int j = 0; j < vectorSize; j++) {
			stack[i][j] = stack[i + 1][j];
		}
	}
	for (int j = 0; j < vectorSize; j++) {
		stack[stackSize-1][j] = newVector[j];
	}
}

void HGSAAlgoritm::solve() {
	double lastF = 1e7;
	double f = -1e7;
	bool maximisation = this->isMaximisational();
	int size = this->getSize();
	double *x = this->getCurrentSolution();
	double *direction = new double[size];
	double step = 1;

	double T = this->TInitial;

	while (abs(lastF - f) > 1e-12) {

		/*if (T > 0) {
			double *xM = new double[size];
			getRandomOffset(xM, x, size, this->radius);
			double FM = targetFunction(xM);
			double F = targetFunction(x);
			double P = exp(-abs(FM - F) / T);
			double p = Shared::bundle().randomGenerator()->next() % 100 * 0.01;
			if ( (maximisation && (FM > F || p < P)) || (!maximisation && (FM < F || p < P)) ) {
				coppyValues(x, xM, size);
			} 
			T -= this->coolDownSpeed;
			delete[] xM;
		}*/

		bool haveValidDirection = false;
		lastF = f;
		for (int i = 0; i < size; i++) {
			direction[i] = 0;
			double f = this->targetFunction(x);
			double zero = x[i];
			double plus = x[i] + step;
			double minus = x[i] - step;
			x[i] = plus;
			double fPlus = targetFunction(x);
			x[i] = minus;
			double fMinus = targetFunction(x);
			double value;
			x[i] = zero;

			if (maximisation) {
				if (fPlus > f || fMinus > f) {
					if (fPlus > fMinus) {
						direction[i] = +step;
						haveValidDirection = true;
					}
					else {
						direction[i] = -step;
						haveValidDirection = true;
					}
				}
			}
			else {
				if (fPlus < f || fMinus < f) {
					if (fPlus < fMinus) {
						direction[i] = +step;
						haveValidDirection = true;
					}
					else {
						direction[i] = -step;
						haveValidDirection = true;
					}
				}
			}
		}

		if (!haveValidDirection) {
			step /= 2;
			lastF = -1e7;
			continue;
		}

		double **xTmp = new double*[4];
		double *xNext = new double[size];
		double *xm, *xmMinuus1, *xmPlus1, *xmMinus2;
		for (int i = 0; i < 4; i++) {
			xTmp[i] = new double[size];
			for (int j = 0; j < size; j++) {
				xTmp[i][j] = x[i];
			}
		}
		double dX = 1;
		double start = 1;
		f = targetFunction(x);
		for (int k = 0; true; k++) {
			dX *= 2;
			for (int i = 0; i < size; i++) {
				xNext[i] = xTmp[3][i] + direction[i] * dX*start;
			}
			double fNext = targetFunction(xNext);
			if (maximisation && fNext < f || !maximisation && fNext > f) {
				if (k < 4 + Shared::bundle().randomGenerator()->next() % 8) {
					for (int j = 0; j < size; j++) {
						xTmp[3][j] = x[j];
					}
					start /= 2;
					k = 0;
					dX = 1;
					f = targetFunction(x);
					continue;
				} else {
					push(xTmp, xNext, 4, size);
					for (int i = 0; i < size; i++) {
						xNext[i] = xTmp[2][i] + direction[i] * dX/2*start;
					}
					push(xTmp, xNext, 4, size);
					break;
				}
			}
			push(xTmp, xNext, 4, size);
			f = fNext;
		}

		double fLeft = targetFunction(xTmp[0]);
		double fRight = targetFunction(xTmp[2]);

		double *xa, *xb, *xc;

		if (maximisation && fLeft > fRight || !maximisation && fLeft < fRight) {
			xa = xTmp[0];
			xb = xTmp[1];
			xc = xTmp[3];
		}  else {
			xa = xTmp[1];
			xb = xTmp[3];
			xc = xTmp[2];
		}

		double fxa = targetFunction(xa);
		double fxb = targetFunction(xb);
		double fxc = targetFunction(xc);

		for (int i = 0; i < size; i++) {
			double top = (xb[i] * xb[i] - xc[i] * xc[i])*fxa + (xc[i] * xc[i] - xa[i] * xa[i])*fxb + (xa[i] * xa[i] - xb[i] * xb[i])*fxc;
			double bottom = (xb[i] - xc[i])*fxa + (xc[i] - xa[i])*fxb + (xa[i] - xb[i])*fxc;
			if (bottom == 0) {
				x[i] = xb[i];
			} else {
				x[i] = -1.0 / 2 * top / bottom;
			}
		}

		f = targetFunction(x);

		delete[] xNext;
		for (int i = 0; i < 4; i++) {
			delete[] xTmp[i];
		}
		delete[] xTmp;

	}

}


HGSAAlgoritm::~HGSAAlgoritm()
{
}
