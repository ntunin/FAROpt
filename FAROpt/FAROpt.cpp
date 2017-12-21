// FAROpt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

void printComplexVector(ComplexVector *v) {
	int n = v->length();
	for (int i = 0; i < n; i++) {
		Complex c = (*v)[i];
		cout << "(";
		cout.width(10);
		cout << c.Re() << ":";
		cout.width(10);
		cout << c.Im() << ");";
	}
}

void printOptimisation(LamdaOptimisator::Optimisation *optimisation) {
	cout << "d: " << optimisation->getD()
		<< " uAu: " << optimisation->get_uAu()
		<< " uBu: " << optimisation->get_uBu() << endl;
	cout << "voltage: " << endl;
	printComplexVector(optimisation->getV());
	cout << endl;
}

int main(int argc, char **argv) {
	try {
		Shared::bundle().log(new ConsoleLog());
		char *fileName = argv[1];
		LamdaOptimisator *optimisator = new LamdaOptimisator(fileName, 14, 9);
		LamdaOptimisator::Optimisation *newOptimisation = optimisator->getNewOptimisation();
		LamdaOptimisator::Optimisation *oldOptimisation = optimisator->getOldOptimisation();
		cout << endl;
		cout << "\n---- New Optimisation Algoritm ----\n" << endl;
		printOptimisation(newOptimisation);
		cout << endl;
		cout << "\n---- Old Optimisation Algoritm ----\n" << endl;
		printOptimisation(oldOptimisation);
		cout << endl;
		NecOut *out = new NecOut();
		AllSourceThread *thread = new AllSourceThread(optimisator, newOptimisation, "optim", out);
		thread->wait();
		RP *rp = optimisator->getNecIn()->getRP();
		NecOutPlotDrawer *drawer = new NecOutPlotDrawer(out, 14 * rp->getThetaInc(), 9 * rp->getPhiInc());
		drawer->wait();
		system("pause");
		delete out;
		delete thread;
		delete drawer;
		delete optimisator;
	} catch (exception e) {
		cout << e.what() << endl;
	};
    return 0;
}

