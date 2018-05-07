#pragma once
#include "ComplexVector.h"
class Utils
{
public:
	static void inverse(int size, double **matrix, double **result);
	static void gradient(int size, double **matrix, double *vector, double *result);
	static void transpose(int size, double **matrix, double **result);
	static void summ(int size, double **matrix1, double **matrix2, double **result);
	static void summ(int size, double *vector1, double *vector2, double *result);
	static void mul(int size, double **matrix, double *vector, double *result);
	static void mul(int size, double *vector, double value, double *result);
	static void fill(int size, double value, double *result);
	static void push(double **stack, double *newVector, int stackSize, int vectorSize);
	static void normalize(ComplexVector *v, double *result);
	static boolean equals(double *array1, double *array2, int size, double epsilon);
	Utils();
	~Utils();
};

