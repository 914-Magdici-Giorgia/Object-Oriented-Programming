#include"Repository.h"
#include<iostream>

int Repository::addCoatRepo(const Coat& coat)
{
	int exists = existingCoat(coat);
	if (exists == -1) {
		this->coats.add(coat);
		return 1;
	}
	else
		return 0;
}

int Repository::deleteCoatRepo(const Coat& coat)
{
	int exists = existingCoat(coat);
	if (exists != -1) {
		this->coats.remove(coat);
		return 1;
	}
	else
		return 0;
}

int Repository::updateCoatRepo(const Coat& coat, int position)
{
	int exists = existingCoat(coat);
	if (exists != -1)
		return 0;
	if (position < 0 || position >= getSize())
		return 0;
	this->coats.update(coat, position);
	return 1;
}

DynamicVector<Coat> Repository::getCoats()
{
	return this->coats;
}

int Repository::getSize()
{
	return this->coats.getSize();
}

int Repository::existingCoat(const Coat& coat)
{
	Coat auxiliar;
	for (int i = 0; i < getSize(); i++) {
		auxiliar = this->coats[i];
		if (auxiliar == coat)
			return i;
	}
	return -1;
}