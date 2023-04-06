#pragma once
#include "Offer.h"
#include "DynamicArray.h"

typedef struct
{
	DynamicArray* Offers;
} OfferRepo;

/// <summary>
/// Creates a OfferRepo.
/// </summary>
OfferRepo* createRepo();

/// <summary>
/// Destroys a given Offer repository. The memory is freed.
/// </summary>
void destroyRepo(OfferRepo* v);

// Returns 0 - if the Offer was successfully added or -1 otherwise.
int addOffer(OfferRepo* repo, Offer* o);

int getRepoLength(OfferRepo* repo);

int deleteOffer(OfferRepo* repo, int index);


int updateOffer(OfferRepo* repo, int index, char* type, char* destination, char* date, int price);

Offer* findByDestinationAndDate(OfferRepo* repo, char* destination, char* date);

int getOfferPosition(OfferRepo* repo, Offer* offer);

Offer* getOfferOnPos(OfferRepo* v, int pos);

DynamicArray* searchByDestination(OfferRepo* v, char* string);

void sortOffersRepoByPrice(OfferRepo* repo);

void sortOffersRepoByDate(OfferRepo* repo);