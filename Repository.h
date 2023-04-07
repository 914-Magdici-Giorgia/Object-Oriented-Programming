#pragma once
#include"DynamicVector.h"
#include"Coat.h"

class Repository {
private:
	DynamicVector<Coat> coats;
public:
	Repository() {};

	//adds a coat in repo if it doesn't exist. Returns 1 if successfull, 0 if the coat existed already
	int addCoatRepo(const Coat&);

	//deletes a coat from repo if id exists.Returns 1 if successfull, 0 if the coat did not exist in repo
	int deleteCoatRepo(const Coat&);

	//replaces a coat from repo with a new one. Returns 1 if successfull, 0 if the position ia not valid or the new coat already exists
	int updateCoatRepo(const Coat&, int);


	//returns the list of coats
	DynamicVector<Coat> getCoats();

	//returns the numer of elementsin repo
	int getSize();

private:

	//checks if a coat exists in repo
	int existingCoat(const Coat&);
};