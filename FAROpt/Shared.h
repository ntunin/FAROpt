#pragma once
#include "Log.h"
#include "Scanner.h"
#include "ProcessManager.h"

class Shared
{
private:
	Shared();
	Log *logInstance;
	Scanner *scannerInstance;
	ProcessManager *processManagerInstance;
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

	~Shared();
};

