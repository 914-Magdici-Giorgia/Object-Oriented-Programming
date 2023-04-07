#pragma once


#include "AdministratorService.h"
#include"ClientService.h"
class UI {
private:
	AdministratorService admService;
	ClientService clService;


public:
	UI(const AdministratorService admServ, const ClientService clServ) : admService(admServ), clService(clServ) {}
	void admAddCoat();
	void admRemoveCoat();
	void admUpdateCoat();
	void admSeeCoats();

	void clSeeCoats();
	void clSeeShoppingBasket();




	void start();
};