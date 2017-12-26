#include "stdafx.h"
#include "Utils.h"


Utils::Utils()
{
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

Utils::~Utils()
{
}
