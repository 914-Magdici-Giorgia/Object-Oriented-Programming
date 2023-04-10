#include "UI.h"
#include<iostream>
#include <windows.h>
#include <shellapi.h>
#include <vector>
#include <algorithm>


using namespace std;

void UI::admAddCoat()
{
	string colour, size, photograph, quantity, price;
	cout << "\n Enter a colour:";
	getline(cin, colour);
	cout << "\n Enter a size:";
	getline(cin, size);
	cout << "\n Enter a quantity:";
	getline(cin, quantity);
	cout << "\n Enter a price:";
	getline(cin, price);
	cout << "\n Enter a photograph link:";
	getline(cin, photograph);

	//int res = this->admService.addCoatService(size, colour, stoi(quantity), stod(price), photograph);
	//if (res == 1)
	//	cout << "\nCoat successfully added!\n";
	//else
	//	cout << "This coat already exists, if you want to add more just update it!";

	try {
		Coat coat{ size,colour, stoi(quantity),stod(price),photograph };
		this->admService.addCoatService(coat);
		cout << "\nCoat successfully added!\n";
	}
	catch (ValidationException& e)
	{
		cout << e.getMessage();
	}

}

void UI::admRemoveCoat()
{
	string pos;
	cout << "Enter the position of the coat you want to delete:";
	getline(cin, pos);
	try {
		this->admService.removeCoatService(stoi(pos));
		cout << "\nCoat successfully removed!\n";
	}
	catch (ValidationException& e) {
		cout << e.getMessage();
	}
}


void UI::admUpdateCoat()
{
	string pos, colour, size, photograph, quantity, price;

	cout << "Enter the position of the coat you want to update:";
	getline(cin, pos);
	cout << "\n Enter a colour:";
	getline(cin, colour);
	cout << "\n Enter a size:";
	getline(cin, size);
	cout << "\n Enter a quantity:";
	getline(cin, quantity);
	cout << "\n Enter a price:";
	getline(cin, price);
	cout << "\n Enter a photograph link:";
	getline(cin, photograph);

	try {
		this->admService.updateCoatService(stoi(pos), size, colour, stoi(quantity), stod(price), photograph);
		cout << "\nCoat successfully updated!\n";
	}
	catch (ValidationException& e) {
		cout << e.getMessage();
	}
}


void UI::admSeeCoats()
{
	vector<Coat> all_coats = this->admService.getCoatsService();
	/*for (int i = 0; i < all_coats.size(); i++) {
		Coat c = all_coats[i];
		cout << i << ".\t Size: " << c.getSize() << " # Colour: " << c.getColour() << " # Quantity: " << c.getQuantity() << " # Price:" << c.getPrice() << " # Photo:" << c.getPhotograph()<<"\n";
	}*/
	int i = 0;
	for_each(all_coats.begin(), all_coats.end(), [&i](Coat c) {cout << i << ".\t Colour: " << c.getColour() << " # Size: " << c.getSize() << " # Quantity: " << c.getQuantity() << " # Price:" << c.getPrice() << " # Photo:" << c.getPhotograph() << "\n"; i++; });
}

void UI::clSeeCoats()
{
	string size, command;
	cout << "\nEnter your size:";
	getline(cin, size);

	while (1) {

		vector<Coat> all_coats = this->clService->getCoatsWithSize(size);

		vector<Coat>::iterator it = all_coats.begin();
		while (it != all_coats.end()) {

			Coat c = *it;
			cout << "\t Colour: " << c.getColour() << " # Size: " << c.getSize() << " # Quantity: " << c.getQuantity() << " # Price:" << c.getPrice();
			string link = c.getPhotograph();
			ShellExecute(nullptr, nullptr, std::wstring(link.begin(), link.end()).c_str(), nullptr, nullptr, SW_SHOW);
			cout << "\nDo you wanna add it to your basket?(yes/no)\t press X to exit.\n";
			getline(cin, command);
			if (command == "X")
				return;
			if (command == "yes") {
				this->clService->addCoatService(c);
				cout << "Total Price:" << this->clService->getTotalPrice() << "\n";
			}
			else
				if (command != "no")
					cout << "\nInvalid command\n";

			it++;
		}
		if (command == "X")
			return;
	}

}

void UI::clSeeShoppingBasket()
{
	vector<Coat> all_coats = this->clService->getbasket();
	if (all_coats.size() == 0)
		cout << "\nNothing to see here yet! Go pick something nice!\n";
	else {
		int i = 0;
		for_each(all_coats.begin(), all_coats.end(), [&i](Coat c) {cout << i << ".\t Size: " << c.getSize() << " # Colour: " << c.getColour() << " # Quantity: " << c.getQuantity() << " # Price:" << c.getPrice() << " # Photo:" << c.getPhotograph() << "\n"; i++; });
	}

	cout << "Total price: " << this->clService->getTotalPrice();
}

void UI::clSeeBasketFile()
{
	this->clService->writeToFile();
}


void admMenu1() {
	cout << "\n1. Manage a coat\n"
		"2. Print all coats\n"
		"0. Exit\n";
}


void admMenu2() {
	cout << "\n1. Add a coat\n"
		"2. Remove a coat\n"
		"3. Update a coat\n";
}


void clMenu() {
	cout << "\n1. See coats\n"
		"2. See shopping basket\n"
		"3. See shopping basket file\n"
		"0. Exit\n";
}





void UI::updateData()
{
	ofstream fout(this->DataFile);
	if (!fout.is_open()) {
		return;
	}
	for (auto c : this->admService.getCoatsService())
		fout << c;
	fout.close();
}

void UI::start()
{
	cout << "Welcome to our store! \n";

	cout << "Who are you? A client or an administator?";
	string mode, command1, command2;
	getline(cin, mode);


	if (mode == "admin") { //the user is an admin
		while (true)
		{
			this->updateData();
			admMenu1();
			cout << "\nyour option:";
			getline(cin, command1);
			if (command1 == "0")
				break;
			else
				if (command1 == "1") {
					admMenu2();
					cout << "\nyour option:";
					getline(cin, command2);
					if (command2 == "1")
						admAddCoat();
					else if (command2 == "2")
						admRemoveCoat();
					else if (command2 == "3")
						admUpdateCoat();
					else cout << "Invalid command";
				}

				else
					if (command1 == "2")
						admSeeCoats();
					else
						cout << "Invalid command";
		}
	}
	else {		//the user is a client
		cout << "How do you want to see your basket? (CSV or HTML)";
		string typefile;
		getline(cin, typefile);
		if (typefile == "HTML") {
			HTMLClientService* clServ=new HTMLClientService{ this->clService->storeRepo,this->clService->basket,"Basket.html" };
			ClientService* cl{ clServ };
			this->clService = cl;

		}
		else {
			CSVClientService* clServ = new CSVClientService{ this->clService->storeRepo,this->clService->basket,"Basket.csv" };
			ClientService* cl{ clServ };
			this->clService = cl;

		}


		while (true) {
			clMenu();
			cout << "\nyour option:";
			getline(cin, command1);
			if (command1 == "0") {
				break;
			}
			else
				if (command1 == "1")
					clSeeCoats();
				else
					if (command1 == "2")
						clSeeShoppingBasket();
					else
						if (command1 == "3")
							clSeeBasketFile();
						else
						cout << "Invalid command";

		}
		

	}
	this->updateData();

	
}
