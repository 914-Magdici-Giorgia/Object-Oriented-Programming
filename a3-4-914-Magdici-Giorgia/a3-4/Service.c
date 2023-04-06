#include "Service.h"
#include "Operation.h"
#include <stdlib.h>
#include <string.h>


Service* createService(OfferRepo* r)
{
	Service* s = (Service*)malloc(sizeof(Service));
	if (s == NULL)
		return NULL;
	s->repo = r;
	s->undoStack = createDynamicArray(0, (DestroyElementFunctionType)&destroyOperation);
	s->undoStack->length = 0;
	s->redoStack = createDynamicArray(0, (DestroyElementFunctionType)&destroyOperation);
	s->redoStack->length = 0;
	return s;
}

void destroyService(Service* s)
{
	if (s == NULL)
		return NULL;
	destroyRepo(s->repo);
	destroy(s->undoStack);
	destroy(s->redoStack);
	free(s);
}

int addOfferServ(Service* s, char* type, char* destination, char* date, double price)
{
	Offer* offer = createOffer(type, destination, date, price);

	int res = addOffer(s->repo, offer);

	if (res == 0) {
		destroyOffer(offer);
		return 0;
	}
	else
		if (res == 1) {
			Operation* operation = createOperation(ADD, offer);
			if (operation == NULL)
				return -1;
			add(s->undoStack, operation);

		}
	return 1;
}


int deleteOfferServ(Service* s, int index) {


	Offer* offer = getOfferOnPos(s->repo, index);
	Operation* operation = createOperation(DELETE, offer);
	if (operation == NULL)
		return -1;
	add(s->undoStack, operation);
	return deleteOffer(s->repo, index);

}

int updateOfferServ(Service* s, int index, char* type, char* destination, char* date, double price){
	Offer* offer = getOfferOnPos(s->repo, index);
    Operation * operation = createOperation(UPDATE, offer);
    if(operation ==NULL)
        return -1;
    add(s->undoStack, operation);
    return updateOffer(s->repo, index, type, destination, date, price);
}


int undo(Service* s) {
    /*
     * does the undo operation
     */
    if (s == NULL)
        return -1;

    int stackSize = getLength(s->undoStack);
    if (stackSize == 0)
        return 0;
    Operation* operation = get(s->undoStack, stackSize - 1);
    if (operation == NULL)
        return -1;
    Offer* offer = getOpObject(operation);
    if (offer == NULL)
        return -1;

    if (getOpType(operation) == ADD)
    {
        Operation* opRedo = createOperation(DELETE, offer);
        add(s->redoStack, opRedo);
        deleteOffer(s->repo, getOfferPosition(s->repo, offer));
    }
    else
        if (getOpType(operation) == DELETE) {
            Operation* opRedo = createOperation(ADD, copyOffer(offer));
            add(s->redoStack, opRedo);
            addOffer(s->repo, copyOffer(offer));
        }

        else
            if (getOpType(operation) == UPDATE) {
                Operation* opRedo = createOperation(UPDATE, offer);
                add(s->redoStack, opRedo);
                updateOffer(s->repo, getOfferPosition(s->repo, offer), getType(offer), getDestination(offer), getDate(offer), getPrice(offer));
            }

    delete(s->undoStack, stackSize - 1);
    return 1;
}

int redo(Service* s)
{
    /*
     * does the redo operation
     */
    if (s == NULL)
        return -1;

    int stackSize = getLength(s->redoStack);
    if (stackSize == 0)
        return 0;
    Operation* operation = get(s->redoStack, stackSize - 1);
    if (operation == NULL)
        return -1;
    Offer* offer = getOpObject(operation);
    if (offer == NULL)
        return -1;

    if (getOpType(operation) == ADD)
        deleteOffer(s->repo, getOfferPosition(s->repo, offer));
    else
        if (getOpType(operation) == DELETE)
            addOffer(s->repo, copyOffer(offer));
        else
            if (getOpType(operation) == UPDATE) {
                updateOffer(s->repo, getOfferPosition(s->repo, offer), getType(offer),
                    getDestination(offer), getDate(offer), getPrice(offer));
            }

    delete(s->redoStack, stackSize - 1);
    return 1;
}


OfferRepo* getRepo(Service* s)
{
	return s->repo;
}