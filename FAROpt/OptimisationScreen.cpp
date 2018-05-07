#include "stdafx.h"
#include "OptimisationScreen.h"
#include <ctime>

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
	this->Y = envirounment->getY();
	FAROptimisationAlgoritm *algoritm = getAgoritm(envirounment);
	printAlgoritmResult(algoritm, envirounment);
	print("\n");
	print("working time: ");
	print(workingTime*1.0 / 1000);
	print("s\n\n");
	print("\n");
	/*NecOut *out = new NecOut();
	string resultOutName = readString("Please provide the name of result nec file: > ");
	AllSourceThread *thread = new AllSourceThread(envirounment->getIn(), algoritm->getV(), resultOutName.c_str(), out);
	thread->wait();
	NecOutPlotDrawer *drawer = new NecOutPlotDrawer(out, theta, phi);
	drawer->wait();;*/
	//system("pause");
	delete in;
	//delete out;
	//delete thread;
	//delete drawer;
	delete envirounment;
}

void OptimisationScreen::printAlgoritmResult(FAROptimisationAlgoritm *algoritm, OptimisationEnvirounment *envirounment) {
	FileLog log("log.txt");
	//ConsoleLog log = *(ConsoleLog *)Shared::bundle().log();
	log.print(" uAu: "); 
	log.print(algoritm->get_uAu());
	log.print("\t");
	vector<double> *uBu = algoritm->get_uBu();
	int size = uBu->size();
	log.print(" uBu: "); 
	for (int i = 0; i < size; i++) {
		log.print((*uBu)[i]);
		log.print("\t");
	}
	log.print("\nvoltage: "); 
	log.print(*algoritm->getV());
	double *I = new double[2 * size];
	Utils::mul(2 * size, envirounment->getY()->doubleExtend(), algoritm->getV()->extendDouble(), I);
	//log.print("\ncurrents:\n");
	//log.print(I, 2 * size);
	log.print("\n");
	print("working time: ");
	print(workingTime*1.0/1000);
	print("s\n\n");
	system("pause");
}



OptimisationScreen::~OptimisationScreen()
{
}
