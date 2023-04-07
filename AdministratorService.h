#pragma once
 
#include"Repository.h"

class AdministratorService{
private:
	Repository repo;
public:
	AdministratorService(const Repository r) : repo(r){};

	//creates a coat with the given information and tries to add it 
	int addCoatService(const std::string size, const std::string color, const int quantity, const double price, const std::string photo);

	//tries to remove a coat from a given position
	int removeCoatService(int pos);

	//tries to update the coat from a given position with a new coat 
	int updateCoatService(int position, const std::string size, const std::string color, const int quantity, const double price, const std::string photo);

	//returns the DynamicVector of coats
	DynamicVector<Coat> getCoatsService();

};