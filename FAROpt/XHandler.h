#pragma once
#include "FileStreamHandler.h"
class XHandler :
	public FileStreamHandler
{
public:
	XHandler();
	~XHandler();
	void readContent(std::ifstream *file, FileStructure *structure);
};

