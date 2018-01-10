#pragma once
#include "NecIn.h"
#include "NecOut.h"
#include <thread>
#include <string>
#include <Windows.h>

class ProcessRunner
{
public:
	ProcessRunner();
	void run();
	void wait();
	virtual void dispatch() = 0;
	~ProcessRunner();
protected:
	void exe(std::string &command, std::string &arguments);
	void exe(std::string &command);
	void createThread();
	std::thread thread;
private:
	HANDLE g_hChildStd_IN_Rd = NULL;
	HANDLE g_hChildStd_IN_Wr = NULL;
	HANDLE g_hChildStd_OUT_Rd = NULL;
	HANDLE g_hChildStd_OUT_Wr = NULL;

	HANDLE g_hInputFile = NULL;

	void CreateChildProcess(LPWSTR cmd, std::string &input);
	void WriteToPipe(std::string &str);
	void ReadFromPipe(void);
	void ErrorExit(PTSTR);
};

