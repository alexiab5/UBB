#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

//theta(n)
SortedBagIterator::SortedBagIterator(SortedBag& b) : bag(b) {
	this->first();
}

//theta(1)
TComp SortedBagIterator::getCurrent() {
	if(!this->valid())
        throw std::exception();
    return this->current->info;
}

//theta(1)
bool SortedBagIterator::valid() {
	return (current != nullptr);
}


//theta(1)
void SortedBagIterator::next() {
	if(!this->valid())
        throw std::exception();
    if(this->inOrder.size() == 0)
        this->current = nullptr;
    else{
        this->current = this->inOrder.top();
        this->inOrder.pop();
        this->parents.pop();
    }
}

// theta(n)
void SortedBagIterator::first() {
    while(!this->inOrder.empty())
        this->inOrder.pop();
    this->inOrderTraversal(this->bag.root);
    if (this->inOrder.size() == 0)
        this->current = nullptr;
    else {
        this->current = this->inOrder.top();
        this->inOrder.pop();
    }
}

//theta(n)
//void SortedBagIterator::inOrderTraversal(BSTNode *node) {
//    if(node != nullptr){
//        this->inOrderTraversal(node->left);
//        this->inOrder.push(node);
//        this->inOrderTraversal(node->right);
//    }
//}

void SortedBagIterator::inOrderTraversal(BSTNode *node, BSTNode *parent) {
    if (node != nullptr) {
        this->inOrderTraversal(node->left, node);
        this->inOrder.push(node);
        this->parents.push(parent);  // Push the parent node onto the parent stack
        this->inOrderTraversal(node->right, node);
    }
}

//TElem SortedBagIterator::remove() {
//    if(!this->valid())
//        throw std::exception();
//    BSTNode* toBeRemoved = this->current;
//    int val = toBeRemoved->info;
//    BSTNode* prev = this->parents.top();
//    this->next();
//
//    if(toBeRemoved->left == nullptr && toBeRemoved->right == nullptr) {
//        if (toBeRemoved == bag.root) {
//            bag.root = nullptr;
//            delete toBeRemoved;
//            return val;
//        }
//        if (prev->right == toBeRemoved)
//            prev->right = nullptr;
//        else
//            prev->left = nullptr;
//        delete toBeRemoved;
//        return val;
//    }
//    // if the node has only one descendent
//    // replace the node with its descendent
//    if(toBeRemoved->left == nullptr){
//        BSTNode* tmp = toBeRemoved->right;
//        if(toBeRemoved == bag.root){
//            delete toBeRemoved;
//            bag.root = tmp;
//            return val;
//        }
//        if(prev->right == current){
//            delete toBeRemoved;
//            toBeRemoved = tmp;
//            prev->right = toBeRemoved;
//            return val;
//        }
//        delete toBeRemoved;
//        toBeRemoved = tmp;
//        prev->left = toBeRemoved;
//        return val;
//    }
//    if(toBeRemoved->right == nullptr){
//        BSTNode* tmp = toBeRemoved->left;
//        if(toBeRemoved == bag.root) {
//            delete toBeRemoved;
//            bag.root = tmp;
//            return val;
//        }
//        if(prev->right == toBeRemoved){
//            delete toBeRemoved;
//            toBeRemoved = tmp;
//            prev->right = toBeRemoved;
//            return val;
//        }
//        delete toBeRemoved;
//        toBeRemoved = tmp;
//        prev->left = toBeRemoved;
//        return val;
//    }
//    // if the node has two descendents
//    // replace the node with its inorder successor (the minimum in the right subtree)
//    BSTNode* successor = toBeRemoved->right;
//    BSTNode* succParent = toBeRemoved;
//    BSTNode* grandParent = nullptr;
//    while(successor->left != nullptr){
//        if(successor->info != succParent->info)
//            grandParent = succParent;
//        succParent = successor;
//        successor = successor->left;
//    }
//    if(successor->info != succParent->info) { // if the right subtree doesn't contain duplicates
//        toBeRemoved->info = successor->info;
//        if (succParent->left == successor)
//            succParent->left = successor->right;
//        else
//            succParent->right = successor->right;
//        delete successor;
//        return val;
//    }
//    toBeRemoved->info = successor->info;
//    succParent->left = successor->right; // null
//    delete successor;
//    BSTNode* tmp = toBeRemoved->left;
//    if(grandParent == current) {
//        toBeRemoved->left = grandParent->right;
//        toBeRemoved->right = grandParent->right->right;
//        toBeRemoved->left->right = nullptr;
//    }
//    else {
//        BSTNode* aux = toBeRemoved->left;
//        toBeRemoved->left = grandParent->left;
//        BSTNode* aux2 = grandParent->left;
//        while(aux2->left != nullptr)
//            aux2 = aux2->left;
//        aux2->left = aux;
//        grandParent->left = grandParent->left->right;
//        if(toBeRemoved->left != nullptr)
//            toBeRemoved->left->right = nullptr;
//    }
//    succParent->left = tmp;
//    succParent->right = nullptr;
//    return val;
//}

// O(n)
TElem SortedBagIterator::remove() {
    if(!this->valid())
        throw std::exception();
    int value = this->current->info;
    bag.remove(value);
    this->next();
    return value;
}