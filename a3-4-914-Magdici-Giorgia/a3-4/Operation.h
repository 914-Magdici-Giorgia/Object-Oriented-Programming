
#pragma once
#include "Offer.h"

typedef enum {
    ADD,
    DELETE,
    UPDATE
}opType;

typedef struct {
    opType type;
    Offer* offer;
}Operation;

Operation* createOperation(opType type, Offer* offer);
void destroyOperation(Operation* o);

opType getOpType(Operation* o);
Offer* getOpObject(Operation* o);