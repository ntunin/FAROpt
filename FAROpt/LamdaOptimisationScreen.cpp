#include "stdafx.h"
#include "LamdaOptimisationScreen.h"

using namespace std;

LamdaOptimisationScreen::LamdaOptimisationScreen() {
	
}

void LamdaOptimisationScreen::apply() {
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
	OneSourceOptimisationEnvirounment *envirounment = new OneSourceOptimisationEnvirounment(in, theta, phi);
	LamdaOptimisationAlgoritm * algoritm = getAgoritm(envirounment);
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
	delete algoritm;
}

void LamdaOptimisationScreen::printAlgoritmResult(LamdaOptimisationAlgoritm *algoritm) {
	print("d: "); print(algoritm->getD());
	print(" uAu: "); print(algoritm->get_uAu());
	print(" uBu: "); print(algoritm->getD());
	print(" uBu: "); print(algoritm->get_uBu());
	print("\nvoltage: "); print(algoritm->getV());
	print("\n");
}



LamdaOptimisationScreen::~LamdaOptimisationScreen()
{
}
