#pragma once
#include "NecOut.h"
#include "OptimisationEnvirounment.h"
class CacheManager {
public:
	CacheManager();
	~CacheManager();
	virtual bool cached(OptimisationEnvirounment *envirounment) = 0;
	virtual void fill(OptimisationEnvirounment *envirounment) = 0;
	virtual void cache(OptimisationEnvirounment *envirounment, std::string fileName) = 0;
protected:
	std::string path;
};

