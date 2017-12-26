#pragma once
#include "Log.h"
#include "Scanner.h"

class Shared
{
private:
	Shared();
	Log *logInstance;
	Scanner *scannerInstance;
public:
	static Shared& bundle() {
		static Shared bndl;
		return bndl;
	}

	Log *log();
	void log(Log *);

	Scanner *scanner();
	void scanner(Scanner *);

	~Shared();
};

