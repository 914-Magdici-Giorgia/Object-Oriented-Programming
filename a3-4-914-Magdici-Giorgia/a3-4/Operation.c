

#include "Operation.h"
#include "Offer.h"
#include <stdlib.h>

Operation* createOperation(opType type, Offer* offer) {
    /*
     * creates an operation
     */
    Operation* op = malloc(sizeof(Operation));
    op->type = type;

    Offer* copyOfOffer = copyOffer(offer);
    op->offer = copyOfOffer;

    return op;
}

void destroyOperation(Operation* o) {
    /*
     * deallocates the memory that was allocated for the operation
     */
    if (o == NULL)
        return;
    destroyOffer(o->offer);
    free(o);
}

opType getOpType(Operation* o) {
    /*
     * returns the operation type
     */
    if (o == NULL)
        return -1;
    return o->type;
}

Offer* getOpObject(Operation* o) {
    /*
     * returns the offer instance that is operated on
     */
    if (o == NULL)
        return NULL;
    return o->offer;
}