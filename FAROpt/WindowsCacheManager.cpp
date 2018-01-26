#include "stdafx.h"
#include "WindowsCacheManager.h"
#include "WindowsUtils.h"


WindowsCacheManager::WindowsCacheManager(std::string path) {
	this->path = path;
	WindowsUtils::createDirectory(path);
}

std::string WindowsCacheManager::cachedFileName(OptimisationEnvirounment *envirounment) {
	std::stringstream str;
	str << path << "/" << envirounment->getName();
	return str.str();
}

std::string WindowsCacheManager::cachedFileName(std::string name) {
	std::stringstream str;
	str << path << "/" << name;
	return str.str();
}

bool WindowsCacheManager::cached(OptimisationEnvirounment *envirounment) {
	std::string path = cachedFileName(envirounment);
	return WindowsUtils::existsDirectory(path);
}

void WindowsCacheManager::fill(OptimisationEnvirounment *envirounment) {
	std::string path = cachedFileName(envirounment);
	std::vector<std::string> files = WindowsUtils::contentsOfDirectory(path);
	int count = files.size();
	NecOut **outs = envirounment->getOuts();
	for (int i = 0; i < count; i++) {
		std::string path = cachedFileName(envirounment).append("/").append(files[i]);
		int start = path.find_last_of('-') + 1;
		int end = path.find_last_of('.');
		int n = atoi(path.substr(start, end - start).c_str());
		NecOutParser(path, outs[n]);
	}
}


void WindowsCacheManager::cache(OptimisationEnvirounment *envirounment, std::string fileName) {
	std::string path = cachedFileName(envirounment);
	WindowsUtils::createDirectory(path);
	WindowsUtils::copy(fileName, path.append("/").append(fileName));
}


WindowsCacheManager::~WindowsCacheManager()
{
}
