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
		if (T > 0) {
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
		}
		
		bool haveValidDirection = false;
		lastF = f;
		f = this->targetFunction(x);
		getGradient(x, direction, size);
		double *xTmp = new double[size];
		for (int i = 0; i < size; i++) {
			xTmp[i] = x[i] + sign * step*direction[i];
		}
		double fPlus = targetFunction(xTmp);

		if ((maximisation && fPlus > f) || (!maximisation && fPlus < f)) {
			if (fPlus > f) {
				haveValidDirection = true;
			}
		}

		if (!haveValidDirection) {
			step /= 2;
			lastF = -1e7;
			delete[] xTmp;
			continue;
		}

		double acceleration = 1;
		f = targetFunction(x);
		double nextF = f;

		do {
			f = nextF;
			for (int i = 0; i < size; i++) {
				xTmp[i] = x[i];
				x[i] += sign * step * direction[i] * acceleration;
			}
			nextF = targetFunction(x);
			acceleration *= 2;
		} while (nextF > f);

		for (int i = 0; i < size; i++) {
			x[i] = xTmp[i];
		}

		f = targetFunction(x);
		delete[] xTmp;

	}

}

GradientSAAlgoritm::~GradientSAAlgoritm()
{
}
