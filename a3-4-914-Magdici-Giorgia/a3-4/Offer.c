#include "Offer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Offer* createOffer(char* type, char* destination, char* date, double price)
{
	Offer* o = malloc(sizeof(Offer));
	o->type = malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(o->type, type);
	o->destination = malloc(sizeof(char) * (strlen(destination) + 1));
	strcpy(o->destination, destination);
	o->date = malloc(sizeof(char) * (strlen(date) + 1));
	strcpy(o->date, date);

	o->price = price;

	return o;
}

void destroyOffer(Offer* o)
{
	if (o == NULL)
		return;

	// free the memory which was allocated for the component fields
	free(o->type);
	free(o->destination);
	free(o->date);

	// free the memory which was allocated for the Offer structure
	free(o);
}


char* getType(Offer* o)
{
	if (o == NULL)
		return NULL;
	return o->type;
}



char* getDestination(Offer* o)
{
	if (o == NULL)
		return NULL;
	return o->destination;
}


char* getDate(Offer* o)
{
	if (o == NULL)
		return NULL;
	return o->date;
}


double getPrice(Offer* o)
{
	if (o == NULL)
		return -1;
	return o->price;
}

void toString(Offer* o, char str[])
{
	if (o == NULL)
		return;
	sprintf(str, "The offer is a %s holiday in %s. Its departure date is on %s and its price is %.2lf .", o->type, o->destination, o->date, o->price);
}

Offer* copyOffer(Offer* o) {
	if (o == NULL)
		return NULL;
	return createOffer(o->type, o->destination, o->date, o->price);
}