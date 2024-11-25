#pragma once
#include "domain.h"
#include "dynamic_array.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct
{
    Material* material;
    char* operationType;
} Operation;

Operation* createOperation(Material* p, char* operationType);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* o);
char* getOperationType(Operation* o);
Material* getMaterial(Operation* o);

// ---------------------------------------------------------------
typedef struct
{
    DynamicArray* stack;
} OperationsStack;

OperationsStack* createStack();
void destroyStack(OperationsStack* s);
void push(OperationsStack* s, Operation* o);
Operation* pop(OperationsStack* s);
int isEmpty(OperationsStack* s);
