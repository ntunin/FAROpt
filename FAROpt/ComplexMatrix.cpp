#include "stdafx.h"
#include "ComplexMatrix.h"
#include <math.h>

ComplexMatrix::ComplexMatrix(int n) {
	this->_n = this->_m = n;
	this->_matrix = new Complex*[n];
	for (int i = 0; i < n; i++) {
		this->_matrix[i] = new Complex[n];
	}
}

ComplexMatrix::ComplexMatrix(int n, int m) {
	this->_n = n;
	this->_m = m;
	this->_matrix = new Complex*[m];
	for (int i = 0; i < m; i++) {
		this->_matrix[i] = new Complex[n];
	}
}

ComplexMatrix::ComplexMatrix(int n, int m, Complex *data) {
	this->_n = n;
	this->_m = m;
	this->_matrix = new Complex*[m];
	int counter = 0;
	for (int i = 0; i < m; i++) {
		this->_matrix[i] = new Complex[n];
		for (int j = 0; j < n; j++) {
			this->_matrix[i][j] = data[counter++];
		}
	}
}

ComplexMatrix::ComplexMatrix(int n, Complex *data) {
	this->_n = n;
	this->_m = n;
	this->_matrix = new Complex*[n];
	int counter = 0;
	for (int i = 0; i < n; i++) {
		this->_matrix[i] = new Complex[n];
		for (int j = 0; j < n; j++) {
			this->_matrix[i][j] = data[counter++];
		}
	}
}

ComplexMatrix::ComplexMatrix(ComplexVector v) {
	this->_n = this->_m = v.length();
	this->_matrix = new Complex*[this->_m];
	ComplexVectorT ve = v.econj();
	for (int j = 0; j < this->_m; j++) {
		this->_matrix[j] = new Complex[this->_n];
		for (int i = 0; i < this->_n; i++) {
			this->_matrix[j][i] = ve[i] * v[j];
		}
	}

}


ComplexMatrix::~ComplexMatrix()
{
	for (int i = 0; i < this->_m; i++) {
		delete[] this->_matrix[i];
	}
	delete[] this->_matrix;
}

Complex*& ComplexMatrix::operator[](int i) {
	return this->_matrix[i];
}

ComplexVector& ComplexMatrix::operator*(ComplexVector v) {
	int length = (int)fmin(this->_m, v.length());
	int width = (int)fmin(this->_n, v.length());
	ComplexVector r = ComplexVector(length);
	for (int j = 0; j < length; j++) {
		Complex a = Complex();
		for (int i = 0; i < width; i++) {
			a += this->_matrix[j][i] * v[i];
		}
		r[j] = a;
	}
	return r;
}

int ComplexMatrix::length() {
	return _m;
}

int ComplexMatrix::width() {
	return _n;
}


ComplexMatrix& ComplexMatrix::operator-(ComplexMatrix m) {
	int length = (int)fmin(this->_m, m.length());
	int width = (int)fmin(this->_n, m.width());
	ComplexMatrix r = ComplexMatrix(length, width);
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < width; i++) {
			m[j][i] = this->_matrix[j][i] - m[j][i];
		}
	}
	return r;

}

ComplexMatrix& ComplexMatrix::operator+(ComplexMatrix m) {
	int length = (int)fmin(this->_m, m.length());
	int width = (int)fmin(this->_n, m.width());
	ComplexMatrix r = ComplexMatrix(length, width);
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < width; i++) {
			r[j][i] = this->_matrix[j][i] + m[j][i];
		}
	}
	return r;
}



ComplexMatrix& ComplexMatrix::operator*(Complex c) {
	int length = this->_m;
	int width = this->_n;
	ComplexMatrix r = ComplexMatrix(length, width);
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < width; i++) {
			r[j][i] = this->_matrix[j][i]* c;
		}
	}
	return r;
}


ComplexMatrix& ComplexMatrix::econj() {
	int length = this->_m;
	int width = this->_n;
	ComplexMatrix r = ComplexMatrix(length, width);
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < width; i++) {
			r[j][i] = this->_matrix[i][j].conj();
		}
	}
	return r;
}

double **ComplexMatrix::doubleExtend() {
	double **res = new double*[2*this->_n];
	for (int i = 0; i < this->_n; i++) {
		res[i] = new double[2 * this->_m];
		res[i + this->_n] = new double[2 * this->_m];
		for (int j = 0; j < this->_m; j++) {
			res[i][j] = this->_matrix[i][j].Re();
			res[i + this->_n][j + this->_m] = this->_matrix[i][j].Re();
			res[i + this->_n][j] = this->_matrix[i][j].Im();
			res[i][j + this->_m] = -this->_matrix[i][j].Im();
		}
	}
	return res;
}

