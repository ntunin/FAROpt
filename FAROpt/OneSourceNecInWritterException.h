#pragma once
class OneSourceNecInWritterException: public std::exception {
private:
	std::string message;
public:
	OneSourceNecInWritterException();
	OneSourceNecInWritterException(const char *message);
	OneSourceNecInWritterException(std::string message);
	std::string getMessage();
	~OneSourceNecInWritterException();
};

