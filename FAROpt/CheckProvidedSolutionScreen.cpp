#include "stdafx.h"
#include "CheckProvidedSolutionScreen.h"
#include "CheckoutParser.h"


using namespace std;

CheckProvidedSolutionScreen::CheckProvidedSolutionScreen() {
	this->reset();
	this->printHead();
	string fileName = Shared::bundle().scanner()->readString("Please enter *.chk file name: > ");
	this->data = new CheckoutData;
	CheckoutParser(fileName, data);
	int size = data->getSize();
	double **A = data->getA();
	vector<double **> *B = data->getB();
	double * X = data->getX();
	print("\n A:\n");
	print(size, A);
	print("\n B:\n");
	for (int i = 0; i < B->size(); i++) {
		print(size, (*B)[i]);
		print("\n");
	}
	print("\n X: ");
	print(size, X);
	print("\n\n");
	double uAu = calculate_uAu(X);
	vector<double> *uBu = calculate_uBu(X);
	print("uAu: ");
	print(uAu);
	print(" uBu: ");
	for (int i = 0; i < uBu->size(); i++) {
		print((*uBu)[i]);
		print(" ");
	}
	print("\n\n");
	delete uBu;
	system("pause");
}


double CheckProvidedSolutionScreen::calculate_uAu(double *vEx) {
	int size = data->getSize();
	double **AEx = data->getA();
	double *Au = new double[size];
	for (int i = 0; i < size; i++) {
		Au[i] = 0;
		for (int j = 0; j < size; j++) {
			Au[i] += AEx[i][j] * vEx[j];
		}
	}
	double uAu = 0;
	for (int i = 0; i < size; i++) {
		uAu += vEx[i] * Au[i];
	}
	delete[] Au;
	return uAu;
}

vector<double> * CheckProvidedSolutionScreen::calculate_uBu(double *vEx) {
	int size = data->getSize();
	vector<double **> *B = data->getB();
	vector<double> *uBus = new vector<double>;
	double *Bu = new double[size];
	for (int k = 0; k < B->size(); k++) {
		for (int i = 0; i < size; i++) {
			Bu[i] = 0;
			for (int j = 0; j < size; j++) {
				double b = (*B)[k][i][j];
				Bu[i] += (*B)[k][i][j] * vEx[j];
			}
		}
		double uBu = 0;
		for (int i = 0; i < size; i++) {
			uBu += vEx[i] * Bu[i];
		}
		uBus->push_back(uBu);
	}
	delete[] Bu;
	return uBus;
}


void CheckProvidedSolutionScreen::printHead() {
	print("---- Check provided solution ----\n");
	print("----    Omsk, 2018   ----\n");
	print("\n");
}

CheckProvidedSolutionScreen::~CheckProvidedSolutionScreen() {

}