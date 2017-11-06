#include "stdafx.h"
#include "OneSourceThread.h"
#include <sstream>
#include <iostream>
#include <mutex> 
#include <tchar.h>
#include <stdio.h> 
#include <strsafe.h>
#define BUFSIZE 4096

std::mutex mtx;

using namespace std;

OneSourceThread::OneSourceThread() {

}

void treamMethod(OneSourceThread *oneSourceThread) {
	oneSourceThread->calculate();
}

OneSourceThread::OneSourceThread(NecIn *in, NecOut *out, int sourceNumber) {
	this->in = in;
	this->out = out;
	this->sourceNumber = sourceNumber;
	this->thread = std::thread(treamMethod, this);
}


OneSourceThread::~OneSourceThread()
{
}

string createName(thread::id id, int number) {
	stringstream s;
	s << "tmp-"<< abs(rand())<<"-";
	id._To_text(s);
	s <<"-"<<number;
	return s.str();
}

void log(string message) {
	unique_lock<mutex> lck(mtx, defer_lock);
	lck.lock();
	std::cout << message << endl;
	lck.unlock();
}

void OneSourceThread::nec2(string &name) {
	std::wstring wName = std::wstring(name.begin(), name.end());
	LPWSTR lpName = const_cast<wchar_t *>(wName.c_str());

	SECURITY_ATTRIBUTES saAttr;

	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	saAttr.bInheritHandle = TRUE;
	saAttr.lpSecurityDescriptor = NULL;

	// Create a pipe for the child process's STDIN. 

	if (!CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0))
		ErrorExit(TEXT("Stdin CreatePipe"));

	// Ensure the write handle to the pipe for STDIN is not inherited. 

	if (!SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0))
		ErrorExit(TEXT("Stdin SetHandleInformation"));

	// Create the child process. 

	stringstream command;
	command << name << ".nec" << endl;
	command << name << ".out" << endl;

	CreateChildProcess(L"nec2dxs11k.exe", command.str());


	return;
}

void OneSourceThread::calculate() {
	string name = createName(this->thread.get_id(), this->sourceNumber);
	log(string("start writting ").append(name));
	//OneSourceNecInWritter(this->sourceNumber, this->in, string(name).append(".nec"));
	//nec2(name);
	stringstream stream;
	stream << "tmp-" << this->sourceNumber << ".out";
	NecOutParser(stream.str(), out);
}

void OneSourceThread::wait() {
	this->thread.join();
}

void OneSourceThread::CreateChildProcess(LPWSTR cmd, string &input) {
	PROCESS_INFORMATION piProcInfo;
	STARTUPINFO siStartInfo;
	BOOL bSuccess = FALSE;

	// Set up members of the PROCESS_INFORMATION structure. 

	ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

	// Set up members of the STARTUPINFO structure. 
	// This structure specifies the STDIN and STDOUT handles for redirection.

	ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
	siStartInfo.cb = sizeof(STARTUPINFO);
	siStartInfo.hStdInput = g_hChildStd_IN_Rd;
	siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

	// Create the child process. 

	bSuccess = CreateProcess(cmd,
		NULL,     // command line 
		NULL,          // process security attributes 
		NULL,          // primary thread security attributes 
		TRUE,          // handles are inherited 
		CREATE_NEW_CONSOLE,             // creation flags 
		NULL,          // use parent's environment 
		NULL,          // use parent's current directory 
		&siStartInfo,  // STARTUPINFO pointer 
		&piProcInfo);  // receives PROCESS_INFORMATION 

					   // If an error occurs, exit the application. 
	if (!bSuccess)
		ErrorExit(TEXT("CreateProcess"));
	else {
		WriteToPipe(input);
		WaitForSingleObject(piProcInfo.hProcess, INFINITE);
		CloseHandle(piProcInfo.hProcess);
		CloseHandle(piProcInfo.hThread);
	}
}

void OneSourceThread::WriteToPipe(string &input) {
	DWORD dwWritten;
	CHAR chBuf[BUFSIZE];
	BOOL bSuccess = FALSE;


	bSuccess = WriteFile(g_hChildStd_IN_Wr, input.c_str(), input.size(), &dwWritten, NULL);

	// Close the pipe handle so the child process stops reading. 

	if (!CloseHandle(g_hChildStd_IN_Wr))
		ErrorExit(TEXT("StdInWr CloseHandle"));
}

void OneSourceThread::ReadFromPipe(void) {
	DWORD dwRead, dwWritten;
	CHAR chBuf[BUFSIZE];
	BOOL bSuccess = FALSE;
	HANDLE hParentStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	for (;;)
	{
		bSuccess = ReadFile(g_hChildStd_OUT_Rd, chBuf, BUFSIZE, &dwRead, NULL);
		if (!bSuccess || dwRead == 0) break;

		bSuccess = WriteFile(hParentStdOut, chBuf,
			dwRead, &dwWritten, NULL);
		if (!bSuccess) break;
	}
}

void OneSourceThread::ErrorExit(PTSTR lpszFunction) {
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);

	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
	StringCchPrintf((LPTSTR)lpDisplayBuf,
		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error %d: %s"),
		lpszFunction, dw, lpMsgBuf);
	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
	ExitProcess(1);
}
