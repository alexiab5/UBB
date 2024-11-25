#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
#include <iostream>
#include <utility>


typedef int TElem;

class TNode{
public:
    std::pair<TElem, int> info; // keys are pairs <unique value, frequency>
    TNode* next;
};

class BagIterator; 
class Bag {

private:
	TNode** hashTable;
    int noOfHashValues;
    int TFunction(TElem key) const{
        return abs(key % noOfHashValues);
    }
    int noOfElements;
    void resize();
    int rehashFunction(TElem key, int capacity) const{
        return abs(key % capacity);
    }
	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();

    int distinctCount() const;
};