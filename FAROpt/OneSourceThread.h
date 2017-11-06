#pragma once
#include "NecIn.h"
#include "NecOut.h"
#include <thread>
#include <string>

class OneSourceThread
{
public:
	OneSourceThread();
	OneSourceThread(NecIn *in, NecOut *out, int sourceNumber);
	void calculate();
	void wait();
	~OneSourceThread();
private:
	NecIn *in;
	NecOut *out;
	int sourceNumber;
	std::thread thread;
	HANDLE g_hChildStd_IN_Rd = NULL;
	HANDLE g_hChildStd_IN_Wr = NULL;
	HANDLE g_hChildStd_OUT_Rd = NULL;
	HANDLE g_hChildStd_OUT_Wr = NULL;

	HANDLE g_hInputFile = NULL;

	void CreateChildProcess(LPWSTR cmd, std::string &input);
	void WriteToPipe(std::string &str);
	void ReadFromPipe(void);
	void ErrorExit(PTSTR); 
	void nec2(std::string &name);

	
};

