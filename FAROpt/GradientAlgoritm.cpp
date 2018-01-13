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
	while (abs(lastF - f) > 1e-12) {
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
			} else {
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

		double *xTmp = new double[size];
		double acceleration = 1;
		f = targetFunction(x);
		double nextF = f;

		do {
			f = nextF;
			for (int i = 0; i < size; i++) {
				xTmp[i] = x[i];
				x[i] += direction[i] * acceleration;
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
