/**
 *
 * Complete, minimal implementation of a Binary Tree.
 * Created for UW Bothell ACM's Winter 2019 CTCI session.
 * Copyright 2019 Lizzy Presland
 *
 */
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

using namespace std;

/**
 * Defining the binary tree we will use for this problem.
 */
template <class T>
class BinTree {

    private:
        // the Node struct needed for class functions
        struct Node {
            Node* left{nullptr};
            Node* right{nullptr};
            T data;
        };

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

        // locate nodes in the tree which match the provided data
        vector<Node*> find(T data) {
            vector<Node*> items;
            findHelper(data, items, root);
            return items;
        }

        // determine whether two subtrees are identical
        bool identical(Node* ptr) {
            return identicalHelper(ptr, root);
        }

        T getRoot() {
            if (root != nullptr)
                return root.data;
        }

        bool isSubtree(BinTree& t2) {
            vector<Node*> subTrees = this->find(t2.root->data);
            bool isSubtree = false;
            for (typename vector<Node*>::iterator it = subTrees.begin(); it != subTrees.end(); ++it) {
                isSubtree = t2.identical(*it);
                if (isSubtree)
                    break;
            }
            return isSubtree;
        }

    private:
        // the root of the tree
        Node* root;

        /**
         * Private Helper Functions
         */

        // a helper method that searches the tree for all nodes that 
        // contain the supplied data
        void findHelper(T searchItem, vector<Node*>& items, Node* rootPtr) {
            if (rootPtr == nullptr)
                return;
            if (rootPtr->data == searchItem)
                items.push_back(rootPtr);
            findHelper(searchItem, items, rootPtr->left);
            findHelper(searchItem, items, rootPtr->right);
        }

        bool identicalHelper(Node* ptr1, Node* ptr2) {
            if (ptr1 == nullptr && ptr2 == nullptr)
                return true;
            if (ptr1 == nullptr && ptr2 != nullptr)
                return false;
            if (ptr1 != nullptr && ptr2 == nullptr)
                return false;
            return identicalHelper(ptr1->left, ptr2->left) && (ptr1->data == ptr2->data) && identicalHelper(ptr1->right, ptr2->right);
        }


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

