// FAROpt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));
	try {
		NecIn *in = new NecIn;
		NecInParser(string(argv[1]), in);
		int count = in->getEX()->size();
		OneSourceThread **threads = new OneSourceThread*[count];
		NecOut **outs = new NecOut*[count];
		for (int i = 0; i < count; i++) {
			outs[i] = new NecOut;
			threads[i] = new OneSourceThread(in, outs[i],  i);
		}
		for (int i = 0; i < count; i++) {
			threads[i]->wait();
		}
		delete in;
		system("pause");
	} catch (FileException e) {
		cout << e.getMessage().c_str() << endl;
	};
    return 0;
}

