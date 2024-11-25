#include "dynamic_array.h"
#include "assert.h"

DynamicArray* createDynamicArray(int capacity, DestroyFunctionType destroyFct)
{
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (arr == NULL)
        return NULL;

    arr->capacity = capacity;
    arr->size = 0;

    arr->elems = (TElem*)malloc(capacity * sizeof(TElem**));
    if (arr == NULL)
        return NULL;
    arr->destroyFct = destroyFct;

    return arr;
}

bool addElement(DynamicArray* array, TElem* element)
{
    if (array == NULL)
        return 1;
    if (array->elems == NULL)
        return 1;
    if (array->capacity == array->size) {
        bool resized;
        resized = resize(array);
        if (resized == 1)
            return 1;
    }
    array->elems[array->size] = element;
    array->size++;
    return 0;
}

bool deleteElementAtPosition(DynamicArray* array, int position)
{
    if(position < 0 || position >= array->size)
        return 1;
    array->destroyFct(array->elems[position]);
    for (int i = position; i < array->size - 1; i++)
        array->elems[i] = array->elems[i + 1];
    array->size--;
    return 0;
}

bool resize(DynamicArray* array)
{
    if (array == NULL)
        return 1;

    int* temp = realloc(array->elems, 2 * array->capacity * sizeof(array->elems));
    if (temp == NULL)
        return 1;

    array->capacity = array->capacity * 2;
    array->elems = temp;
    return 0;
}

void destroyDynamicArray(DynamicArray* array)
{
    if (array == NULL)
        return;

    for (int i = 0; i < array->size; i++)
        array->destroyFct(array->elems[i]);

    free(array->elems);
    array->elems = NULL;
    free(array);
}

TElem* get(DynamicArray* arr, int pos)
{
    if (arr == NULL)
        return NULL;
    if (pos < 0 || pos >= arr->size)
        return NULL;
    return arr->elems[pos];
}

int getLength(DynamicArray* array)
{
    if (array == NULL)
        return 0;

    return array->size;
}

int getCapacity(DynamicArray* array)
{
    if (array == NULL)
        return 0;

    return array->capacity;
}
