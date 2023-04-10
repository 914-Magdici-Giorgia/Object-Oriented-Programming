#pragma once
#include <vector>
#include"Coat.h"
using namespace std;

class Repository {
protected:
	vector<Coat> coats;
public:
	Repository() {};

	//adds a coat in repo if it doesn't exist. Returns 1 if successfull, 0 if the coat existed already
	void addCoatRepo( Coat&);

	//deletes a coat from repo if id exists.Returns 1 if successfull, 0 if the coat did not exist in repo
	void deleteCoatRepo( int);

	//replaces a coat from repo with a new one. Returns 1 if successfull, 0 if the position ia not valid or the new coat already exists
	void updateCoatRepo(const Coat&, int);


	//returns the list of coats
	vector<Coat> getCoats();

	//returns the numer of elementsin repo
	int getSize();

	void modifyQuantity(Coat);
	
	//virtual void writeToFile() const;

private:

	//checks if a coat exists in repo
	int existingCoat(const Coat&);
};//keeep


//class CSVRepository:public Repository
//{
//private:
//	std::string namefile;
//public:
//	CSVRepository(std::string namef);
//	~CSVRepository();
//
//	void writeToFile() const override;
//
//};
//
//class HTMLRepository :public Repository
//{
//private:
//	std::string namefile;
//public:
//	HTMLRepository(std::string namef);
//	~HTMLRepository();
//
//	void writeToFile() const override;
//
//};
//
