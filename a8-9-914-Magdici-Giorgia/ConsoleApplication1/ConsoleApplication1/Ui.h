#pragma once


#include "AdministratorService.h"
#include"ClientService.h"
#include<fstream>
#include"CoatValidator.h"
class UI {
private:
	AdministratorService admService;
	ClientService* clService ;
	std::string DataFile;


public:
	UI(const AdministratorService admServ,  ClientService* clServ,const std::string file) : admService(admServ), clService(clServ),DataFile(file) {}
	
	void admAddCoat();
	void admRemoveCoat();
	void admUpdateCoat();
	void admSeeCoats();

	void clSeeCoats();
	void clSeeShoppingBasket();
	void clSeeBasketFile();

	void updateData();

	void start();
};//keep
