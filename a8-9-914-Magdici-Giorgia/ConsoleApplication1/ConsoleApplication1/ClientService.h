#pragma once
#include"Repository.h"


class ClientService {
public:
	Repository storeRepo;
	vector<Coat> basket;
	double totalPrice;

public:

	ClientService(const Repository r, const vector<Coat> b) : storeRepo(r), basket(b), totalPrice(0) {};

	void addCoatService(Coat& c);

	//void seeBasKet();

	vector<Coat> getCoatsWithSize(std::string size);

	vector<Coat> getbasket();

	double getTotalPrice();
	virtual void writeToFile() const ;

};

class CSVClientService:public ClientService
{
private:
	std::string namefile;
public:
	CSVClientService(const Repository r, const vector<Coat> b,std::string namef);
	~CSVClientService();

	void writeToFile() const override;

};


class HTMLClientService :public ClientService
{
private:
	std::string namefile;
public:
	HTMLClientService(const Repository r, const vector<Coat> b, std::string namef);
	~HTMLClientService();

	void writeToFile() const override;

};