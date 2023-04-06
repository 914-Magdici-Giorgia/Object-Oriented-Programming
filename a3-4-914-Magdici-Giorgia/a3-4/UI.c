#include "UI.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

UI* createUI(Service* s)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	if (ui == NULL)
		return NULL;
	ui->serv = s;
	return ui;
}

void destroyUI(UI* ui)
{
	if (ui == NULL)
		return;
	// first destroy the Service
	destroyService(ui->serv);
	// free the UI memory
	free(ui);
}

/*
	Prints the available menu for the problem
	Input: -
	Output: the menu is printed at the console
*/
void printMenu()
{
	printf("\n**********************************************************\n");
	printf("1 - add an Offer.\n");
	printf("2 - remove an Offer.\n");
	printf("3 - update an offer\n");
	printf("4 - search in destinations.\n");
	printf("5 - search for offers by type, after a given date.\n");
	printf("6 - undo the last operation.\n");
	printf("7 - redo the last operation.\n");
	printf("0 - to exit.\n");
	printf("\n**********************************************************\n");
}

/*
	Verifies if the given command is valid (is either 1, 2, 3or 0)
	Input: command - integer
	Output: 1 - if the command is valid
	0 - otherwise
*/
int validCommand(int command)
{
	if (command >= 0 && command <= 7)
		return 1;
	return 0;
}

/*
	Reads an integer number from the keyboard. Asks for number while read errors encoutered.
	Input: the message to be displayed when asking the user for input.
	Returns the number.
*/
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

/*
	Reads a string with spaces from the standard input.
	Input:	message - string, message to be shown to the user.
			maxStrSize - the maximum size for the string to be read
	Output: the string that was read.
*/
void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
	printf(message);
	fgets(str, maxStrSize, stdin);
	// the newline is also read so we must eliminate it from the string
	size_t size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

int addOfferUI(UI* ui)
{
	// read the Offer's data
	char type[50], destination[50], date[50];
	double price;

	fgetc(stdin); // read the newline, to prevent it from going further to fgets
	readStringWithSpaces("Please input the type: ", 50, type);
	readStringWithSpaces("Please input the destination: ", 50, destination);
	readStringWithSpaces("Please input the date: ", 50, date);
	printf("Please input the price: ");
	scanf("%lf", &price);

	return addOfferServ(ui->serv, type, destination, date, price);
}


int deleteOfferUI(UI* ui)
{
	// read the Offer's data
	int index;

	index = readIntegerNumber("Please input the number of the offer : ");


	return deleteOfferServ(ui->serv, index);
}

int updateOfferUI(UI* ui)
{
	// read the Offer's data
	int index;
	char updatedType[50], updatedDestination[50], updatedDate[50];
	double updatedPrice;


	index = readIntegerNumber("Please input the numebr of the offer: ");
	

	fgetc(stdin);
	readStringWithSpaces("Please input the updated type: ", 50, updatedType);
	readStringWithSpaces("Please input the updated destination: ", 50, updatedDestination);
	readStringWithSpaces("Please input the updated date: ", 50, updatedDate);
	updatedPrice = readIntegerNumber("Please input the updated price: ");
	return updateOfferServ(ui->serv,index, updatedType, updatedDestination, updatedDate, updatedPrice);
}


void displayList(DynamicArray* list)
{
	if (list == NULL)
		return;

	int length = getLength(list);

	for (int i = 0; i < length; i++)
	{
		Offer* Offer = get(list, i);
		char OfferString[200];
		toString(Offer, OfferString);
		printf("%s\n", OfferString);
	}
}
void searchByDestinationUI(UI* ui) {

	if (ui == NULL)
		return;
	OfferRepo* repository = getRepo(ui->serv);
	if (repository == NULL)
		return;

	char string[50];
	fgetc(stdin);
	readStringWithSpaces("What are you searching for?", 50, string);

	sortOffersRepoByPrice(ui->serv->repo);
	for (int i = 0; i < getRepoLength(repository); ++i)
	{
		Offer* offer = getOfferOnPos(repository, i);
		if ((int)string[0] == 0 || strstr(offer->destination, string) != 0)
		{
			char offerStr[200];
			toString(offer, offerStr);
			printf("\t\t %d )", i);
			printf("%s\n", offerStr);
		}
	}


}



void listSortedOffersByDate(UI* ui)
{
	if (ui == NULL)
		return;

	OfferRepo* repository = getRepo(ui->serv);
	if (repository == NULL)
		return;

	char type[50],date[50];
	fgetc(stdin);
	readStringWithSpaces("Please input the  type: ", 50, type);

	readStringWithSpaces("after which date? ", 50, date);

	sortOffersRepoByDate(ui->serv->repo);

	for (int i = 0; i < getRepoLength(repository); ++i)
	{
		Offer* offer = getOfferOnPos(repository, i);
		if (strstr(offer->type, type) != 0 && strcmp(offer->date,date)>=0)
		{
			char offerStr[200];
			toString(offer, offerStr);
			printf("\t\t %d )", i);
			printf("%s\n", offerStr);
		}
	}

}


int undoUI(UI* ui)
{
	return undo(ui->serv);
}
int redoUI(UI* ui)
{
	return redo(ui->serv);
}




void startUI(UI* ui)
{

	while (1)
	{
		printMenu();

		int command = readIntegerNumber("Input command: ");

		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
		{
			break;
		}

		switch (command)
		{
		case 1:
		{
			int result = addOfferUI(ui);

			if (result == 1)
				printf("Offer successfully added.\n");
			else
				printf("Error! Offer could not be added, as there is another offer with the same destination and date!\n");
			break;
		}

		case 2:
		{
			int result = deleteOfferUI(ui);
			if (result == 1)
				printf("Offer successfully deleted.\n");
			else
				printf("Error! Offer could not be deleted, as there doesn't exist an offer on this position!\n");
			break;

		}

		case 3:
		{
			int result = updateOfferUI(ui);
			if (result == 1)
				printf("Offer successfully updated.\n");
			else
				printf("Error! Offer could not be updated, as there doesn't exist an offer on this position!\n");
			break;

		}

		case 4:
		{
			searchByDestinationUI(ui);
			break;
		}

		case 5:
		{
			listSortedOffersByDate(ui);
			break;
		}
		case 6:
		{
			int res = undoUI(ui);
			if (res == 1)
				printf("\nundo was successful\n");
			else
				if (res == 0)
					printf("you can't perform undo anymore");
				else
					printf("error");
			break;
		}
		case 7:
		{
			int res1 = redoUI(ui);
			if (res1 == 1)
				printf("\nredo was successful\n");
			else
				if (res1 == 0)
					printf("you can't perform redo anymore");
				else
					printf("error");
			break;
		}
		default:
		    break;
		}
	}
	exit(0);
}