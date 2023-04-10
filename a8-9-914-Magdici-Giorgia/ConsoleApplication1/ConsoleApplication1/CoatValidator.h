#pragma once
#include<string>
#include"Coat.h"


class ValidationException {
private:
	std::string message;
public:
	ValidationException(std::string m);
	std::string getMessage() const;
};

class CoatValidator {
	public:
		static void validate(const Coat& c);
};