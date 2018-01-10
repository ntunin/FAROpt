// FAROpt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;



int main(int argc, char **argv) {
	try {
		Log *log = new ConsoleLog();
		Scanner *scanner = new ConsoleScanner();
		ProcessManager *processManager = new WindowsProcessManager();
		Shared::bundle().log(log);
		Shared::bundle().scanner(scanner);
		Shared::bundle().processManager(processManager);
		LifeCycle *cycle = new LifeCycle();
		cycle->run();
		delete cycle;
		delete scanner;
		delete log;
		delete processManager;

	} catch (exception e) {
		cout << e.what() << endl;
	};
    return 0;
}

