#pragma once
#include <stdexcept>
using namespace std;
template<typename T>
class BTree
{
private:
	T fKey; // T() for empty BTree
	BTree<T>* fLeft;
	BTree<T>* fRight;
	BTree() : fKey(T()) , fLeft(&NIL) , fRight(&NIL){}
		// sentinel constructor
	// tree manipulator auxiliaries
	void attach(BTree<T>** aNode, const BTree<T>& aBTree) {
		if (!empty()) {
			if ((*aNode)->empty()) {
				*aNode = const_cast<BTree<T>*>(&aBTree);
			}
		}
		else {
			throw domain_error("No empty subtree valid ");
		}
	}
	const BTree<T>& detach(BTree<T>** aNode) {
		if (!(*aNode)->empty()){
			BTree<T> *Result = *aNode; 
			*aNode = &NIL;
			return *Result;
		}
		else {
			throw domain_error("No empty subtree valid ");
		}
	}
public:
	static BTree<T> NIL; // Empty BTree
	BTree(const T& aKey) : fKey(aKey) , fLeft(&NIL) , fRight(&NIL)  {
		
	} // BTree leaf
	BTree(T&& aKey) : fKey(move(aKey)), fLeft(&NIL), fRight(&NIL) {} // BTree leaf
	BTree(const BTree& aOtherBTree) : BTree(){
		*this = aOtherBTree; 
	}// copy constructor
	BTree(BTree&& aOtherBTree) : BTree(){
		*this = move(aOtherBTree);
	} // move constructor
	virtual ~BTree() {
		if (fRight != &NIL) {
			delete fRight; 
		}
		if (fLeft != &NIL) {
			delete fLeft;
		}
	} // destructor
	BTree& operator=(const BTree& aOtherBTree)    // copy assignment operator
	{
		if (!aOtherBTree.empty())
		{
			if (this != &aOtherBTree)
			{
				this->~BTree(); 
				fKey = aOtherBTree.fKey;
				fLeft = aOtherBTree.left().clone(); // su dung .clone boi vi left tra ve tham chieu &
				fRight = aOtherBTree.right().clone();
			}

			return *this;
		}
		else
		{
			throw std::domain_error("Illegal binary tree operation.");
		}
	}
	// copy assignment operator
	BTree& operator=(BTree&& aOtherBTree) {
		if (this != &aOtherBTree) {
			if (!aOtherBTree.empty()) {
				this->~BTree();
				fKey = move(aOtherBTree.fKey);
				fLeft = aOtherBTree.left().clone();
				fRight = aOtherBTree.right().clone();
			}
			else {
				throw domain_error("Illegal binary tree operation.");
			}
		}
		else {
			throw domain_error("Copying of NIL detected.");
		}
		return *this;

	}
		// move assignment operator
	virtual BTree* clone() const {
		if (!empty()) {
			return new BTree(*this); 
		}
		else {
			return const_cast<BTree<T>*>(this);
		}
	} // clone a tree
	bool empty() const {
		return this == &NIL; 
	}// is tree empty
	const T& operator*() const {
		return fKey;
	} // get key (node value)
	const BTree& left() const {
		return *fLeft; 
	}
	const BTree& right() const {
		return *fRight;
	}
	// tree manipulators
	void attachLeft(const BTree<T>& aBTree) {
		attach(&fLeft, aBTree); 
	}
	void attachRight(const BTree<T>& aBTree) {
		attach(&fRight, aBTree); 
	}
	const BTree& detachLeft() {
		return detach(&fLeft);
	}
	const BTree& detachRight() {
		return detach(&fRight);
	}
	
};

template<class T>
BTree<T> BTree<T>::NIL;