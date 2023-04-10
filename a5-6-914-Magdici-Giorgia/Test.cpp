#include "Test.h"
#include "Coat.h"
#include <vector>
#include "Repository.h"
#include <assert.h>
#include"AdministratorService.h"
#include"ClientService.h"
using namespace std;

void Test::testAll()
{
	testCoat();
	testDynamicVector();
	testRepository();
	testAdministratorService();
	testClientService();


}

void Test::testCoat()
{
	Coat c{ "M","black",120,599.99,"www.store.com/coats/black/1234" };
	assert(c.getColour() == "black");
	assert(c.getSize() == "M");
	assert(c.getPrice() == 599.99);
	assert(c.getQuantity() == 120);
	assert(c.getPhotograph() == "www.store.com/coats/black/1234");

	Coat c2{ "M","black",120,599.99,"www.store.com/coats/black/1234" };
	assert(c == c2);
	Coat c3 = c2;
	assert(c2 == c3);

	c.setColour("white");
	assert(c.getColour() == "white");

	c.setPrice(200);
	assert(c.getPrice() == 200);

	c.setQuantity(30);
	assert(c.getQuantity() == 30);

	c.setSize("S");
	assert(c.getSize() == "S");

	c.setPhotograph("www.photo.com");
	assert(c.getPhotograph() == "www.photo.com");


}


void Test::testDynamicVector()
{
    DynamicVector<int> v1{ 2 };
    v1.add(10);
    v1.add(20);

    DynamicVector<int> v4{ 2 };
    v4.add(10);
    v4.add(20);
    assert(v1==v4);

    assert(v1.getSize() == 2);
    assert(v1[1] == 20);
    v1[1] = 25;
    assert(v1[1] == 25);
    v1.add(30);
    assert(v1.getSize() == 3);

    DynamicVector<int> v2{ v1 };
    assert(v2.getSize() == 3);

    DynamicVector<int> v3;
    v3 = v1;
    assert(v3[0] == 10);
    // test iterator
    DynamicVector<int>::iterator it = v1.begin();
    assert(it==v1.begin());
    assert(*it == 10);
    assert(it != v1.end());
    it++;
    assert(*it == 25);

    int i = 0;
    for (auto x : v1)
        i++;
    assert(i == 3);


}



void Test::testRepository()
{
	Coat c1{ "M","black",120,599.99,"www.store.com/coats/black/1234" };
	Coat c2{ "M","white",50,459.99,"www.store.com/coats/white/1344" };
	Coat c3{ "S","pink",30,879.99,"www.store.com/coats/pink/3454" };
	Coat c4{ "S","brown",100,449.99,"www.store.com/coats/brown/5345" };
	Coat c5{ "L","beige",150,799.99,"www.store.com/coats/beige/7546" };

	Repository repo = Repository();
	repo.addCoatRepo(c1);
	repo.addCoatRepo(c2);
	repo.addCoatRepo(c3);
	repo.addCoatRepo(c4);


	Coat c4again = c4;
	Coat c5again = c5;
	assert(repo.addCoatRepo(c4again) == 0);
	assert(repo.getSize() == 4);

	assert(repo.addCoatRepo(c5) == 1);
	assert(repo.getSize() == 5);

	assert(repo.deleteCoatRepo(c4) == 1);
	assert(repo.getSize() == 4);

	assert(repo.deleteCoatRepo(c4) == 0);
	assert(repo.getSize() == 4);

	assert(repo.updateCoatRepo(c5again, 1) == 0);
	assert(repo.updateCoatRepo(c4, 4) == 0);
	assert(repo.updateCoatRepo(c4, 2) == 1);

	assert(repo.getCoats()[2] == c4);
}

void Test::testAdministratorService()
{
	Repository repo;
	AdministratorService admin{ repo };

	int res1 = admin.addCoatService("M", "black", 120, 599.99, "https://static.zara.net/photos///2022/V/0/1/p/2219/747/800/2/w/897/2219747800_1_1_1.jpg?ts=1641913547609");
	int res2 = admin.addCoatService("M","white",50,459.99,"https://static.zara.net/photos///2022/V/0/1/p/2739/474/712/2/w/897/2739474712_2_12_1.jpg?ts=1645639424249" );
	int res3 = admin.addCoatService("S","pink",30,879.99,"https://static.zara.net/photos///2022/V/0/1/p/2818/795/630/2/w/897/2818795630_1_1_1.jpg?ts=1648469538335" );
	int res4 = admin.addCoatService("S","brown",100,449.99,"https://static.zara.net/photos///2022/V/0/1/p/4043/054/701/2/w/563/4043054701_1_1_1.jpg?ts=1646667521520" );

	assert(res1 == 1);
	assert(res2 == 1);
	assert(res3 == 1);
	assert(res4 == 1);

	int res5 = admin.addCoatService("S", "brown", 100, 449.99, "https://static.zara.net/photos///2022/V/0/1/p/4043/054/701/2/w/563/4043054701_1_1_1.jpg?ts=1646667521520");
	assert(res5 == 0);

	int res6 = admin.removeCoatService(3);
	assert(res6 == 1);
	int res9 = admin.removeCoatService(10);
	assert(res9 == 0);

	int res7 = admin.updateCoatService(2, "L", "blue", 150, 500.99, "https://static.zara.net/photos///2022/V/0/1/p/2217/747/436/2/w/897/2217747436_1_1_1.jpg?ts=1641912302009");
	assert (res7 == 1);

	int res8 = admin.updateCoatService(2, "M", "black", 120, 599.99, "https://static.zara.net/photos///2022/V/0/1/p/2219/747/800/2/w/897/2219747800_1_1_1.jpg?ts=1641913547609");
	assert(res8 == 0);



}


void Test::testClientService()
{
	Coat c1{ "M","black",120,600,"www.store.com/coats/black/1234" };
	Coat c2{ "M","white",50,459.99,"www.store.com/coats/white/1344" };
	Coat c3{ "S","pink",30,879.99,"www.store.com/coats/pink/3454" };
	Coat c4{ "S","brown",100,400,"www.store.com/coats/brown/5345" };
	Coat c5{ "L","beige",150,799.99,"www.store.com/coats/beige/7546" };

	Repository repo ;
	repo.addCoatRepo(c1);
	repo.addCoatRepo(c2);
	repo.addCoatRepo(c3);
	repo.addCoatRepo(c4);

	DynamicVector<Coat> b;
	ClientService client{ repo,b };

	client.addCoatService(c1);
	client.addCoatService(c4);
	assert(client.getTotalPrice() == 1000);


	DynamicVector<Coat> TestB;

	TestB.add(c1);
	TestB.add(c4);

	assert(TestB == client.getbasket());


	DynamicVector<Coat> Test2;


	Test2.add(c3);
	Test2.add(c4);
	assert(client.getCoatsWithSize("S") == Test2);

}

