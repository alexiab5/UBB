#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(SortedSet& m) : multime(m)
{
	this->currentNode = multime.head;
}

//theta(1)
void SortedSetIterator::first() {
    this->currentNode = multime.head;
}

//theta(1)
void SortedSetIterator::next() {
    if(!valid())
        throw exception();
	this->currentNode = this->currentNode->next;
}

//theta(1)
TElem SortedSetIterator::getCurrent()
{
	if(!this->valid())
        throw exception();
    return this->currentNode->value;

}

//theta(1)
bool SortedSetIterator::valid() const {
	if(this->currentNode == nullptr)
        return false;
    return true;
}

TElem SortedSetIterator::remove() {
    // theta(1)
    if (!this->valid())
        throw exception();
    Node* current = this->currentNode;
    TElem currentValue = current->value;
    // only one element in the set
    if(this->multime.length == 1) {
        this->multime.tail = nullptr;
        delete this->multime.head;
        this->multime.head = nullptr;
        this->multime.length = 0;
        this->currentNode = nullptr;
        return currentValue;
    }
    // always removing the head, next node becomes new head
    current->next->prev = nullptr;
    this->multime.head = current->next;
    this->currentNode = current->next;
    this->multime.length--;
    currentValue = current->value;
    delete current;
    return currentValue;
}

