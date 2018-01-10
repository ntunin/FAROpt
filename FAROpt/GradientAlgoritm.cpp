#include "stdafx.h"
#include "GradientAlgoritm.h"


GradientAlgoritm::GradientAlgoritm()
{
}
void GradientAlgoritm::setSize(int size) {
	this->size = size;
}

void GradientAlgoritm::makeMaximisational() {
	this->maximisation = true;
}

void GradientAlgoritm::setInitial(double *x) {
	this->x = x;
}

void GradientAlgoritm::solve() {
	double lastF = 1e7;
	double f = -1e7;
	double *direction = new double[this->size];
	double step = 1;
	while (abs(lastF - f) > 1e-12) {
		bool haveValidDirection = false;
		lastF = f;
		for (int i = 0; i < size; i++) {
			direction[i] = 0;
			double f = this->targetFunction(x);
			double zero = x[i];
			double plus = this->x[i] + step;
			double minus = this->x[i] - step;
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
			for (int i = 0; i < this->size; i++) {
				xTmp[i] = this->x[i];
				x[i] += direction[i] * acceleration;
			}
			nextF = targetFunction(x);
			acceleration *= 2;
		} while (nextF > f);

		for (int i = 0; i < this->size; i++) {
			x[i] = xTmp[i];
		}

		f = targetFunction(x);
		delete[] xTmp;
	}
}


GradientAlgoritm::~GradientAlgoritm()
{
}
