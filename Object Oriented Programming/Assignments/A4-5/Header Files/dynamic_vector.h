#pragma once
#include "domain.h"
#include <stdexcept>

template <typename T>
class DynamicVector {
private:
	T* elements;
	int capacity, size;
    void resize();
public:
    /// Creates a general dynamic array, with a given capacity.
	DynamicVector(int capacity = 10);
    /// Creates a general dynamic array having the same elements and capacity as the provided dynamic vector.
	DynamicVector(const DynamicVector& arr);
	~DynamicVector();
    /// Returns a reference to a copy of the provided dynamic array.
	DynamicVector& operator=(const DynamicVector& arr);

    /**
     * Adds a new element to the dynamic array.
     * Input: the element to be added.
     **/
	void addElement(const T& element);

    /**
     * Removes the element at a specific position from the dynamic array. Raises std::invalid_argument if the position is invalid.
     * Input: an integer representing the position of the element to be removed.
     **/
	void removeElement(int position);

    /**
     * Updates the element at a specific position from the dynamic array. Raises std::invalid_argument if the position is invalid.
     * Input: an integer representing the position of the element to be removed, a reference the updated element.
     **/
	void updateElement(int position, const T& element);

    /**
     * Returns the size of a dynamic array.
     **/
	int getSize() const;
    /**
     * Returns the capacity of a dynamic array.
     **/
	int getCapacity() const;

    /**
     * Searches for an element in the dynamic array.
     * Input: A reference to the element to be searched.
     * Returns: the position of the provided element in the dynamic array or -1 if it does not exist.
     **/
	int searchForElement(const T& element) const;

    /**
     * Returns the element at a specified index in the dynamic array. Raises std::invalid_argument if the index is invalid.
     **/
	T getElement(int index) const;

    /**
     * Returns the element at a specified index in the dynamic array.
     **/
	T& operator[](int index);
};

template<typename T>
void DynamicVector<T>::resize()
{
    this->capacity = 2 * this->capacity;
    T* new_vector = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
        new_vector[i] = this->elements[i];
    }
    delete[] this->elements;
    this->elements = new_vector;
}

template<typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->elements = new T[capacity];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& arr)
{
    this->capacity = arr.capacity;
    this->size = arr.size;
    this->elements = new T[arr.capacity];
    for (int i = 0; i < this->size; i++)
        this->elements[i] = arr.elements[i];
}

template<typename T>
DynamicVector<T>::~DynamicVector()
{
    delete[] this->elements;
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& arr)
{
    delete[] this->elements;
    this->capacity = arr.capacity;
    this->size = arr.size;
    this->elements = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->elements[i] = arr.elements[i];
    }
    return *this;
}

template<typename T>
void DynamicVector<T>::addElement(const T& element)
{
    if (this->capacity == this->size) {
        resize();
    }
    this->elements[this->size] = element;
    this->size++;
}

template<typename T>
void DynamicVector<T>::removeElement(int position)
{
    if (position < 0 || position >= this->size) {
        throw std::invalid_argument("Invalid position! ");
    }
    for (int i = position; i < this->size; i++)
        this->elements[i] = this->elements[i + 1];
    this->size--;
}

template<typename T>
void DynamicVector<T>::updateElement(int position, const T& element)
{
    if (position < 0 || position >= this->size) {
        throw std::invalid_argument("Invalid position! ");
    }
    this->elements[position] = element;
}

template<typename T>
int DynamicVector<T>::getSize() const
{
    return this->size;
}

template<typename T>
int DynamicVector<T>::getCapacity() const
{
    return this->capacity;
}

template<typename T>
int DynamicVector<T>::searchForElement(const T& element) const
{
    for (int i = 0; i < this->size; i++)
        if (this->elements[i] == element)
            return i;
    return -1;
}

template<typename T>
T DynamicVector<T>::getElement(int index) const
{
    if (index < 0 || index >= this->size) {
        throw std::invalid_argument("Invalid position! ");
    }
    return this->elements[index];
}

template<typename T>
T& DynamicVector<T>::operator[](int index)
{
    return this->elements[index];
}


