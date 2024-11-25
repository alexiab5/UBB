#include "operations_stack.h"


Operation* createOperation(Material* p, char* operationType)
{
    Operation* o = malloc(sizeof(Operation));
    if (o == NULL)
        return NULL;
    o->material = copyMaterial(p);

    if (operationType != NULL)
    {
        o->operationType = malloc(sizeof(char) * (strlen(operationType) + 1));
        if (o->operationType == NULL)
        {
            free(o);
            return NULL;
        }
        strcpy(o->operationType, operationType);
    }
    else
        o->operationType = NULL;

    return o;
}

void destroyOperation(Operation* o)
{
    if (o == NULL)
        return;

    destroyMaterial(o->material);
    // then the operationType
    free(o->operationType);
    // then free the operation
    free(o);
}

Operation* copyOperation(Operation* o)
{
    if (o == NULL)
        return NULL;
    Operation* copy = createOperation(getMaterial(o), getOperationType(o));
    return copy;
}

char* getOperationType(Operation* o)
{
    return o->operationType;
}

Material* getMaterial(Operation* o)
{
    return o->material;
}

// ---------------------------------------------------------------

OperationsStack* createStack()
{
    OperationsStack* s = malloc(sizeof(OperationsStack));
    if (s == NULL)
        return NULL;
    s->stack = createDynamicArray(CAPACITY, (DestroyFunctionType) &destroyOperation);
    if (s->stack == NULL)
    {
        free(s);
        return NULL;
    }

    return s;
}

void destroyStack(OperationsStack* s)
{
    if (s == NULL)
        return;

    // first deallocate the memory for the dynamic array
    destroyDynamicArray(s->stack);

    // then free the stack
    free(s);
}

void push(OperationsStack* s, Operation* o)
{
    if (s == NULL || o == NULL)
        return;
    addElement(s->stack, o);
}

Operation* pop(OperationsStack* s)
{
    if (s == NULL)
        return NULL;
    int lastPos = getLength(s->stack) - 1;
    Operation* o = (Operation*)get(s->stack, lastPos); // must cast it to Operation*, as it is a void*
    // make a copy to use it for redo as well
    Operation* lastOp = copyOperation(o);
    deleteElementAtPosition(s->stack, lastPos);
    return lastOp;
}

int isEmpty(OperationsStack* s)
{
    if (s == NULL)
        return 1;
    return (getLength(s->stack) == 0);
}
