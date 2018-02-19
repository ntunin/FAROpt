#pragma once
#include <mutex>
class RandomGenerator
{
public:
	virtual int next() = 0;
	RandomGenerator();
	~RandomGenerator();
};

