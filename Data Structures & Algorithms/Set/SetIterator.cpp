#include "SetIterator.h"
#include "Set.h"
#include <stdexcept>

SetIterator::SetIterator(const Set& m) : set(m)
{
	this->currentPosition = 0;
}

// Best Case: theta(1) Worst Case: theta(1) Average Case: theta(1) Total: theta(1)
void SetIterator::first() {
    this->currentPosition = 0;
}

// Best Case: theta(1) Worst Case: theta(1) Average Case: theta(1) Total: theta(1)
void SetIterator::next() {
    if(valid())
        this->currentPosition += 1;
    else
        throw std::invalid_argument("Invalid iterator");
}

// Best Case: theta(1) Worst Case: theta(1) Average Case: theta(1) Total: theta(1)
TElem SetIterator::getCurrent()
{
    if(valid())
	    return set.elements[this->currentPosition];
    throw std::invalid_argument("Invalid iterator!");
}

// Best Case: theta(1) Worst Case: theta(1) Average Case: theta(1) Total: theta(1)
bool SetIterator::valid() const {
	if(this->currentPosition >= set.length)
        return false;
    return true;
}

// Best Case: theta(1) Worst Case: theta(1) Average Case: theta(1) Total: theta(1)
void SetIterator::previous() {
    if(!valid()){
        throw(std::invalid_argument("Invalid iterator!"));
    }
    if(this->currentPosition == 0){ // the current element is the first in the set
        this->currentPosition = set.length; // the iterator is now invalid
        return;
    }
    this->currentPosition--;
}



