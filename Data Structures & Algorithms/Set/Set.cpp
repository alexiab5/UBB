#include "Set.h"
#include "SetITerator.h"

Set::Set() {
    this->length = 0;
    this->capacity = 2;
    this->elements = new TElem[this->capacity];
}

// Best Case: theta(n) Worst Case: theta(n) Average Case: theta(n) Total: O(n)
void Set::resize() {
    {
        this->capacity = 2 * this->capacity;
        TElem* new_array = new TElem[this->capacity];
        for (int i = 0; i < this->length; i++) {
            new_array[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = new_array;
    }
}

// Best Case: theta(1) Worst Case: theta(n) (the array needs to be resized) Average Case: theta(1)? Total: O(n)
bool Set::add(TElem elem) {
	if(search(elem) == true)
	    return false;
    if(this->length == this->capacity){
        resize();
    }
    this->elements[length] = elem;
    this->length++;
    return true;
}

// Best Case: theta(n) Worst Case: theta(n) Average Case: theta(n) Total: theta(n)
bool Set::remove(TElem elem) {
	for(int i = 0; i < this->length; i++){
        if(this->elements[i] == elem){
            for(int j = i; j < this->length - 1; j++)
                this->elements[j] = this->elements[j + 1];
            this->length--;
            return true;
        }
    }
    return false;
}

// Best Case: theta(1) (when the element is on the first position of the array) Worst Case: theta(n) Average Case: theta(n) Total: O(n)
bool Set::search(TElem elem) const {
	for(int i = 0; i < this->length; i++)
        if(this->elements[i] == elem)
            return true;
    return false;
}

// Best Case: theta(1) Worst Case: theta(1) Average Case: theta(1) Total: theta(1)
int Set::size() const {
	return this->length;
}

// Best Case: theta(1) Worst Case: theta(1) Average Case: theta(1) Total: theta(1)
bool Set::isEmpty() const {
	return (this->length == 0);
}

Set::~Set() {
	delete[] this->elements;
}

SetIterator Set::iterator() const {
	return SetIterator(*this);
}

Set &Set::operator=(const Set &s) {
    if(this == &s){
        return *this;
    }
    delete[] this->elements;
    this->capacity = s.capacity;
    this->length = s.length;
    this->elements = new TElem[this->capacity];
    for (int i = 0; i < this->length; i++) {
        this->elements[i] = s.elements[i];
    }
    return *this;
}

Set::Set(const Set &s) {
    this->length = s.length;
    this->capacity = s.capacity;
    this->elements = new TElem[this->capacity];
    for(int i = 0; i < this->length; i ++)
        this->elements[i] = s.elements[i];
}




