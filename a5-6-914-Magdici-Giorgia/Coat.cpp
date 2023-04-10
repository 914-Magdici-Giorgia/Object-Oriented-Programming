#include "Coat.h"
#include <Windows.h>




Coat::Coat()
	:size(""), colour(""), quantity(0), price(0), photograph("")
{}

Coat::Coat(const std::string& _size, const std::string& _colour, const int& _quantity, const double& _price, const std::string& _photograph)
	: size(_size), colour(_colour), quantity(_quantity), price(_price), photograph(_photograph)
{}


Coat::Coat(const Coat& c)
	: quantity(c.quantity), price(c.price), size(c.size), colour(c.colour), photograph(c.photograph)
{
}

Coat::~Coat() {
	price = 0;
	quantity = 0;
	size = "";
	colour = "";
	photograph = "";
}

double Coat::getPrice()
{
	return this->price;
}

int Coat::getQuantity()
{
	return this->quantity;
}

std::string Coat::getSize()
{
	return this->size;
}

std::string Coat::getColour()
{
	return this->colour;
}

std::string Coat::getPhotograph()
{
	return this->photograph;
}

void Coat::setPrice(double price)
{
	this->price = price;
}

void Coat::setQuantity(int quantity)
{
	this->quantity = quantity;
}

void Coat::setColour(std::string colour)
{
	this->colour = colour;
}

void Coat::setSize(std::string size)
{
	this->size = size;
}

void Coat::setPhotograph(std::string photograph)
{
	this->photograph = photograph;
}

Coat& Coat::operator=(const Coat& coat)
{
	if (this == &coat)
		return *this;

	this->quantity = coat.quantity;
	this->price = coat.price;
	this->colour = coat.colour;
	this->size = coat.size;
	this->photograph = coat.photograph;

	return *this;
}

bool Coat::operator==(const Coat& other_coat)
{
	return (other_coat.photograph == this->photograph && this->size==other_coat.size);
}

bool Coat::operator!=(const Coat& other_coat)
{
	return (other_coat.photograph != this->photograph && this->size != other_coat.size);
}


