#pragma once
#include "FileStreamHandler.h"
class BHandler :
	public FileStreamHandler
{
public:
	void readContent(std::ifstream *file, FileStructure *structure);
	BHandler();
	~BHandler();
};

