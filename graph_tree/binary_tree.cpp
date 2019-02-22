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

