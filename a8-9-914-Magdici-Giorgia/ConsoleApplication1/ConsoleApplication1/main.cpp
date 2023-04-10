#include<iostream>
#include "Comp.h"
#include"Coat.h"
#include"Test.h"
#include"Repository.h"
#include"AdministratorService.h"
#include"UI.h"


int main() {
	/*Test t;
	t.testAll();*/


	Repository repo;

	/*Coat c1{ "M","black",120,599.99,"https://static.zara.net/photos///2022/V/0/1/p/2219/747/800/2/w/897/2219747800_1_1_1.jpg?ts=1641913547609" };
	Coat c2{ "M","white",50,459.99,"https://static.zara.net/photos///2022/V/0/1/p/2739/474/712/2/w/897/2739474712_2_12_1.jpg?ts=1645639424249" };
	Coat c3{ "S","pink",30,879.99,"https://static.zara.net/photos///2022/V/0/1/p/2818/795/630/2/w/897/2818795630_1_1_1.jpg?ts=1648469538335" };
	Coat c4{ "S","brown",100,449.99,"https://static.zara.net/photos///2022/V/0/1/p/4043/054/701/2/w/563/4043054701_1_1_1.jpg?ts=1646667521520" };
	Coat c5{ "L","beige",150,799.99,"https://static.zara.net/photos///2022/V/0/1/p/2719/696/706/2/w/897/2719696706_1_1_1.jpg?ts=1646924764825" };
	Coat c6{ "L","beige",150,349.99,"https://static.zara.net/photos///2022/V/0/1/p/2710/583/742/2/w/897/2710583742_1_1_1.jpg?ts=1645707622483" };
	Coat c7{ "L","purple",150,129.99,"https://static.zara.net/photos///2022/V/0/1/p/2581/747/655/2/w/897/2581747655_1_1_1.jpg?ts=1641912307743" };
	Coat c8{ "L","butter",150,999.99,"https://static.zara.net/photos///2022/V/0/1/p/2049/449/712/2/w/897/2049449712_1_1_1.jpg?ts=1641899409690" };
	Coat c9{ "L","green",150,459.99,"https://static.zara.net/photos///2022/V/0/1/p/2867/154/063/2/w/897/2867154063_1_1_1.jpg?ts=1646322013836" };
	Coat c10{ "L","blue",150,500.99,"https://static.zara.net/photos///2022/V/0/1/p/2217/747/436/2/w/897/2217747436_1_1_1.jpg?ts=1641912302009" };




	repo.addCoatRepo(c1);
	repo.addCoatRepo(c2);
	repo.addCoatRepo(c3);
	repo.addCoatRepo(c4);
	repo.addCoatRepo(c5);
	repo.addCoatRepo(c6);
	repo.addCoatRepo(c7);
	repo.addCoatRepo(c8);
	repo.addCoatRepo(c9);
	repo.addCoatRepo(c10);




	ofstream f("Coats.txt");
	for (auto c : repo.getCoats()) {
		f << c;
	}

	f.close();*/
	testSort();
	vector<Coat> basket;
	AdministratorService admin{ repo };
	
	ifstream fin("Coats.txt");

	Coat c{};
	while (fin >> c) {
		admin.addCoatService(c);
	}
	fin.close();


	ClientService* client=new ClientService{ admin.getRepo(),basket,};
	UI ui{ admin,client,"Coats.txt"};
	ui.start();

	_CrtDumpMemoryLeaks();


	return 0;
}

