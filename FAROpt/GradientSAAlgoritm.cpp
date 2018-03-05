#include "stdafx.h"
#include "GradientSAAlgoritm.h"


GradientSAAlgoritm::GradientSAAlgoritm()
{
}


void GradientSAAlgoritm::getRandomOffset(double *xM, double *x, int size, double radius) {
	for (int i = 0; i < size; i++) {
		xM[i] = x[i] + Shared::bundle().randomGenerator()->next() % ((int)(2 * radius * 1e3)) / 1e3 - radius;
	}
}

void GradientSAAlgoritm::coppyValues(double *x, double *xM, int size) {
	for (int i = 0; i < size; i++) {
		x[i] = xM[i];
	}
}

void GradientSAAlgoritm::solve() {
	double lastF = 1e7;
	double f = -1e7;
	bool maximisation = this->isMaximisational();
	int size = this->getSize();
	double *x = this->getCurrentSolution();
	double *direction = new double[size];
	double step = 1;
	int sign = (maximisation) ? 1 : -1;
	double T = this->TInitial;

	while (abs(lastF - f) > 1e-12 && step > 0) {
		/*if (T > 0) {
			double *xM = new double[size];
			getRandomOffset(xM, x, size, this->radius);
			double FM = targetFunction(xM);
			double F = targetFunction(x);
			double P = exp(-(FM - F) / T);
			double p = Shared::bundle().randomGenerator()->next() % 100 * 0.01;
			if (maximisation) {
				if (FM > F || p < P) {
					coppyValues(x, xM, size);
				}
			}
			else {
				if (FM < F || p < P) {
					coppyValues(x, xM, size);
				}
			}
			T -= this->coolDownSpeed;
			delete[] xM;
		}*/
		
		bool haveValidDirection = false;
		lastF = f;
		f = this->targetFunction(x);
		getGradient(x, direction, size);
		double absDir = 0;
		for (int i = 0; i < size; i++) {
			absDir += direction[i] * direction[i];
		}
		absDir = sqrt(absDir);
		for (int i = 0; i < size; i++) {
			direction[i] /= absDir;
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
		double path = 0;
		double scale = 1;
		f = targetFunction(x);
		for (int k = 0; true; k++) {
			dX *= 2;
			path += dX;
			for (int i = 0; i < size; i++) {
				xNext[i] = x[i] + direction[i] * path * scale;
			}
			double fNext = targetFunction(xNext);
			if (maximisation && fNext < f || !maximisation && fNext > f) {
				if (k < 4 + Shared::bundle().randomGenerator()->next() % 8) {
					for (int j = 0; j < size; j++) {
						xTmp[3][j] = x[j];
					}
					scale /= 2;
					k = 0;
					dX = 1;
					f = targetFunction(x);
					continue;
				}
				else {
					push(xTmp, xNext, 4, size);
					for (int i = 0; i < size; i++) {
						xNext[i] = x[i] + direction[i] * (path - 0.5*dX) * scale;
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
		double a, b, c;

		if (maximisation && fLeft > fRight || !maximisation && fLeft < fRight) {
			xa = xTmp[0]; a = path - 1.5 * dX;
			xb = xTmp[1]; b = path - dX;
			xc = xTmp[3]; c = path - 0.5 * dX;
		}
		else {
			xa = xTmp[1]; a = path - dX;
			xb = xTmp[3]; b = path - 0.5 * dX;
			xc = xTmp[2]; c = path;
		}

		double fxa = targetFunction(xa);
		double fxb = targetFunction(xb);
		double fxc = targetFunction(xc);

		double top = (b*b - c * c) * fxa + (c*c - a * a) * fxb + (a*a - b * b) * fxc;
		double bottom = (b - c) * fxa + (c - a) * fxb + (a - b) * fxc;
		int sign = (maximisation) ? 1 : -1;
		double opt = (bottom == 0) ? b : sign * 1.0 / 2 * top / bottom;

		for (int i = 0; i < size; i++) {
			x[i] += direction[i] * opt * scale;
		}

		f = targetFunction(x);

		delete[] xNext;
		for (int i = 0; i < 4; i++) {
			delete[] xTmp[i];
		}
		delete[] xTmp;

	}

}

void GradientSAAlgoritm::push(double **stack, double *newVector, int stackSize, int vectorSize) {
	for (int i = 0; i < stackSize - 1; i++) {
		for (int j = 0; j < vectorSize; j++) {
			stack[i][j] = stack[i + 1][j];
		}
	}
	for (int j = 0; j < vectorSize; j++) {
		stack[stackSize - 1][j] = newVector[j];
	}
}

GradientSAAlgoritm::~GradientSAAlgoritm()
{
}
