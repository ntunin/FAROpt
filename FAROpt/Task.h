#pragma once
class Task
{
private:
	std::string id;
public:
	virtual void execute() = 0;
	void assign(std::string id); 
	std::string getId();
	Task();
	~Task();
};

