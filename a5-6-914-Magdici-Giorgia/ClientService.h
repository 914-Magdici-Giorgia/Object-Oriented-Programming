#pragma once
#include"Repository.h"
#include"DynamicVector.h"

class ClientService {
private:
	Repository storeRepo;
	DynamicVector<Coat> basket;
	double totalPrice;

public:

	ClientService(const Repository r, const DynamicVector<Coat> b) : storeRepo(r), basket(b), totalPrice(0) {};

	void addCoatService(Coat c);

	//void seeBasKet();

	DynamicVector<Coat> getCoatsWithSize(std::string size);

	DynamicVector<Coat> getbasket();

	double getTotalPrice();

};