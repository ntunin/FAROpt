#include "stdafx.h"
#include "HGAlgoritm.h"


HGAlgoritm::HGAlgoritm() {
}

void HGAlgoritm::solve() {
	double lastF = 1e7;
	double f = -1e7;
	bool maximisation = this->isMaximisational();
	int size = this->getSize();
	double *x = this->getCurrentSolution();
	double *direction = new double[size];
	double **xTmp = new double*[4];
	for (int i = 0; i < 4; i++) {
		xTmp[i] = new double[size];
	}
	double *xNext = new double[size];
	double step = 1;

	while (abs(lastF - f) > 1e-3) {
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

		double *xm, *xmMinuus1, *xmPlus1, *xmMinus2;
		for (int i = 0; i < 4; i++) {
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
				if (k < 4) {
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
					Utils::push(xTmp, xNext, 4, size);
					for (int i = 0; i < size; i++) {
						xNext[i] = x[i] + direction[i] * (path - 0.5*dX) * scale;
					}
					Utils::push(xTmp, xNext, 4, size);
					break;
				}
			}
			Utils::push(xTmp, xNext, 4, size);
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


	}

	delete[] xNext;
	for (int i = 0; i < 4; i++) {
		delete[] xTmp[i];
	}
	delete[] xTmp;
	delete[] direction;
}


HGAlgoritm::~HGAlgoritm()
{
}
