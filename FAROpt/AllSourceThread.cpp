#include "stdafx.h"
#include "AllSourceThread.h"
#include <sstream>
#include <iostream>
#include <tchar.h>
#include <stdio.h> 
#include <strsafe.h>

#define BUFSIZE 4096



using namespace std;

AllSourceThread::AllSourceThread(LamdaOptimisator *optimisator, LamdaOptimisator::Optimisation *optimisation, const char *fileName, NecOut *out) {
	this->optimisator = optimisator;
	this->optimisation = optimisation;
	this->fileName = string(fileName);
	this->out = out;
	this->createThread();
}

void AllSourceThread::run() {
	string inName = string(this->fileName).append(".nec");
	string outName = string(this->fileName).append(".out");
	AllSourceNecInWritter(this->optimisation->getV(), this->optimisator->getNecIn(), inName);
	stringstream command;
	command << inName << endl;
	command << outName << endl;
	string commandString = command.str();
	Shared::bundle().log()->print(string("Please wait while nec2 making calculations for optimased sources. i/o name: ").append(this->fileName));
	this->exe(string("nec2dxs11k.exe"), commandString);
	Shared::bundle().log()->print(string("The nec2 finised. i/o name: ").append(this->fileName));
	NecOutParser(outName, out);
}

NecOut *AllSourceThread::getOut() {
	return this->out;
}

AllSourceThread::~AllSourceThread()
{
}