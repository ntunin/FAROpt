// FAROpt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;



int main(int argc, char **argv) {
	try {
		ofstream file;
		file.open("log.txt", std::ofstream::out);
		file.close();
		Log *log = new ConsoleLog();
		//Scanner *scanner = new FileScanner("run-script.txt");
		//Scanner *scanner = new ConsoleScanner;
		Scanner *scanner = new PredefinedScanner;
		ProcessManager *processManager = new WindowsProcessManager();
		CacheManager *cacheManager = new WindowsCacheManager("cache");
		TaskManager *taskManager = new WindowsTaskManager();
		Shared::bundle().log(log);
		Shared::bundle().scanner(scanner);
		Shared::bundle().processManager(processManager);
		Shared::bundle().cacheManager(cacheManager);
		Shared::bundle().taskManager(taskManager);
		WindowsRandomGenerator *generator = new WindowsRandomGenerator();
		Shared::bundle().randomGenerator(generator);
		LifeCycle *cycle = new LifeCycle();
		//for (int i = 0; i < 100; i++) {
			cycle->run();
		//}
		generator->stop();
		delete generator;
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

