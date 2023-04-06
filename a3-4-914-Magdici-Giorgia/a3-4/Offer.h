#pragma once

typedef struct
{
	char* type;
	char* destination;
	char* date;
	double price;
} Offer;

Offer* createOffer(char* type, char* destination, char* date, double price);
void destroyOffer(Offer* o); // the memory is freed



char* getType(Offer* o);
char* getDestination(Offer* o);
char* getDate(Offer* o);
double getPrice(Offer* o);

Offer* copyOffer(Offer* o);

void toString(Offer* o, char str[]);