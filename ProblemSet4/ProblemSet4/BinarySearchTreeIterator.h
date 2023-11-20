#pragma once
#include "BinarySearchTree.h"
#include <stack>
template<typename T>
class BinarySearchTreeIterator
{
private:
	using BSTree = BinarySearchTree<T>;
	using BNode = BinaryTreeNode<T>;
	using BTreeNode = BNode*;
	using BTNStack = std::stack<BTreeNode>;
	const BSTree& fBSTree; // binary search tree
	BTNStack fStack; // DFS traversal stack
	void pushLeft(BTreeNode aNode) {
		if (!aNode->empty()) {
			fStack.push(aNode);
			aNode = aNode->left;
			pushLeft(aNode);
		}
	}
public:
	using Iterator = BinarySearchTreeIterator<T>;
	BinarySearchTreeIterator(const BSTree& aBSTree) : fBSTree(aBSTree){
		pushLeft(aBSTree.fRoot); 
	}
	const T& operator*() const {
		return fStack.top()->key; 
	}
	Iterator& operator++() {
		BTreeNode nodeTmp = fStack.top(); 
		fStack.pop(); 
		pushLeft(nodeTmp->right); 
		return *this;
		
	}
	Iterator operator++(int) {
		Iterator temp = *this; 
		++(*this); 
		return temp; 
	}
	bool operator==(const Iterator& aOtherIter) const {
		return fStack == aOtherIter.fStack && &fBSTree == &aOtherIter.fBSTree; 
	}
	bool operator!=(const Iterator& aOtherIter) const {
		return !(aOtherIter == *this); 
	}
	Iterator begin() const {
		Iterator tmp = *this; 
		tmp.fStack = BTNStack(); 
		tmp.pushLeft(fBSTree.fRoot);
		return tmp; 
	}
	Iterator end() const {
		Iterator tmp = *this;
		tmp.fStack = BTNStack(); 
		return tmp;
	}
};