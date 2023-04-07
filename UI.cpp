#include "UI.h"
#include<iostream>
#include <windows.h>
#include <shellapi.h>
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

	int res = this->admService.addCoatService(size, colour, stoi(quantity), stod(price), photograph);
	if (res == 1)
		cout << "\nCoat successfully added!\n";
	else
		cout << "This coat already exists, if you want to add more just update it!";

}

void UI::admRemoveCoat()
{
	string pos;
	cout << "Enter the position of the coat you want to delete:";
	getline(cin, pos);
	int res = this->admService.removeCoatService(stoi(pos));

	if (res == 1)
		cout << "\nCoat successfully removed!\n";
	else
		cout << "This coat doesn't exist!";
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


	int res = this->admService.updateCoatService(stoi(pos), size, colour, stoi(quantity), stod(price), photograph);
	if (res == 1)
		cout << "\nCoat successfully updated!\n";
	else
		cout << "Something went wrong!";
}


void UI::admSeeCoats()
{
	DynamicVector<Coat> all_coats = this->admService.getCoatsService();
	for (int i = 0; i < all_coats.getSize(); i++) {
		Coat c = all_coats[i];
		cout << i << ".\t Size: " << c.getSize() << " # Colour: " << c.getColour() << " # Quantity: " << c.getQuantity() << " # Price:" << c.getPrice() << " # Photo:" << c.getPhotograph() << "\n";
	}
}

void UI::clSeeCoats()
{
	string size, command;
	cout << "\nEnter your size:";
	getline(cin, size);
	DynamicVector<Coat> all_coats = this->clService.getCoatsWithSize(size);

	DynamicVector<Coat>::iterator it = all_coats.begin();
	while (it != all_coats.end()) {

		Coat c = *it;
		cout << "\t Size: " << c.getSize() << " # Colour: " << c.getColour() << " # Quantity: " << c.getQuantity() << " # Price:" << c.getPrice();
		string link = c.getPhotograph();
		ShellExecute(nullptr, nullptr, std::wstring(link.begin(), link.end()).c_str(), nullptr, nullptr, SW_SHOW);
		cout << "\nDo you wanna add it to your basket?(yes/no)\t press X to exit.\n";
		getline(cin, command);
		if (command == "X")
			return;
		if (command == "yes") {
			this->clService.addCoatService(c);
			cout << "Total Price:" << this->clService.getTotalPrice() << "\n";
		}
		else
			if (command != "no")
				cout << "\nInvalid command\n";

		it++;
		if (it == all_coats.end())
			it = all_coats.begin();
	}


}

void UI::clSeeShoppingBasket()
{
	DynamicVector<Coat> all_coats = this->clService.getbasket();
	if (all_coats.getSize() == 0)
		cout << "\nNothing to see here yet! Go pick something nice!\n";
	else
		for (int i = 0; i < all_coats.getSize(); i++) {
			Coat c = all_coats[i];
			cout << i << ".\t Size: " << c.getSize() << " # Colour: " << c.getColour() << " # Quantity: " << c.getQuantity() << " # Price:" << c.getPrice() << " # Photo:" << c.getPhotograph() << "\n";
		}

	cout << "Total price: " << this->clService.getTotalPrice();
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
		"0. Exit\n";
}



void UI::start()
{
	cout << "Welcome to our store! \n";

	cout << "Who are you? A client or an administator?";
	string mode, command1, command2;
	getline(cin, mode);

	if (mode == "admin") {
		while (true)
		{
			admMenu1();
			cout << "\nyour option:";
			getline(cin, command1);
			if (command1 == "0")
				return;
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
	else
		while (true) {
			clMenu();
			cout << "\nyour option:";
			getline(cin, command1);
			if (command1 == "0")
				return;
			else
				if (command1 == "1")
					clSeeCoats();
				else
					if (command1 == "2")
						clSeeShoppingBasket();
					else
						cout << "Invalid command";

		}
}