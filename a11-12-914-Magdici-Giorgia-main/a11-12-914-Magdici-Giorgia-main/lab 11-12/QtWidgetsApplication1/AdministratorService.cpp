#include "AdministratorService.h"
#include<iostream>
using namespace std;

void AdministratorService::addCoatService( Coat& c)
{
	
	this->repo.addCoatRepo(c);
	}
	

void AdministratorService::removeCoatService(int pos)
{
	this->repo.deleteCoatRepo(pos); 
}

void AdministratorService::updateCoatService(int position, const std::string size, const std::string colour, const int quantity, const double price, const std::string photo)
{
	Coat coat{ size,colour, quantity,price,photo };
	this->repo.updateCoatRepo(coat, position);
}

vector<Coat> AdministratorService::getCoatsService()
{
	return this->repo.getCoats();
}
//keep