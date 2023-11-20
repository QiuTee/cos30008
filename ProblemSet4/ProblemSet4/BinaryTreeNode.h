#pragma once
#include <stdexcept>
#include <algorithm>
using namespace std;
template<typename T>
struct BinaryTreeNode
{
	using BNode = BinaryTreeNode<T>;
	using BTreeNode = BNode*;

	T key;
	BTreeNode left;
	BTreeNode right;

	static BNode NIL;
	const T& findMax() const {
		if (empty()) {
			throw domain_error("Tree cannot be empty ");
		}
		if (right->empty()) {
			return key;
		}
		return right->findMax();
	}
	const T& findMin() const {
		if (empty()) {
			throw domain_error("Tree cannot be empty");
		}
		if (left->empty()) {
			return key;
		}
		else {
			return left->findMin();
		}

	}
	bool remove(const T& aKey, BTreeNode aParent)
	{
		BTreeNode x = this;
		BTreeNode y = aParent;

		while (!x->empty())
		{
			if (aKey == x->key)
			{
				break;
			}

			y = x;                                      // new parent

			x = aKey < x->key ? x->left : x->right;
		}

		if (x->empty())
		{
			return false;                               // delete failed
		}

		if (!x->left->empty())
		{
			const T& lKey = x->left->findMax();         // find max to left
			x->key = lKey;
			x->left->remove(lKey, x);
		}
		else
		{
			if (!x->right->empty())
			{
				const T& lKey = x->right->findMin();    // find min to right
				x->key = lKey;
				x->right->remove(lKey, x);
			}
			else
			{
				if (y != &NIL)                        // y can be NIL
				{
					if (y->left == x)
					{
						y->left = &NIL;
					}
					else
					{
						y->right = &NIL;
					}
				}

				delete x;                               // free deleted node
			}
		}

		return true;
	}


	BinaryTreeNode() : key(T()), left(&NIL), right(&NIL) {}
	BinaryTreeNode(const T& aKey) : key(aKey), left(&NIL), right(&NIL) {}
	BinaryTreeNode(T&& aKey) : key(move(aKey)), left(&NIL), right(&NIL) {}
	~BinaryTreeNode() {
		if (right != &NIL) {
			delete right;
		}
		if (left != &NIL) {
			delete left;
		}
	}

	bool empty() const {
		return (this == &NIL);
	}
	bool leaf() const {
		return (right->empty() && left->empty());
	}
	size_t height() const
	{
		if (empty())
		{
			throw domain_error("Empty tree encountered");
		}
		if (leaf())
		{
			return 0;
		}
		if (right == &NIL || left == &NIL) {
			return 0; 
		}
		return max(left->height(), right->height()) + 1;
	}
	bool insert(const T& aKey)
	{
		if (empty())
		{
			return false;
		}
		BTreeNode newNode = new BNode();
		newNode->key = aKey;
		newNode->right = newNode->left = &NIL;
		if (aKey > key)
		{
			if (right->empty())
			{
				right = newNode;
				return true;
			}
			else
			{
				return right->insert(aKey);
			}
			
		}
		if (aKey < key)
		{
			if (left->empty())
			{
				left = newNode;
				return true;
			}
			else
			{
				return left->insert(aKey);
			}
			
		}
		return false;
	}
};
template<typename T>
BinaryTreeNode<T> BinaryTreeNode<T>::NIL;