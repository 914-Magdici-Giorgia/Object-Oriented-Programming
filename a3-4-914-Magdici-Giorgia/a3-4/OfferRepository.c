#include "OfferRepository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

OfferRepo* createRepo()
{
	OfferRepo* v = (OfferRepo*)malloc(sizeof(OfferRepo));
	if (v == NULL)
		return NULL;
	v->Offers = createDynamicArray(CAPACITY, &destroyOffer);

	return v;
}

void destroyRepo(OfferRepo* v)
{
	if (v == NULL)
		return;

	// destroy the dynamic array
	destroy(v->Offers);
	free(v);
}




int addOffer(OfferRepo* v, Offer* o)
{
	if (v == NULL || o == NULL)
		return 0;

	if (findByDestinationAndDate(v, o->destination, o->date) != NULL)
		return 0;

	add(v->Offers, o);

	return 1;
}


int deleteOffer(OfferRepo* repo, int index) {
	if (repo == NULL || index >=getRepoLength(repo)|| index<0) {
		return 0;
	}
	Offer* o = getOfferOnPos(repo, index);
	for (int i = 0; i < getRepoLength(repo); i++) {
		if (get(repo->Offers, i) == o) {
			delete(repo->Offers, i);
			return 1;
		}
	}

	return 0;
}


int updateOffer(OfferRepo* repo,int index, char* type, char* destination, char* date, int price) {

	if (repo == NULL || index<0 || index>=getRepoLength || type == NULL || destination == NULL || date == NULL) {
		return 0;
	}
	for (int i = 0; i < getLength(repo->Offers); i++) {
		if (i == index) {
			Offer* updatedOffer = get(repo->Offers, i);
			strcpy(updatedOffer->type, type);
			strcpy(updatedOffer->destination, destination);
			strcpy(updatedOffer->date, date);
			updatedOffer->price = price;
			return 1;
		}
	}
	
}


int getRepoLength(OfferRepo* v)
{
	if (v == NULL)
		return -1;

	return getLength(v->Offers);
}

Offer* getOfferOnPos(OfferRepo* v, int pos)
{
	if (v == NULL)
		return NULL;
	return get(v->Offers, pos);
}


int getOfferPosition(OfferRepo* repo, Offer* offer) {
	if (repo == NULL || offer == NULL) {
		return -1;
	}
	for (int i = 0; i <= getRepoLength(repo); i++) {
		Offer* o = get(repo->Offers, i);
		if (strcmp(getDestination(o), getDestination(offer)) == 0 && strcmp(getDate(o), getDate(offer)) == 0) {
			return i;
		}
	}
}



Offer* findByDestinationAndDate(OfferRepo * repo, char* destination, char* date) {
	if (repo == NULL || destination == NULL || date == NULL) {
		return NULL;
	}

	for (int i = 0; i < getLength(repo->Offers); i++) {
		Offer* o = get(repo->Offers, i);
		if (strcmp(getDestination(o), destination) == 0 && strcmp(getDate(o), date) == 0) {
			return o;
		}
	}

	return NULL;
}



DynamicArray* searchByDestination(OfferRepo* v, char* string) {

	DynamicArray* list = createDynamicArray(10, &destroyOffer);

	if (v == NULL || string == NULL) {
		return NULL;
	}
	for (int i = 0; i < getLength(v->Offers); i++) {
		Offer* o = get(v->Offers, i);
		if (strstr(getDestination(o), string) != NULL) {
			add(list, o);
		}
	}
	return list;

}


void sortOffersRepoByPrice(OfferRepo* repo) {
	for (int i = 0; i < getRepoLength(repo) - 1; i++) {
		for (int j = i + 1; j < getRepoLength(repo); j++) {
			Offer* aux1 = get(repo->Offers, i);
			Offer* aux2 = get(repo->Offers, j);
			if (aux1->price > aux2->price) {
				repo->Offers->elems[i] = aux2;
				repo->Offers->elems[j] = aux1;
			}
		}
	}
}


void sortOffersRepoByDate(OfferRepo* repo) {
	for (int i = 0; i < getRepoLength(repo) - 1; i++) {
		for (int j = i + 1; j < getRepoLength(repo); j++) {
			Offer* aux1 = get(repo->Offers, i);
			Offer* aux2 = get(repo->Offers, j);
			if (strcmp(aux1->date, aux2->date)>0) {
				repo->Offers->elems[i] = aux2;
				repo->Offers->elems[j] = aux1;
			}
		}
	}
}


// **************** Tests for add___delete___update ***************

//*****************************************************************
void initOfferRepoForTests(OfferRepo* repo)
{
	Offer* offer = createOffer("seaside", "Spain", "05/05/2022", 5000);
	addOffer(repo, offer);
}

void testAddFunction()
{
	OfferRepo* repo = createRepo();
	initOfferRepoForTests(repo);
	assert(getRepoLength(repo) == 1);

	Offer* offer = createOffer("mountain", "Sinaia", "2022/01/27", 2600);
	assert(addOffer(repo, offer) == 1);
	assert(getRepoLength(repo) == 2);

	assert(addOffer(repo, offer) == 0); // try to add same Offer

	destroyRepo(repo);
}

void testDeleteFunction()
{
	OfferRepo* repo = createRepo();
	initOfferRepoForTests(repo);
	assert(getRepoLength(repo) == 1);

	assert(deleteOffer(repo, 0) == 1);

	assert(getRepoLength(repo) == 0);
	assert(deleteOffer(repo, 0) == 0); //try to delete same Offer

	destroyRepo(repo);
}

void testUpdateFunction()
{
	OfferRepo* repo = createRepo();
	initOfferRepoForTests(repo);
	assert(getRepoLength(repo) == 1);

	updateOffer(repo, 0, "mountain", "Sinaia", "2022/01/27", 2600);
	Offer* OfferVer = (Offer*)get(repo->Offers, 0);
	assert(OfferVer->price == 2600);

	destroyRepo(repo);
}

void testsOfferRepo()
{	testAddFunction();
	testDeleteFunction();}













