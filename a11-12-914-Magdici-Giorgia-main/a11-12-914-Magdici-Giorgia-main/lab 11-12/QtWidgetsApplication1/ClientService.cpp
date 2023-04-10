#include "ClientService.h"
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

void ClientService::addCoatService(Coat& c)
{
	this->storeRepo.modifyQuantity(c);
	bool alreadyInBasket = false;


	int pos = 0;
	for (auto x : this->basket) {
		if (x == c) {
			alreadyInBasket = true;
			break;
		}
		pos++;
	}

	if (alreadyInBasket == false) {
		Coat newCoat = c;
		newCoat.setQuantity(1);
		this->basket.push_back(newCoat);
	}
	else {
		this->basket[pos].setQuantity(this->basket[pos].getQuantity() + 1);
	}

	this->totalPrice += c.getPrice();


}


vector<Coat> ClientService::getCoatsWithSize(std::string size)
{


	vector<Coat> all_coats = this->storeRepo.getCoats();
	int count = count_if(all_coats.begin(), all_coats.end(), [size](Coat c) {return c.getSize().find(size) != -1; });
	vector<Coat> resultVector(count);

	//for (int i = 0; i < all_coats.size(); i++)
	//{
	//	Coat aux= all_coats[i];
	//	if (aux.getSize().find(size) != -1)
	//		resultVector.push_back(aux);
	//}

	copy_if(all_coats.begin(), all_coats.end(), resultVector.begin(), [size](Coat c) {return c.getSize().find(size) != -1; });

	return resultVector;

}

vector<Coat> ClientService::getbasket()
{
	return this->basket;
}

double ClientService::getTotalPrice()
{
	return this->totalPrice;
}
//void ClientService::writeToFile() const
//{
//
//}


CSVClientService::CSVClientService(const Repository r, const vector<Coat> b,std::string namef):ClientService{r,b},namefile{namef}
{
}

CSVClientService::~CSVClientService()
{
}

void CSVClientService::writeToFile() const 
{
	ofstream f(this->namefile);
	if (!f.is_open())
		return;
	

	for (auto c : this->basket) {
		f << c;
	}
	
	f.close();
	
	system("notepad Basket.csv");
}

HTMLClientService::HTMLClientService(const Repository r, const vector<Coat> b,std::string namef) :ClientService{ r,b }, namefile{ namef }
{
}

HTMLClientService::~HTMLClientService()
{
}

void HTMLClientService::writeToFile() const
{
	ofstream f(this->namefile);
	if (!f.is_open())
		return;
	f << "<!DOCTYPE html><html><head><title>Basket</title></head>";
	f << "<body><table border=\"1\"> <tr><td>Size</td><td>Colour</td><td>quantity</td><td>Price/piece</td><td>Store link</td> </tr>";

	for (auto c : this->basket) {
		f << "<tr><td>" << c.getSize() << "</td><td>" << c.getColour() << "</td><td>" << c.getQuantity() << "</td><td>" << c.getPrice() << "</td><td><a href=\" " << c.getPhotograph() << "\">Link</a></td> </tr>";
	}
	f << "</table></body></html> ";


	f.close();
	std::string file = namefile;
	ShellExecute(NULL, NULL, std::wstring(file.begin(), file.end()).c_str(),
		NULL, NULL, SW_SHOWNORMAL);
}
