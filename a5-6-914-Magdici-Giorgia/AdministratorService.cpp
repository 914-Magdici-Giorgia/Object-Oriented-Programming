#include "AdministratorService.h"

int AdministratorService::addCoatService(const std::string size, const std::string colour, const int quantity, const double price, const std::string photo)
{
	Coat coat{ size,colour, quantity,price,photo };
	return this->repo.addCoatRepo(coat);
}

int AdministratorService::removeCoatService(int pos)
{
	if (pos < 0 || pos >= this->getCoatsService().getSize())
		return 0;
	Coat coat = this->getCoatsService()[pos];
	return this->repo.deleteCoatRepo(coat);
}

int AdministratorService::updateCoatService(int position, const std::string size, const std::string colour, const int quantity, const double price, const std::string photo)
{
	Coat coat{ size,colour, quantity,price,photo };
	return this->repo.updateCoatRepo(coat, position);
}

DynamicVector<Coat> AdministratorService::getCoatsService()
{
	return this->repo.getCoats();
}