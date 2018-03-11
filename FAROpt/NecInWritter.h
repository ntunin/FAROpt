#pragma once
class NecInWritter
{
	void writeStream(std::ofstream &stream);
	NecIn *in;
	std::string name;

	void write(std::ofstream &file, std::vector<NecCommand *> *commandsPointer);
	void write(std::ofstream &file, std::vector<EX *> *commandsPointer, ComplexVector *sources);
	void write(std::ofstream &file, NecCommand *command);

public:
	NecInWritter(NecIn *in, std::string name);
	~NecInWritter();
};

