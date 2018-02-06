#pragma once
#include "FileStreamHandler.h"
class AHandler :
	public FileStreamHandler
{
public:
	AHandler();
	~AHandler();
	void readContent(std::ifstream *file, FileStructure *structure);
};

