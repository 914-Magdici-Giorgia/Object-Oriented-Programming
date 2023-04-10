#include "CoatValidator.h"
#pragma once
using namespace std;

ValidationException::ValidationException(std::string m):message{m}
{
}

std::string ValidationException::getMessage() const
{
	return this->message;
}

void CoatValidator::validate(const Coat& c)
{
	string errors;
	string size = c.getSize();
	if (size != "XS" && size != "S" && size != "M" && size != "L" && size != "XL" && size != "XXL") {
		errors += string("Invalid size\n");
	}
	
	if (c.getQuantity() < 0) {
		errors += string("Quantity can't be <0\n");
	}

	if (c.getPrice() < 0) {
		errors += string("Price can't be <0\n");
	}
	if (c.getPhotograph().size() <3) {
		errors += string("Link can't be less than 3 characters\n");
	}
	if (c.getColour().size() < 3) {
		errors += string("Colour can't be less than 3 characters\n");
	}

	if (errors.size() > 0) {
		throw ValidationException(errors);
	}
}
