#pragma once
#include "NecIn.h"
#include "NecOut.h"
#include <thread>
#include <string>

class ProcessRunner
{
public:
	ProcessRunner();
	virtual void run() = 0;
	void wait();
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

