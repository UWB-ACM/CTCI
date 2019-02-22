/**
 *
 * Complete, minimal, verifiable solution for "Validate BST".
 * Created for UW Bothell ACM's Winter 2019 CTCI session.
 * Copyright 2019 Lizzy Presland
 *
 */
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

/**
 * Defining the binary tree we will use for this problem.
 */
template <class T>
class BinTree {

    public:
        /**
         * Public Helper Functions
         */

        // default constructor
        BinTree() {
            root = nullptr;
        }

        // array constructor
        // builds BST in top-bottom, left-right fashion 
        // starting at the tree's root.
        BinTree(T items[], int size) {
            int count = 0;
            int height = 0;
            buildTree(items, size, count, height, root);
            // comment
        }

        // destructor
        ~BinTree() {
            destroyTree(root);
        }

        bool validate() {
            // return validateHelper(root, root, true);
            return validateHelper(root, nullptr, nullptr);
        }

    
    private:
        // the Node struct needed for class functions
        struct Node {
            Node* left{nullptr};
            Node* right{nullptr};
            T data;
        };

        // the root of the tree
        Node* root;

        /**
         * Private Helper Functions
         */

/*
 * This is kind of broken...
        // the actual interview question's solution, implemented as a class method
        //
        bool validateHelper(Node<T>* currPtr, Node<T>* divider, bool isLeft) {
            // base case - return true if currptr is null
            if (currPtr == nullptr)
                return true;
            bool balLhs = (currPtr->left == nullptr || currPtr->left->data <= currPtr->data);
            bool balRhs = (currPtr->right == nullptr || currPtr->right->data > currPtr->data);
            bool isDividedCorrectly = true;
            if (isLeft && currPtr->data > divider->data) {
                isDividedCorrectly = false;
            } else if (!isLeft && currPtr->data <= divider->data) {
                isDividedCorrectly = false;
            }
            bool switchDir = currPtr != divider;
            return balLhs && balRhs && isDividedCorrectly && validateHelper(currPtr->left, divider, isLeft) && validateHelper(currPtr->right, divider, switchDir) && validateHelper(currPtr->left, currPtr, true) && validateHelper(currPtr->right, currPtr, false);
        }
 */

        // the actual interview question's solution, implemented as a class method
        bool validateHelper(Node* currPtr, Node* minVal, Node* maxVal) {
            // base case: return true if current node is nullptr
            if (currPtr == nullptr)
                return true;
            // for the given partition points (min/max values possible),
            // ensure that the current node's data lies within the permissible range
            if (minVal != nullptr && currPtr->data < minVal->data)
                return false;
            if (maxVal != nullptr && currPtr->data >= maxVal->data)
                return false;
            bool checkLhs = validateHelper(currPtr->left, minVal, currPtr);
            bool checkRhs = validateHelper(currPtr->right, currPtr, maxVal);
            if (!checkLhs || !checkRhs)
                return false;
            return true;
        }

        // clear all nodes in tree
        void destroyTree(Node* currNode) {
            if (currNode == nullptr)
                return;
            destroyTree(currNode->left);
            destroyTree(currNode->right);
            delete currNode;
            return;
        }

        // builds tree from array
        void buildTree(T items[], int size, int& count, int& height, Node* ptr) {
            while (count < size) {
                if (count == 0) {
                    root = makeNode(items[count]);
                } else {
                    // do stuff
                    Node* parent = root;
                    int resid = count - (pow(2, height) - 1);
                    for (int i = height - 1; i > 0; i--) {
                        if (resid / int(pow(2, i)) == 0) {
                            parent = parent->left;
                        }
                        else {
                            parent = parent->right;
                        }
                    }
                    if ((count - int(pow(2, height) - 1)) % 2 == 0) {
                        parent->left = makeNode(items[count]);
                    } else {
                        parent->right = makeNode(items[count]);
                    }
                }
                count++;
                if (pow(2, height + 1) - 1 <= count)
                    height++;
            }
        }

        // construct a new node
        Node* makeNode(T nextData) {
            Node* newNode = new Node();
            newNode->data = nextData;
            return newNode;
        }

};

void test1() {
    /*
     * Testing the following tree:
     *        e
     *    b        g
     * a    k    f    h
     * Expecting test to fail.
     */
    string stuff[7]{"e", "b", "g", "a", "k", "f", "h"};
    BinTree<string> b(stuff, 7);
    bool success = b.validate();
    assert(!success);
}

void test2() {
    /*
     * Testing the following tree:
     *  B
     * A C
     * Expecting test to pass.
     */
    string stuff[3]{"B", "A", "C"};
    BinTree<string> b(stuff, 3);
    bool success = b.validate();
    assert(success);
}

void test3() {
    /*
     * Testing the following tree:
     *        d
     *    b        f
     * a    c    e    g
     * Expecting test to pass.
     */
    string stuff[7]{"d", "b", "f", "a", "c", "e", "g"};
    BinTree<string> b(stuff, 7);
    bool success = b.validate();
    assert(success);
}

void test4() {
    /*
     * Testing the following tree:
     *        a
     *    b        c
     * d    e    f    g
     */
    string notInOrder[7]{"a", "b", "c", "d", "e", "f", "g"};
    BinTree<string> b(notInOrder, 7);
    bool success = b.validate();
    assert(!success);
}

int main() {
    test1();
    test2();
    test3();
    test4();
}
