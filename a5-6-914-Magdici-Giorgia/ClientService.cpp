#include "ClientService.h"

void ClientService::addCoatService(Coat c)
{
	this->basket.add(c);
	this->totalPrice += c.getPrice();

}


DynamicVector<Coat> ClientService::getCoatsWithSize(std::string size)
{
	DynamicVector<Coat> all_coats = this->storeRepo.getCoats();
	DynamicVector<Coat> resultVector{};
	for (int i = 0; i < all_coats.getSize(); i++)
	{
		Coat aux = all_coats[i];
		if (aux.getSize().find(size) != -1)
			resultVector.add(aux);
	}

	return resultVector;

}

DynamicVector<Coat> ClientService::getbasket()
{
	return this->basket;
}

double ClientService::getTotalPrice()
{
	return this->totalPrice;
}