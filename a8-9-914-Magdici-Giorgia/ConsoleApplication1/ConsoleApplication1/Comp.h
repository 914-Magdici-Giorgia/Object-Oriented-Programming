#pragma once
#include "Coat.h"
#include <vector>
#include <algorithm>
#include <assert.h>

template<typename T>
class Comparator {
public:
	virtual bool compare(T a, T b) = 0;
};

class ComparatorAscendingByPrice : public Comparator<Coat> {
	bool compare(Coat a, Coat b) override;
};

class ComparatorDescendingByQuantity: public Comparator<Coat> {
	bool compare(Coat a, Coat b) override;
};

template<typename T>
inline void genericSort(std::vector<T>& elems, Comparator<T>* comp) {
	for (int i = 0; i < elems.size() - 1; i++) {
		for (int j = i + 1; j < elems.size(); j++) {
			if (!comp->compare(elems[i], elems[j])) {
				std::swap(elems[i], elems[j]);
			}
		}
	}
}

void testSort();