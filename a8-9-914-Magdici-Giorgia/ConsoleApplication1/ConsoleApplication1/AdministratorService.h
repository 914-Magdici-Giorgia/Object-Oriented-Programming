#pragma once

#include"Repository.h"
#include"CoatValidator.h"

class AdministratorService {
private:
	Repository repo;
public:
	AdministratorService( Repository r) : repo(r) {};

	//creates a coat with the given information and tries to add it 
	void addCoatService( Coat& c);

	//tries to remove a coat from a given position
	void removeCoatService(int pos);

	//tries to update the coat from a given position with a new coat 
	void updateCoatService(int position, const std::string size, const std::string color, const int quantity, const double price, const std::string photo);

	//returns the DynamicVector of coats
	vector<Coat> getCoatsService();

	Repository getRepo() { return this->repo; };
	
};