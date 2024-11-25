#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    // BC: theta(1), WC: theta(noOfHashValues)
    this->currentHashValue = 0;
    this->currentNode = nullptr;
    this->currentFrequency = 0;
    while(this->bag.hashTable[currentHashValue] == nullptr && currentHashValue < this->bag.noOfHashValues)
        this->currentHashValue++;
    if(currentHashValue != this->bag.noOfHashValues) {
        this->currentNode = this->bag.hashTable[currentHashValue]; // if there are no elems in the bag, the iterator becomes invalid
        if (this->currentNode != nullptr)
            this->currentFrequency = this->currentNode->info.second;
    }
}

void BagIterator::first() {
    // BC: theta(1), WC: theta(noOfHashValues)
    this->currentHashValue = 0;
    while(this->bag.hashTable[currentHashValue] == nullptr && currentHashValue < this->bag.noOfHashValues)
        this->currentHashValue++;
    this->currentNode = this->bag.hashTable[currentHashValue];
    if(this->currentNode != nullptr)
        this->currentFrequency = this->currentNode->info.second;
}


void BagIterator::next() {
    // BC: theta(1), WC: theta(noOfHashValues)
    if(!this->valid())
        throw std::exception();
	this->currentFrequency--;
    if(this->currentFrequency == 0){ // search for the next element
        currentNode = currentNode->next;
        if(currentNode == nullptr) {
            this->currentHashValue++;
            while (this->bag.hashTable[currentHashValue] == nullptr && currentHashValue < this->bag.noOfHashValues)
                this->currentHashValue++;
            if(currentHashValue != bag.noOfHashValues) {
                this->currentNode = this->bag.hashTable[currentHashValue];
                if (this->currentNode != nullptr)
                    this->currentFrequency = this->currentNode->info.second;
            }
        }
        else
            this->currentFrequency = this->currentNode->info.second;
    }
}


bool BagIterator::valid() const {
    // theta(1)
	return (this->currentNode != nullptr);
}

TElem BagIterator::getCurrent() const {
    // theta(1)
    if(!this->valid())
        throw std::exception();
	return this->currentNode->info.first;
}
