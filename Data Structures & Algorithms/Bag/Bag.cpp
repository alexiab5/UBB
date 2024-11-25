#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	this->noOfHashValues = 10;
    this->hashTable = new TNode*[this->noOfHashValues];
    this->noOfElements = 0;
    for(int i = 0; i < this->noOfHashValues; i++)
        this->hashTable[i] = nullptr;
}

void Bag::add(TElem elem) {
    // BC: theta(1), WC: theta(n), n=number of unique elements in the bag that have the same last digit, TC: O(n)
	if(this->noOfElements > this->noOfHashValues * 0.75) {
        this->resize();
        std::cout << noOfHashValues << std::endl;
    }
    int hashValue = this->TFunction(elem);
    if(this->hashTable[hashValue] == nullptr) { // first elem in linked list
        TNode* node = new TNode;
        node->info.first = elem;
        node->info.second = 1;
        node->next = nullptr;
        this->noOfElements++;
        this->hashTable[hashValue] = node;
    }
    else {
        // search for elem in the linked list
        TNode* currentNode = this->hashTable[hashValue];
        while(currentNode != nullptr && currentNode->info.first != elem)
            currentNode = currentNode->next;
        if(currentNode != nullptr){
            currentNode->info.second += 1; // if elem already exists, increase its frequency
        }
        else { // insert elem at the beginning of the linked list
            TNode* node = new TNode;
            node->info.first = elem;
            node->info.second = 1;
            node->next = this->hashTable[hashValue];
            this->hashTable[hashValue] = node;
        }
        this->noOfElements++;
    }
}

bool Bag::remove(TElem elem) {
    // BC: theta(1), WC: theta(n), TC: O(n)
    int hashValue = this->TFunction(elem);
    TNode* currentNode = this->hashTable[hashValue];
    TNode* prevNode = nullptr;
    while(currentNode != nullptr && currentNode->info.first != elem) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode != nullptr){
        currentNode->info.second -= 1; // if elem already exists, decrease its frequency
        if(currentNode->info.second == 0) { // if it was the last appearance of elem, delete it from the list
            if(currentNode == this->hashTable[hashValue]){ // first elem in the list
                this->hashTable[hashValue] = currentNode->next;
                delete currentNode;
            }
            else{
                prevNode->next = currentNode->next;
                delete currentNode;
            }
        }
        this->noOfElements--;
        return true;
    }
    else
        return false;
}

bool Bag::search(TElem elem) const {
    int hashValue = this->TFunction(elem);
    TNode* currentNode = this->hashTable[hashValue];
    while(currentNode != nullptr && currentNode->info.first != elem)
        currentNode = currentNode->next;
    if(currentNode != nullptr)
        return true;
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
    // BC: theta(1), WC: theta(n), TC: O(n)
    int hashValue = this->TFunction(elem);
    TNode* currentNode = this->hashTable[hashValue];
    while(currentNode != nullptr && currentNode->info.first != elem)
        currentNode = currentNode->next;
    if(currentNode == nullptr) // elem doesn't exist
        return 0;
    return currentNode->info.second; // elem exists => return its frequency
}


int Bag::size() const {
    // TC: theta(1)
	return this->noOfElements;
}


bool Bag::isEmpty() const {
	// TC: theta(1)
    return (this->noOfElements == 0);
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

Bag::~Bag() {
    for(int i = 0; i < this->noOfHashValues; i++) {
        TNode *currentNode = this->hashTable[i];
        while (currentNode != nullptr) {
            TNode *prevNode = currentNode;
            currentNode = currentNode->next;
            delete prevNode;
        }
    }
    delete[] this->hashTable;
}

int Bag::distinctCount() const {
    // TC: theta(noDistinctElements)
    int count = 0;
    for(int i = 0; i < this->noOfHashValues; i++){
        if(this->hashTable[i] != nullptr){
            TNode* current = this->hashTable[i];
            while(current != nullptr){
                current = current->next;
                count++;
            }
        }
    }
    return count;
}

void Bag::resize() {
    int newCapacity = 2 * this->noOfHashValues;
    TNode** newTable = new TNode*[newCapacity];
    for (int i = 0; i < newCapacity; i++)
        newTable[i] = nullptr;
    for (int i = 0; i < this->noOfHashValues; i++) {
        TNode* current = this->hashTable[i];
        while (current != nullptr) {
            TNode* newCurrent = current->next;
            int index = rehashFunction(current->info.first, newCapacity);
            if(newTable[index] == nullptr)
                newTable[index] = current;
            else{
                TNode* temp = newTable[index];
                newTable[index] = current;
                current->next = temp;
            }
            current = newCurrent;
        }
    }
    delete[] this->hashTable;
    this->hashTable = newTable;
    this->noOfHashValues = newCapacity;
}

