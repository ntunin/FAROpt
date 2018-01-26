#pragma once
#include "CacheManager.h"
class WindowsCacheManager :
	public CacheManager
{
private:
	std::string cachedFileName(OptimisationEnvirounment *envirounment);
	std::string WindowsCacheManager::cachedFileName(std::string name);
public:
	WindowsCacheManager(std::string path);
	bool cached(OptimisationEnvirounment *envirounment);
	void fill(OptimisationEnvirounment *envirounment);
	void cache(OptimisationEnvirounment *envirounment, std::string fileName);
	~WindowsCacheManager();
};

