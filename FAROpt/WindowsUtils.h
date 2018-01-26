#pragma once
#include <Windows.h>

class WindowsUtils
{
public:
	static LPWSTR wideString(const std::string& instr);
	static std::string string(LPWSTR instr);
	static void createDirectory(const std::string& path);
	static bool existsDirectory(const std::string& path);
	static void copy(std::string& from, std::string& to);
	static std::vector<std::string> contentsOfDirectory(const std::string& path);
	WindowsUtils();
	~WindowsUtils();
};

