#pragma once
#include "Log.h"
#include "Scanner.h"
#include "ProcessManager.h"
#include "CacheManager.h"
#include "TaskManager.h"
#include "RandomGenerator.h"

class Shared
{
private:
	Shared();
	Log *logInstance;
	Scanner *scannerInstance;
	ProcessManager *processManagerInstance;
	CacheManager *cahceManagerInstance;
	TaskManager *taskManagerInstance;
	RandomGenerator *generatorInstance;
public:
	static Shared& bundle() {
		static Shared bndl;
		return bndl;
	}

	Log *log();
	void log(Log *);

	Scanner *scanner();
	void scanner(Scanner *);

	ProcessManager *processManager();
	void processManager(ProcessManager *);

	CacheManager *cacheManager();
	void cacheManager(CacheManager *);

	TaskManager *taskManager();
	void taskManager(TaskManager *);

	RandomGenerator *randomGenerator();
	void randomGenerator(RandomGenerator *);

	~Shared();
};

