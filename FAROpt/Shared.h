#pragma once
#include "Log.h"

class Shared
{
private:
	Shared();
	Log *logInstance;
public:
	static Shared& bundle() {
		static Shared bndl;
		return bndl;
	}

	Log *log();
	void log(Log *);
	~Shared();
};

