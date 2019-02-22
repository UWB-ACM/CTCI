/**
 * Complete, minimal, and verifiable solution tests for the "check subtree" 
 * problem.
 * Created for UW Bothell ACM's Winter 2019 CTCI session.
 * Copyright 2019 Lizzy Presland
 */
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include "binary_tree.cpp"

using namespace std;

void test1() {
    string inOrder[15]{"m", "h", "q", "c", "j", "o", "s", "a", "e", "i", "k", "n", "p", "r", "t"};
    BinTree<string> b1(inOrder, 15);
    string subtree[7]{"h", "c", "j", "a", "e", "i", "k"};
    BinTree<string> b2(subtree, 7);
    bool success = b1.isSubtree(b2);
    assert(success);
}

void test2() {
    string inOrder[15]{"m", "h", "q", "c", "j", "o", "s", "a", "e", "i", "k", "n", "p", "r", "t"};
    BinTree<string> b1(inOrder, 15);
    string subtree[6]{"h", "c", "j", "a", "e", "i"};
    BinTree<string> b2(subtree, 6);
    bool success = b1.isSubtree(b2);
    assert(!success);
}

void test3() {
    string inOrder[15]{"h", "h", "q", "c", "j", "o", "s", "a", "e", "i", "k", "n", "p", "r", "t"};
    BinTree<string> b1(inOrder, 15);
    string subtree[7]{"h", "c", "j", "a", "e", "i", "k"};
    BinTree<string> b2(subtree, 7);
    bool success = b1.isSubtree(b2);
    assert(success);
}

int main() {
    test1();
    test2();
    test3();
}
