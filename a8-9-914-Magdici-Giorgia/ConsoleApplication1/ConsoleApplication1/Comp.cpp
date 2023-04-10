#include "Comp.h"

bool ComparatorAscendingByPrice::compare(Coat a, Coat b) {
	return (a.getPrice() <= b.getPrice());
}

bool ComparatorDescendingByQuantity::compare(Coat a, Coat b) {
	return (a.getQuantity() >= b.getQuantity());
}

void testSort() {
	std::vector<Coat> elems;

	Coat c1{ "M","black",1,599.99,"https://static.zara.net/photos///2022/V/0/1/p/2219/747/800/2/w/897/2219747800_1_1_1.jpg?ts=1641913547609" };
	Coat c2{ "M","white",5,559.99,"https://static.zara.net/photos///2022/V/0/1/p/2739/474/712/2/w/897/2739474712_2_12_1.jpg?ts=1645639424249" };
	Coat c3{ "S","pink",30,479.99,"https://static.zara.net/photos///2022/V/0/1/p/2818/795/630/2/w/897/2818795630_1_1_1.jpg?ts=1648469538335" };
	Coat c4{ "S","brown",100,449.99,"https://static.zara.net/photos///2022/V/0/1/p/4043/054/701/2/w/563/4043054701_1_1_1.jpg?ts=1646667521520" };
	Coat c5{ "L","beige",150,399.99,"https://static.zara.net/photos///2022/V/0/1/p/2719/696/706/2/w/897/2719696706_1_1_1.jpg?ts=1646924764825" };
	Coat c6{ "L","beige",250,349.99,"https://static.zara.net/photos///2022/V/0/1/p/2710/583/742/2/w/897/2710583742_1_1_1.jpg?ts=1645707622483" };
	Coat c7{ "L","purple",350,329.99,"https://static.zara.net/photos///2022/V/0/1/p/2581/747/655/2/w/897/2581747655_1_1_1.jpg?ts=1641912307743" };
	Coat c8{ "L","butter",450,299.99,"https://static.zara.net/photos///2022/V/0/1/p/2049/449/712/2/w/897/2049449712_1_1_1.jpg?ts=1641899409690" };
	Coat c9{ "L","green",550,259.99,"https://static.zara.net/photos///2022/V/0/1/p/2867/154/063/2/w/897/2867154063_1_1_1.jpg?ts=1646322013836" };
	Coat c10{ "L","blue",650,200.99,"https://static.zara.net/photos///2022/V/0/1/p/2217/747/436/2/w/897/2217747436_1_1_1.jpg?ts=1641912302009" };


	elems.push_back(c1); 
	elems.push_back(c2); 
	elems.push_back(c3);
	elems.push_back(c4);
	elems.push_back(c5);
	elems.push_back(c6);
	elems.push_back(c7);
	elems.push_back(c8);
	elems.push_back(c9);
	elems.push_back(c10);


	for (int i = 0; i < elems.size() - 1; i++) {
		assert(elems[i].getPrice() > elems[i+1].getPrice());
	}

	for (int i = 0; i < elems.size() - 1; i++) {
			assert(elems[i].getQuantity() < elems[i+1].getQuantity());
	}

	ComparatorAscendingByPrice* comp1 = new ComparatorAscendingByPrice;
	ComparatorDescendingByQuantity* comp2 = new ComparatorDescendingByQuantity;

	genericSort(elems, comp1);
	for (int i = 0; i < elems.size() - 1; i++) {
		for (int j = i + 1; j < elems.size(); j++) {
			assert(elems[i].getPrice() <= elems[j].getPrice());
		}
	}

	genericSort(elems, comp2);
	for (int i = 0; i < elems.size() - 1; i++) {
		for (int j = i + 1; j < elems.size(); j++) {
			assert(elems[i].getQuantity() >= elems[j].getQuantity());
		}
	}

	delete comp1;
	delete comp2;
}