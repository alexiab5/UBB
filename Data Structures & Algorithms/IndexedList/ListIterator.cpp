#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

ListIterator::ListIterator(const IndexedList& list) : list(list){
   this->currentPos = this->list.head;
}

// theta(1)
void ListIterator::first(){
    this->currentPos = this->list.head;
}

// theta(1)
void ListIterator::next(){
    if(!this->valid())
        throw std::exception();
    this->currentPos = this->list.next[this->currentPos];
}

// theta(1)
bool ListIterator::valid() const{
    return (this->currentPos != -1);
}

// theta(1)
TElem ListIterator::getCurrent() const{
    if(!this->valid())
        throw std::exception();
   return this->list.elems[this->currentPos];
}