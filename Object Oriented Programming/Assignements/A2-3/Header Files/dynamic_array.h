#pragma once
#include "domain.h"
#include <stdbool.h>
#include <stdlib.h>
#define CAPACITY 50

typedef void TElem;
typedef void (*DestroyFunctionType)(TElem*);

typedef struct {
    TElem** elems;
    int size;
    int capacity;
    DestroyFunctionType destroyFct;
}DynamicArray;

/// <summary>
/// Creates a general dynamic array, with a given capacity.
/// </summary>
/// <param name="capacity">= Integer, maximum capacity for the dynamic array.</param> <param name="destroyFct">= The function used to destroy the elements of the array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArray* createDynamicArray(int capacity, DestroyFunctionType destroyFct);
/// <summary>
/// Adds an element of type integer to a dynamic array of integers.
/// </summary>
/// <param name="array">= The address of the dynamic array.</param> <param name="element">= The element to be added in the array.</param>
/// <returns>0 if the element was successfully added to the array, 1 otherwise.</returns>
bool addElement(DynamicArray* array, TElem* number);

/// <summary>
/// Deletes the element at a specific position in a dynamic array.
/// </summary>
/// <param name="array">= The address of the dynamic array.</param> <param name="number">= The position of the element to be deleted.</param>
/// <returns>0 if the element was successfully deleted, 1 otherwise.</returns>
bool deleteElementAtPosition(DynamicArray* array, int position);

/// <summary>
/// Resizes a dynamic array of integers.
/// </summary>
/// <param name="array">= The address of the dynamic array to be resized.</param>
/// <returns>0 if the array was successfully resized, 1 otherwise.</returns>
bool resize(DynamicArray* array);

/// <summary>
/// Destroys a dynamic array.
/// </summary>
/// <param name="array">= The address of the dynamic array to be destroyed.</param>
/// <returns>None</returns>
void destroyDynamicArray(DynamicArray* array);

/// <summary>
/// Returns the length of a dynamic array.
/// </summary>
/// <param name="array">= The address of the dynamic array.</param>
/// <returns>The length of the dynamic array.</returns>
int getLength(DynamicArray* array);

/// <summary>
/// Returns the capacity of a dynamic array.
/// </summary>
/// <param name="array">= The address of the dynamic array.</param>
/// <returns>The capacity of the dynamic array.</returns>
int getCapacity(DynamicArray* array);

/// <summary>
/// Returns the element on a given position.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="pos">The position - must be a valid position.</param>
/// <returns>The element on the given position.</returns>
TElem* get(DynamicArray* arr, int pos);
