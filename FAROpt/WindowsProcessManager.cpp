#include "stdafx.h"
#include "WindowsProcessManager.h"


WindowsProcessManager::WindowsProcessManager()
{
}


int WindowsProcessManager::getCoresCount() {
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	int numCPU = sysinfo.dwNumberOfProcessors;
	return numCPU;
}

WindowsProcessManager::~WindowsProcessManager()
{
}
