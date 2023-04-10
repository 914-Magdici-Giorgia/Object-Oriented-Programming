#include"Repository.h"

#include"CoatValidator.h"
#include<iostream>

void Repository::addCoatRepo( Coat& coat)
{
	/*int exists = existingCoat(coat);
	if (exists == -1) {
		this->coats.push_back(coat);
		return 1;
	}
	else
	{
		return 0;
	}*/



	CoatValidator::validate(coat);

	int pos = existingCoat(coat);
	if (pos == -1) {
		this->coats.push_back(coat);
	}
	else
		throw ValidationException("Coat already exists");
	
}

void Repository::deleteCoatRepo(int pos)
{
	if (pos<0 || pos>this->coats.size())
		throw ValidationException("Wrong index");

	this->coats.erase(this->coats.begin() + pos);

}

void Repository::updateCoatRepo(const Coat& coat, int position)
{
	int exists = existingCoat(coat);
	if (exists != -1)
		throw ValidationException("New coat already exists");
	if (position < 0 || position >= getSize())
		throw ValidationException("Wrong index. No coat there to replace");
	this->coats.erase(this->coats.begin() + position);
	this->coats.insert(this->coats.begin() + position, coat);
}

vector<Coat> Repository::getCoats()
{
	return this->coats;
}

int Repository::getSize()
{
	return this->coats.size();
}

void Repository::modifyQuantity(Coat c)
{
	int pos = existingCoat(c);
	this->coats[pos].setQuantity(this->coats[pos].getQuantity() - 1);

}


int Repository::existingCoat(const Coat& coat)
{
	int i = 0;
	for (Coat aux : this->coats) {
		if (aux == coat)
			return i;
		i++;
	}
	return -1;
}


//keep

