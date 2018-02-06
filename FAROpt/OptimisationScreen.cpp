#include "stdafx.h"
#include "OptimisationScreen.h"

using namespace std;

OptimisationScreen::OptimisationScreen() {
	
}

void OptimisationScreen::apply() {
	this->reset();
	this->printHead();
	string fileName = readString("Please provide path to *.nec file: > ");
	NecIn *in = new NecIn();
	NecInParser(fileName, in);
	RP *rp = in->getRP();
	int thetaInc = rp->getThetaInc();
	int phiInc = rp->getPhiInc();
	print("\nFill out the direction of radiation\n");
	int theta = readInt("Theta: > ");
	int phi = readInt("Phi: > ");
	print("\n");
	OptimisationEnvirounment *envirounment = new OptimisationEnvirounment(in, theta, phi, fileName);
	FAROptimisationAlgoritm *algoritm = getAgoritm(envirounment);
	print("\n");
	printAlgoritmResult(algoritm);
	print("\n");
	NecOut *out = new NecOut();
	string resultOutName = readString("Please provide the name of result nec file: > ");
	AllSourceThread *thread = new AllSourceThread(envirounment->getIn(), algoritm->getV(), resultOutName.c_str(), out);
	thread->wait();
	NecOutPlotDrawer *drawer = new NecOutPlotDrawer(out, theta, phi);
	drawer->wait();
	system("pause");
	delete in;
	delete out;
	delete thread;
	delete drawer;
	delete envirounment;
}

void OptimisationScreen::printAlgoritmResult(FAROptimisationAlgoritm *algoritm) {
	print("d: "); print(algoritm->getD());
	print(" uAu: "); print(algoritm->get_uAu());
	vector<double> *uBu = algoritm->get_uBu();
	int size = uBu->size();
	print(" uBu: "); 
	for (int i = 0; i < size; i++) {
		print((*uBu)[i]);
		print(" ");
	}
	print("\nvoltage: "); print(algoritm->getV());
	print("\n");
}



OptimisationScreen::~OptimisationScreen()
{
}
