// FAROpt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;



int main(int argc, char **argv) {
	try {
		Log *log = new ConsoleLog();
		Scanner *scanner = new ConsoleScanner();
		Shared::bundle().log(log);
		Shared::bundle().scanner(scanner);
		LifeCycle *cycle = new LifeCycle();
		cycle->run();
		delete cycle;
		delete scanner;
		delete log;

	} catch (exception e) {
		cout << e.what() << endl;
	};
    return 0;
}

