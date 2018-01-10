#pragma once
#include "ProcessManager.h"
class WindowsProcessManager :
	public ProcessManager
{
public:
	int getCoresCount();
	WindowsProcessManager();
	~WindowsProcessManager();
};

