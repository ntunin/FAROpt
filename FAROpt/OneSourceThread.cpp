#include "stdafx.h"
#include "OneSourceThread.h"
#include <sstream>
#include <iostream>
#include <tchar.h>
#include <stdio.h> 
#include <strsafe.h>

using namespace std;

OneSourceThread::OneSourceThread(NecIn *in, NecOut *out, int sourceNumber) {
	this->in = in;
	this->out = out;
	this->sourceNumber = sourceNumber;
	this->createThread();
}

void OneSourceThread::randomize() {
	stringstream s;
	this->thread.get_id()._To_text(s);
	int i = atoi(s.str().c_str());
	int t = time(NULL) % 10 + time(NULL) % 20 * 50 + time(NULL) % 50 * 20;
	t *= i * 10 * (this->sourceNumber + 1);
	srand(t);
}

string buildInOutArgs(string inName, string outName) {
	stringstream command;
	command << inName << endl;
	command << outName << endl;
	string commandString = command.str();
	return commandString;
}

void OneSourceThread::run() {
	randomize();
	string name = createName(this->thread.get_id(), this->sourceNumber);
	string inName = string(name).append(".nec");
	string outName = string(name).append(".out");
	OneSourceNecInWritter(this->sourceNumber, this->in, inName);
	string commandString = buildInOutArgs(inName, outName);
	Shared::bundle().log()->print(string("Temporary i/o name: ").append(name).append("\n"));
	this->exe(string("nec2dxs11k.exe"), commandString);
	Shared::bundle().log()->print(string("The nec2 finised. Temporary i/o with name: ").append(name).append(" was removed\n"));
	stringstream command;
	command << "tmp-" << this->sourceNumber<<".out";
	string tmpName = command.str();
	NecOutParser(outName, out);
	removeFile(inName);
	removeFile(outName);
}

string OneSourceThread::createName(thread::id id, int number) {
	stringstream s;
	s << "tmp-" << abs(rand() % 1000 + 1) << "-";
	id._To_text(s);
	s << "-" << number;
	return s.str();
}

void OneSourceThread::removeFile(string &name) {
	if (remove(name.c_str()) != 0) {
		Shared::bundle().log()->print(string("could not remove the file ").append(name).append("\n"));
	}
}



OneSourceThread::OneSourceThread() {

}




OneSourceThread::~OneSourceThread()
{
}