#pragma once
#include <string>

class Coat {
private:
	int quantity;
	double price;
	std::string size;
	std::string colour;
	std::string photograph;

public:
	Coat();
	Coat(const std::string& size, const std::string& colour, const int& quantity, const double& price, const std::string& photograph);
	Coat(const Coat&);

	~Coat();

	double getPrice() const;
	int getQuantity() const;
	std::string getSize() const;
	std::string getColour() const;
	std::string getPhotograph() const;



	void setPrice(double price);
	void setQuantity(int quantity);
	void setColour(std::string colour);
	void setSize(std::string size);
	void setPhotograph(std::string photograph);

	Coat& operator=(const Coat& new_coat);
	bool operator==(const Coat& other_coat);
	bool operator!=(const Coat& other_coat);

	friend std::istream& operator>>(std::istream& is, Coat& c);
	friend std::ostream& operator<<(std::ostream& os, const Coat& c);

};//keeep