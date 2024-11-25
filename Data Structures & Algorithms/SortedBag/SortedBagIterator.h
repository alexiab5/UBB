#pragma once
#include "SortedBag.h"
#include <stack>
class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
    SortedBag& bag;
	SortedBagIterator(SortedBag& b);

	BSTNode* current;
    std::stack<BSTNode*> inOrder;
    std::stack<BSTNode*> parents;
//    void inOrderTraversal(BSTNode* node);
    void inOrderTraversal(BSTNode *node, BSTNode *parent = nullptr);

public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
    TElem remove();
};

