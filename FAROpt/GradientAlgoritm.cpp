#include "stdafx.h"
#include "GradientAlgoritm.h"


GradientAlgoritm::GradientAlgoritm() {
}

void GradientAlgoritm::solve() {
	double lastF = 1e7;
	double f = -1e7;
	bool maximisation = this->isMaximisational();
	int size = this->getSize();
	double *x = this->getCurrentSolution();
	double *direction = new double[size];
	double step = 1;
	int sign = (maximisation) ? -1 : 1;

	while (abs(lastF - f) > 1e-12 && step > 0) {
		bool haveValidDirection = false;
		lastF = f;
		f = this->targetFunction(x);
		getGradient(x, direction, size);
		double *xTmp = new double[size];
		for (int i = 0; i < size; i++) {
			xTmp[i] = x[i] + sign*step*direction[i];
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


GradientAlgoritm::~GradientAlgoritm()
{
}
