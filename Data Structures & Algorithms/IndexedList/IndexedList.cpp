#include <exception>
#include <stdexcept>
#include "IndexedList.h"
#include "ListIterator.h"

IndexedList::IndexedList() {
    this->cap = 5;
    this->next = new TElem[this->cap];
    this->elems = new int[this->cap];
    this->head = -1;
    for (int i = 0; i < this->cap - 1; i++)
        this->next[i] = i + 1;
    this->next[this->cap - 1] = -1;
    this->firstEmpty = 0;
    this->length = 0;
}

// theta(1)
int IndexedList::size() const {
//    int currentIndex = this->head;
//    int noElems = 0;
//    while(currentIndex != -1){
//        noElems += 1;
//        currentIndex = this->next[currentIndex];
//    }
//    return noElems;
    return this->length;
}

// theta(1)
bool IndexedList::isEmpty() const {
    return (this->head == -1);
}

// BC: theta(1), WC: theta(n), total: O(n)
TElem IndexedList::getElement(int pos) const {
    if(pos < 0 || pos >= this->length)
        throw std::exception();
    int currentIndex = this->head; // current index in the array
    int currentPos = 0; // current position in the list
    while(currentPos != pos){
        currentPos++;
        currentIndex = this->next[currentIndex];
    }
    return this->elems[currentIndex];
}

// BC: theta(1), WC: theta(n), total: O(n)
TElem IndexedList::setElement(int pos, TElem e) {
    if(pos < 0 || pos >= this->length)
        throw std::exception();
    int currentIndex = this->head;
    int currentPos = 0;
    while(currentPos != pos){
        currentIndex = this->next[currentIndex];
        currentPos++;
    }
    TElem oldVal = this->elems[currentIndex];
    this->elems[currentIndex] = e;
    return oldVal;
}

// theta(n)
void IndexedList::addToEnd(TElem e) {
    if(this->firstEmpty == -1) {
        this->resize();
    }
    int currentPos = 0;
    int currentIndex = this->head;
    if(currentIndex == -1)
    {
        this->head = this->firstEmpty;
        this->elems[this->head] = e;
        this->firstEmpty = this->next[this->firstEmpty];
        this->next[this->head] = -1;
        this->length++;
        return;
    }
    while (currentIndex != -1 && currentPos != this->length - 1) {
        currentIndex = this->next[currentIndex];
        currentPos = currentPos + 1;
    }
    if (currentIndex != -1) {
        int newPos = this->firstEmpty;
        this->firstEmpty = this->next[this->firstEmpty];
        this->elems[newPos] = e;
        this->next[newPos] = this->next[currentIndex];
        this->next[currentIndex] = newPos;
        this->length++;
    }
}

// BC: theta(1), WC: theta(n), total: O(n)
void IndexedList::addToPosition(int pos, TElem e) {
    if(pos < 0)
        throw std::exception();
    else {
        if (this->firstEmpty == -1) {
            this->resize();
        }
        if (pos == 0) {
            int newPos = this->firstEmpty;
            this->elems[newPos] = e;
            this->firstEmpty = this->next[this->firstEmpty];
            this->next[newPos] = this->head;
            this->head = newPos;
            this->length++;
        }
        else {
            int currentPos = 0;
            int currentIndex = this->head;
            while (currentIndex != -1 && currentPos != pos - 1) {
                currentIndex = this->next[currentIndex];
                currentPos = currentPos + 1;
            }
            if (currentIndex != -1) {
                int newPos = this->firstEmpty;
                this->firstEmpty = this->next[this->firstEmpty];
                this->elems[newPos] = e;
                this->next[newPos] = this->next[currentIndex];
                this->next[currentIndex] = newPos;
                this->length++;
            }
            else
                throw std::exception();
        }
    }
}

// BC: theta(1), WC: theta(n), total: O(n)
TElem IndexedList::remove(int pos) {
    if(pos < 0 || pos >= this->length)
        throw std::exception();
    int currentPos = 0; // current position in the list
    int currentIndex = this->head; // current position in the array
    int previous = -1;
    // search for the position of the element in the array
    while(currentPos != pos){
        currentPos++;
        previous = currentIndex;
        currentIndex = this->next[currentIndex];
    }
    if(currentPos == 0){
        this->head = this->next[this->head];
    }
    else if(currentPos == this->length - 1){
        this->next[previous] = -1;
    }
    else{
        this->next[previous] = this->next[currentIndex];
    }
    this->next[currentIndex] = this->firstEmpty;
    this->firstEmpty = currentIndex;
    this->length--;
    return this->elems[currentIndex];
}

// BC: theta(n), WC: theta(n), total: O(n)
int IndexedList::search(TElem e) const{
    int i = this->head;
    int currentPos = 0;
    while(i != -1){
        if(this->elems[i] == e)
            return currentPos;
        i = this->next[i];
        currentPos++;
    }
    return -1;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}

IndexedList::~IndexedList() {
	delete[] this->elems;
    delete[] this->next;
}

void IndexedList::resize() {
    TElem* newElems = new TElem[2*this->cap];
    int* newNext = new int[2*this->cap];
    for(int i = 0; i < this->cap; i++) {
        newElems[i] = this->elems[i];
        newNext[i] = this->next[i];
    }
    for(int i = this->cap; i < this->cap*2 - 1; i++)
        newNext[i] = i + 1;
    newNext[2*this->cap - 1] = -1;
    this->elems = newElems;
    this->next = newNext;
    this->firstEmpty = this->cap;
    this->cap = 2 * this->cap;
}

// theta(n)
int IndexedList::removeFromKtoK(int k) {
    if(k <= 0)
        throw std::exception();
    if(k > this->length)
        return 0;
    int currentIndex = 0;
    int pos = 1;
    int removed = 0;
    int previous = 0;
    while(currentIndex != -1){
        if(pos % k == 0){
            this->next[previous] = this->next[currentIndex];
            this->next[firstEmpty] = firstEmpty;
            this->firstEmpty = currentIndex;
            removed++;
            this->length--;
        }
        previous = currentIndex;
        currentIndex = this->next[currentIndex];
        pos++;
    }
    return removed;
}
// pos
// 1 2 3 4 5 6 7 8
// k=2
// 1 3 5 7