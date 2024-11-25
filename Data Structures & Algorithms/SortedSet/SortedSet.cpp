#include "SortedSet.h"
#include "SortedSetIterator.h"

// theta(1)
SortedSet::SortedSet(Relation r) {
    this->rel = r;
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

// BC: O(1) WC:O(length)
bool SortedSet::add(TComp elem) {
    if(this->search(elem))
        return false;
    // if the set is empty => just add the node
	if(this->head == nullptr) {
        Node* newNode = new Node;
        newNode->value = elem;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        this->head = newNode;
        this->tail = newNode;
        this->length++;
        return true;
    }
    Node* currentNode = this->head;
    while(currentNode != nullptr && this->rel(currentNode->value, elem)){
        currentNode = currentNode->next;
    }
    // insert new node
    if(currentNode == nullptr){
        // insert at the end
        Node* newNode = new Node;
        newNode->value = elem;
        newNode->prev = this->tail;
        newNode->next = nullptr;
        this->tail->next = newNode;
        this->tail = newNode;
    }
    else {
        // insert in between two nodes
        Node *newNode = new Node;
        newNode->value = elem;
        newNode->prev = currentNode->prev;
        newNode->next = currentNode;
        if(currentNode == this->head){
            this->head = newNode;
        }
        else {
            currentNode->prev->next = newNode;
        }
        currentNode->prev = newNode;
    }
    this->length++;
    return true;
}

// BC: O(1) WC:O(length)
bool SortedSet::remove(TComp elem) {
    if(this->head == nullptr)
        return false;
    // only one node
    if(this->head == this->tail && this->head->value == elem){
        this->tail = nullptr;
        delete this->head;
        this->head = nullptr;
        this->length = 0;
        return true;
    }
    // remove head
    if(elem == this->head->value){
        this->head = this->head->next;
        delete this->head->prev;
        this->head->prev = nullptr;
        this->length--;
        return true;
    }
    // remove tail
    if(elem == this->tail->value){
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = nullptr;
        this->length--;
        return true;
    }
    // remove node in between two nodes
    Node* currentNode = this->head->next;
    while(currentNode != nullptr){
        if(currentNode->value == elem) {
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;
            delete currentNode;
            this->length--;
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;

}

// O(length)
bool SortedSet::search(TComp elem) const {
	if(this->head == nullptr)
        return false;
    Node* currentNode = this->head;
    while(currentNode != nullptr){
        if(currentNode->value == elem)
            return true;
        currentNode = currentNode->next;
    }
    return false;
}

//theta(1)
int SortedSet::size() const {
	return this->length;
}

//theta(1)
bool SortedSet::isEmpty() const {
	return (this->head == nullptr && this->tail == nullptr);
}

SortedSetIterator SortedSet::iterator() {
	return SortedSetIterator(*this);
}

//theta(length)
SortedSet::~SortedSet() {
    Node* currentNode = this->head;
    if(this->head == nullptr)
        return;
    while(currentNode != nullptr){
        Node* n = currentNode->next;
        delete currentNode;
        currentNode = n;
    }
}
