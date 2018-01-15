#pragma once
class Scanner
{
public:
	virtual int readInt(std::string message) = 0;
	virtual int readInt() = 0; 
	virtual std::string readString() = 0;
	virtual std::string readString(std::string message) = 0;
	virtual double readDouble() = 0;
	virtual double readDouble(std::string message) = 0;
	Scanner();
	~Scanner();
};

