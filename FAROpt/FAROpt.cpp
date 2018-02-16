// FAROpt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;



int main(int argc, char **argv) {
	try {
		Log *log = new ConsoleLog();
		Scanner *scanner = new FileScanner("run-script.txt");
		ProcessManager *processManager = new WindowsProcessManager();
		CacheManager *cacheManager = new WindowsCacheManager("cache");
		TaskManager *taskManager = new WindowsTaskManager();
		Shared::bundle().log(log);
		Shared::bundle().scanner(scanner);
		Shared::bundle().processManager(processManager);
		Shared::bundle().cacheManager(cacheManager);
		Shared::bundle().taskManager(taskManager);
		LifeCycle *cycle = new LifeCycle();
		cycle->run();
		delete cycle;
		delete scanner;
		delete log;
		delete processManager;
		delete cacheManager;

	} catch (exception e) {
		cout << e.what() << endl;
	};
    return 0;
}

