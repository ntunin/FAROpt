#pragma once
;
class TableValueParser {
public:
	TableValueParser(std::string str);
	~TableValueParser();
	int getInt();
	double getDouble();
	std::string getString();
	void setInput(std::string str);
private:
	int index;
	int state;
	int sign;
	std::string input;
	std::string buffer;
	double mantissa;
	double exponenta;
	void parseSign(char c);
	void parseMantissa(char c);
	void parseExponenta(char c);
	void skipSpaces(char c);
	void parseString(char c);
	void parseInput();
};

