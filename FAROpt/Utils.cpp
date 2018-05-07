#include "stdafx.h"
#include "Utils.h"


Utils::Utils()
{
}


void Utils::push(double **stack, double *newVector, int stackSize, int vectorSize) {
	for (int i = 0; i < stackSize - 1; i++) {
		for (int j = 0; j < vectorSize; j++) {
			stack[i][j] = stack[i + 1][j];
		}
	}
	for (int j = 0; j < vectorSize; j++) {
		stack[stackSize - 1][j] = newVector[j];
	}
}

void Utils::inverse(int size, double **matrix, double **result) {
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


void Utils::transpose(int size, double **matrix, double **result) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[j][i] = matrix[i][j];
		}
	}
}


void Utils::summ(int size, double **matrix1, double **matrix2, double **result) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}

void Utils::mul(int size, double **matrix, double *vector, double *result) {
	for (int i = 0; i < size; i++) {
		double s = 0;
		for (int j = 0; j < size; j++) {
			s += matrix[i][j] * vector[j];
		}
		result[i] = s;
	}
}

void Utils::gradient(int size, double **matrix, double *vector, double *result) {
	double **matrixT = new double*[size];
	double **mTplusM = new double*[size];
	for (int i = 0; i < size; i++) {
		matrixT[i] = new double[size];
		mTplusM[i] = new double[size];
	}
	transpose(size, matrix, matrixT);
	summ(size, matrixT, matrix, mTplusM);
	mul(size, mTplusM, vector, result);
	for (int i = 0; i < size; i++) {
		delete[] matrixT[i];
		delete[] mTplusM[i];
	}
	delete[] matrixT;
	delete[] mTplusM;
}


void Utils::fill(int size, double value, double *result) {
	for (int i = 0; i < size; i++) {
		result[i] = value;
	}
}

void Utils::mul(int size, double *vector, double value, double *result) {
	for (int i = 0; i < size; i++) {
		result[i] = vector[i] * value;
	}
}

void Utils::summ(int size, double *vector1, double *vector2, double *result) {
	for (int i = 0; i < size; i++) {
		result[i] = vector1[i] + vector2[i];
	}
}

void Utils::normalize(ComplexVector *cv, double *result) {
	ComplexVector v = *cv;
	int size = v.length();
	double rPhi = v[0].arg();
	for (int i = 0; i < size; i++) {
		result[2 * i] = v[i].abs();
		result[2 * i + 1] = v[i].arg() - rPhi;
	}

}

boolean Utils::equals(double *array1, double *array2, int size, double epsilon) {
	for (int k = 0; k < size; k++) {
		if (abs(array1[k] - array2[k]) > epsilon) {
			return false;
		}
	}
	return true;
}

Utils::~Utils()
{
}
