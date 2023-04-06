#pragma once
#include "OfferRepository.h"
#include "DynamicArray.h"

typedef struct
{
	OfferRepo* repo;
	DynamicArray* undoStack;
	DynamicArray* redoStack;

} Service;

Service* createService(OfferRepo* r);
void destroyService(Service* s);

/// <summary>
/// Adds a Offer to the repository of Offers.
/// </summary>
/// <param name="s">Pointer to theService.</param>
/// <param name = "name">A string, the name of the Offer.</param>
/// <param name = "type">A string, the Offer's type.</param>
/// <param name = "distanceFromEarth">Double, the distance from the Offer to Earth, in light years.</param>
/// <returns>1 - if the Offer was sucessfully added; 0 - if the Offer could not be added, as another Offer with the same symbol already exists.</returns>
int addOfferServ(Service* s, char* type, char* destination, char* date, double price);

OfferRepo* getRepo(Service* s);

int deleteOfferServ(Service* s, int index);

int updateOfferServ(Service* s,int index, char* type, char* destination, char* date, double price);
int undo(Service* s);
int redo(Service* s);


