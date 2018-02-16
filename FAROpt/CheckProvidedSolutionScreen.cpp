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
	string inName = Shared::bundle().scanner()->readString("Please provide the name of original *.nec file: > ");
	string solutionName = Shared::bundle().scanner()->readString("Please provide the name *.nec file for check: > ");
	NecIn *in = new NecIn;
	print("\nFill out the direction of radiation\n");
	int theta = readInt("Theta: > ");
	int phi = readInt("Phi: > ");
	print("\n");
	NecInParser(inName, in);
	OptimisationEnvirounment *envirounment = new OptimisationEnvirounment(in, theta, phi, inName);	
	ComplexMatrix *Y = envirounment->getY();
	size = Y->length();
	Complex ****ACover = envirounment->getA();
	ComplexMatrix Ain = ComplexMatrix(size);
	int iDirect = envirounment->getIDirect();
	int jDirect = envirounment->getJDirect();
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Ain[i][j] = ACover[i][j][iDirect][jDirect];
		}
	}
	double **AEx = Ain.doubleExtend();
	double **Z = new double*[2*size];
	for (int i = 0; i < 2*size; i++) {
		Z[i] = new double[2*size];
	}
	print("\n A:\n");
	print(2*size, AEx);
	Utils::inverse(2*size, Y->doubleExtend(), Z);
	double *U = new double[2 * size];
	Utils::mul(2*size, Z, X, U);
	ComplexVector u(size);
	for (int i = 0; i < size; i++) {
		u[i] = Complex(U[i], U[i + size]);
	}
	NecOut *out = new NecOut;
	AllSourceThread *thread = new AllSourceThread(in, &u, solutionName.c_str(), out);
	thread->wait();
	NecOutPlotDrawer *drawer = new NecOutPlotDrawer(out, theta, phi);
	drawer->wait();
	system("pause");
	delete uBu;
	delete in;
	delete envirounment;
	for (int i = 0; i < 2 * size; i++) {
		delete[] AEx[i];
		delete[] Z[i];
	}
	delete[] AEx;
	delete[] U;
	delete[] Z;
	delete out;
	delete drawer;
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