/**
 * Driver file for testing the Validate BST solution.
 * Copyright 2019 Lizzy Presland
 */
#include <string>
#include <iostream>
#include <cassert>
#include "binary_tree.cpp"

using namespace std;

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

void test5() {
    /*
     * Testing the following tree:
     *              m
     *          h       q
     *      c    j     o    s
     *  a    e  i k   n p  r    t
     * Expecting test to pass
     */
    string inOrder[15]{"m", "h", "q", "c", "j", "o", "s", "a", "e", "i", "k", "n", "p", "r", "t"};
    BinTree<string> b(inOrder, 15);
    bool success = b.validate();
    assert(success);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
}
