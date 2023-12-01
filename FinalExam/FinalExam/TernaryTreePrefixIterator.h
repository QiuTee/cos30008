


#pragma once

#include "TernaryTree.h"

#include <stack>

template<typename T>
class TernaryTreePrefixIterator
{
private:
    using TTree = TernaryTree<T>;
    using TTreeNode = TTree*;
    using TTreeStack = std::stack<const TTree*>;

    const TTree* fTTree;                // ternary tree
    TTreeStack fStack;                  // traversal stack

public:

    using Iterator = TernaryTreePrefixIterator<T>;

    Iterator operator++(int)
    {
        Iterator old = *this;

        ++(*this);

        return old;
    }

    bool operator!=(const Iterator& aOtherIter) const
    {
        return !(*this == aOtherIter);
    }

    /////////////////////////////////////////////////////////////////////////
    // Problem 4: TernaryTree Prefix Iterator

private:
    //Because pre-order traversal works in such a way that it will look at one child node on the left before it considers the last child node on the left it will move to the center node and then continue to consider all the left child nodes of the middle node
    // it will do that until it meets the last child node on the right side of the tree 
    // So in push_subtree we have to push the child node from the right side so that the child node on the left will be pushed in the last into the stack. 
    // So when taking the first child node in the stack to continue pushing the child nodes of the first node in the stack, the left child node of the tree will be removed first and its child nodes will continue to be pushed into the stack 
    //                                    [root]                        |A  |
    //                                /     |      \                    |B  |
    //                               /      |       \                   |C  |
    //                             [A]      [B]      [C]                |___|
    //                            
    // push subtree of aNode [30]
    void push_subtrees(const TTree* aNode) {
        if (!aNode->getRight().empty()) {
            fStack.push(&aNode->getRight()); //push the address of the right subtree onto the stack
            //cout << *aNode->getRight() << " ";
        }
        if (!aNode->getMiddle().empty()) {
            fStack.push(&aNode->getMiddle());//push the address of the middle subtree onto the stack
            //cout << *aNode->getMiddle() << " ";
        }
        if (!aNode->getLeft().empty()) {
            fStack.push(&aNode->getLeft());//push the address of the left subtree onto the stack
            //cout << *aNode->getLeft() << " ";
        }

    }
    // Because the pre_order 
public:

    // iterator constructor [12]
    TernaryTreePrefixIterator(const TTree* aTTree) : fTTree(aTTree) {
        if (aTTree != &TTree::NIL) {
            fStack.push(aTTree); // push root of tree into the stack 
        }
    }

    // iterator dereference [8]
    const T& operator*() const {
        return **fStack.top(); // get the key of the top subtree in the stack 
    }

    // prefix increment [12]
    Iterator& operator++() {
        TTreeNode tmp = const_cast<TTreeNode>(fStack.top()); // get the top subtree in the stack and store it in the temporary variable 
        fStack.pop(); // delete the top node in stack
        push_subtrees(tmp); // use push_subtree to push the subtree of tmp into the stack 
        return *this; 
    }

    // iterator equivalence [12]
    bool operator==(const Iterator& aOtherIter) const {
        return fStack.size() == aOtherIter.fStack.size() && fTTree == aOtherIter.fTTree; // compare size of stack and address of tree 
    }

    // auxiliaries [4,10]
    Iterator begin() const {
        Iterator iter = *this; 
        iter.fStack = TTreeStack();
        iter.fStack.push(const_cast<TTreeNode>(iter.fTTree));
        return iter; 
    }
    Iterator end() const {
        Iterator iter = *this; 
        iter.fStack = TTreeStack(); 
        return iter; 
    }
};
