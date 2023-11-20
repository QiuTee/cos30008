#pragma once 
#include "DoublyLinkedList.h" 
#include "DoublyLinkedListIterator.h" 
#include <stdexcept> 
using namespace std;
template<typename T>
class List
{
private:
	// auxiliary definition to simplify node usage 
	using Node = DoublyLinkedList<T>;
	Node* fRoot;
	size_t fCount;
public:
	// the first element in the list 
	// number of elements in the list 
	// auxiliary definition to simplify iterator usage 
	using Iterator = DoublyLinkedListIterator<T>;
	List() { // default constructor 
		fRoot = NULL ;
		fCount = 0; 
	}
	List(const List& aOtherList) {
		fRoot = NULL; 
		fCount = 0; 
		*this = aOtherList; 
	}
	
   // copy constructor 
	List& operator=(const List& aOtherList) {
		if (&aOtherList != this ) {
			this->~List();
			fCount = 0;
			fRoot = NULL; 
			for (auto it = aOtherList.begin(); it != aOtherList.end(); it++) {
				auto element = *it;
				push_back(element);
			}
		}
		return *this; 
	} // assignment operator 
	~List() {// destructor - frees all nodes 
		while (fRoot != NULL) {
			Node* tmp = const_cast<Node*>(&fRoot->getPrevious());
			if (fRoot != tmp) {
				Node* lTemp = const_cast<Node*>(&fRoot->getPrevious());
				lTemp->isolate();
				delete lTemp;
			}
			else {
				delete fRoot;
				break; 
			}
		}
	}

	void remove(const T& aElement) {// remove first match from list 

		if (isEmpty()) {
			return;
		}
		Node* rRoot = fRoot;
		Node* tmp = nullptr;

		while (rRoot != nullptr) {
			
			if (rRoot->getPayload() == aElement) {
				if (fRoot == rRoot) {//delete when find match at first node 
					tmp = const_cast<Node*>(&rRoot->getNext());
					if (tmp != nullptr) {
						fRoot = const_cast<Node*>(&fRoot->getNext());
						rRoot->isolate();
						delete rRoot;
					}
					else {
						fRoot = nullptr;
					}
				}
				else if (&rRoot->getNext() == NULL) { //delete when find match at last node 
					rRoot->isolate();
					delete rRoot;
				}
				else {
					rRoot->isolate();
					delete rRoot;
				}
				fCount--;
				break; // if find the first match -> delete node match and break 
			}
			rRoot = const_cast<Node*>(&rRoot->getNext());
		}
	}

	
	bool isEmpty() const {// Is list empty? 
		if (fRoot != NULL) return false;
		return true;
	}
	size_t size() const {// list size 
		return fCount; 
	}
	void push_front(const T& aElement) {// adds aElement at front
		Node* newNode = new Node(aElement); 
		if (isEmpty()) {
			fRoot = newNode; 
		}
		else {
			fRoot->push_front(*newNode);
			fRoot = newNode;
		}
		fCount++;
	}
	void push_back(const T& aElement) {
		Node* newNode = new Node(aElement);
		if (isEmpty()) {
			fRoot = newNode;
		}
		else {
			Node* tmp = const_cast<Node*>(&fRoot->getPrevious());
			tmp->push_back(*newNode);
			tmp = newNode;
		}
		fCount++;
	}// adds aElement at back 
	const T& operator[](size_t aIndex) const {
		Node* tmp = fRoot; 
		if (aIndex >= fCount) {
			throw out_of_range("Index out of bounds.");
		}
		else {
			for (int i = 0; i < aIndex; i++) {
				tmp = const_cast<Node*>(&tmp->getNext());
			}
		}
		return tmp->getPayload();
	} // list indexer 
	Iterator begin() const {
		return Iterator(fRoot);
	}
	Iterator end() const {
		return Iterator(fRoot);
	}
	Iterator rbegin() const {

		return Iterator(fRoot).rbegin();
	}
	Iterator rend() const {
		return Iterator(fRoot).rend();
	}
	// move features 
	List(List&& aOtherList) {
		fRoot = NULL;
		fCount = 0;
		*this = std::move(aOtherList);
	}
	List& operator=(List&& aOtherList) {
		if (&aOtherList != this) {
			this->~List();
			fRoot = aOtherList.fRoot;
			fCount = aOtherList.fCount;
			aOtherList.fRoot = nullptr;
			aOtherList.fCount = 0;
			for (auto it = aOtherList.begin(); it != aOtherList.end(); it++) {
				auto element = *it;
				push_back(element);
			}
		}
		return *this;
	}
	void push_front(T&& aElement) {
		Node* newNode = new Node(std::move(aElement));
		
		if (isEmpty()) {
			fRoot = newNode;
		}
		else {
			fRoot->push_front(*newNode);
			fRoot = newNode;
		}
		fCount++;
	}
	void push_back(T&& aElement) {
		Node* newNode = new Node(std::move(aElement));
		if (isEmpty()) {
			fRoot = newNode;
		}
		else {
			Node* prenode = const_cast<Node*>(&fRoot->getPrevious());
			prenode->push_back(*newNode);
			prenode = newNode;
		}
		fCount++;
	}
};