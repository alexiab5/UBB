#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
	this->root = nullptr;
    this->noElements = 0;
    this->r = r;
}

BSTNode *SortedBag::allocateNode(TComp info) {
    BSTNode* node = new BSTNode;
    node->info = info;
    node->right = nullptr;
    node->left = nullptr;
    return node;
}

// BC: theta(1), TC: O(h)
void SortedBag::add(TComp e) {
    this->noElements++;
    if(this->root == nullptr) { // the tree is empty
        this->root = this->allocateNode(e);
        return;
    }
    BSTNode* current = this->root;
    BSTNode* prev = nullptr;
    while(current != nullptr){
        prev = current;
        if(!r(current->info, e)) // e > current => continue in the right subtree
            current = current->right;
        else
            current = current->left; // else if e <= current => continue in the left subtree
    }
    BSTNode* newNode = this->allocateNode(e);
    if(!r(prev->info, e))
        prev->right = newNode;
    else prev->left = newNode;
}

// BC: theta(1), WC: O(n)
bool SortedBag::remove(TComp e) {
	if(this->root == nullptr)
        return false;
    BSTNode* current = this->root;
    BSTNode* prev = nullptr;
    while(current != nullptr){
        if(current->info == e){
            this->noElements--;
            // if the node is a leaf (no descendents)
            // set the corresponding child of the parent to null
            if(current->left == nullptr && current->right == nullptr) {
                if (current == this->root) {
                    this->root = nullptr;
                    delete current;
                    return true;
                }
                if (prev->right == current)
                    prev->right = nullptr;
                else
                    prev->left = nullptr;
                delete current;
                return true;
            }
            // if the node has only one descendent
            // replace the node with its descendent
            if(current->left == nullptr){
                BSTNode* tmp = current->right;
                if(current == this->root){
                    delete current;
                    this->root = tmp;
                    return true;
                }
                if(prev->right == current){
                    delete current;
                    current = tmp;
                    prev->right = current;
                    return true;
                }
                delete current;
                current = tmp;
                prev->left = current;
                return true;
            }
            if(current->right == nullptr){
                BSTNode* tmp = current->left;
                if(current == this->root) {
                    delete current;
                    this->root = tmp;
                    return true;
                }
                if(prev->right == current){
                    delete current;
                    current = tmp;
                    prev->right = current;
                    return true;
                }
                delete current;
                current = tmp;
                prev->left = current;
                return true;
            }
            // if the node has two descendents
            // replace the node with its inorder successor (the minimum in the right subtree)
            BSTNode* successor = current->right;
            BSTNode* succParent = current;
            BSTNode* grandParent = nullptr;
            while(successor->left != nullptr){
                if(successor->info != succParent->info)
                    grandParent = succParent;
                succParent = successor;
                successor = successor->left;
            }
            if(successor->info != succParent->info) { // if the right subtree doesn't contain duplicates
                current->info = successor->info;
                if (succParent->left == successor)
                    succParent->left = successor->right;
                else
                    succParent->right = successor->right;
                delete successor;
                return true;
            }
            current->info = successor->info;
            succParent->left = successor->right; // null
            delete successor;
            BSTNode* tmp = current->left;
            if(grandParent == current) {
                current->left = grandParent->right;
                current->right = grandParent->right->right;
                current->left->right = nullptr;
            }
            else {
                BSTNode* aux = current->left;
                current->left = grandParent->left;
                BSTNode* aux2 = grandParent->left;
                while(aux2->left != nullptr)
                    aux2 = aux2->left;
                aux2->left = aux;
                grandParent->left = grandParent->left->right;
                if(current->left != nullptr)
                    current->left->right = nullptr;
            }
            succParent->left = tmp;
            succParent->right = nullptr;
            return true;
        }
        prev = current;
        if(!this->r(current->info, e))
            current = current->right;
        else
            current = current->left;

    }
	return false;
}

// BC: theta(1), TC: O(h), h = height of the tree => O(n)
bool SortedBag::search(TComp elem) const {
	BSTNode* current = this->root;
    while(current != nullptr){
        if(current->info == elem)
            return true;
        else if(!this->r(current->info, elem))
            current = current->right;
        else
            current = current->left;
    }
    return false;
}

int SortedBag::nrOccurrences(TComp elem) const {
	BSTNode* current = this->root;
    int occurrences = 0;
    while(current != nullptr){
        if(current->info == elem)
            occurrences++;
        if(!this->r(current->info, elem))
            current = current->right;
        else
            current = current->left;
    }
	return occurrences;
}

int SortedBag::size() const {
	return this->noElements;
}

bool SortedBag::isEmpty() const {
	return (this->root == nullptr);
}

SortedBagIterator SortedBag::iterator() {
	return SortedBagIterator(*this);
}

// theta(n)
void SortedBag::destroyRecursive(BSTNode* node)
{
    if (node != nullptr)
    {
        destroyRecursive(node->left);
        destroyRecursive(node->right);
        delete node;
    }
}

SortedBag::~SortedBag() {
    destroyRecursive(this->root);
}

