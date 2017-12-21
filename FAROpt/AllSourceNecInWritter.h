#pragma once
class AllSourceNecInWritter {

private:
	void writeStream(std::ofstream &stream);
	ComplexVector *sources;
	NecIn *in;
	std::string name;

	void write(std::ofstream &file, std::vector<NecCommand *> *commandsPointer);
	void write(std::ofstream &file, std::vector<EX *> *commandsPointer, ComplexVector *sources);
	void write(std::ofstream &file, NecCommand *command);

public:
	AllSourceNecInWritter(ComplexVector *sourceValues, NecIn *in, std::string name);
	~AllSourceNecInWritter();
};

