
#include "Coat.h"
#include <Windows.h>
#include<iostream>
#include<vector>
#include <sstream>
using namespace std;

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

double Coat::getPrice() const
{
	return this->price;
}

int Coat::getQuantity() const
{
	return this->quantity;
}

std::string Coat::getSize() const
{
	return this->size;
}

std::string Coat::getColour() const
{
	return this->colour;
}

std::string Coat::getPhotograph() const
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
	return (other_coat.photograph == this->photograph && this->size == other_coat.size);
}

bool Coat::operator!=(const Coat& other_coat)
{
	return (other_coat.photograph != this->photograph && this->size != other_coat.size);
}


/*
	Tokenizes a string.
	Input:	str - the string to be tokenized.
			delimiter - char - the delimiter used for tokenization
	Output: a vector of strings, containing the tokens
*/
vector<string> tokenize(string str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, ','))
		result.push_back(token);

	return result;
}
std::istream& operator>>(std::istream& is, Coat& c)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) // make sure all the starship data was valid
		return is;
	
	c.size = tokens[0];
	c.colour = tokens[1];
	c.quantity = stoi(tokens[2]);
	c.price = stod(tokens[3]);
	c.photograph = tokens[4];

	return is;
}

std::ostream& operator<<(std::ostream& os, const Coat& c)
{
	os << c.size << "," << c.colour << "," << c.quantity <<","<<c.price<<","<<c.photograph<< "\n";
	return os;
}

