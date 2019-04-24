/**
 * Solution for CTCI 6th Ed. Problem 1.3
 * URLify a String
 *
 * Solution written for UWB ACM Cracking the Coding Interview Workshop
 * April 26, 2019
 */

#include <iostream>

using namespace std;

char* urlify(char* str, int length) {
    // First, iterate over the first <length> chars in array and 
    // count the number of spaces.
    int spaceCount = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') spaceCount++;
    }
    // Edge case: no replacement is needed
    if (spaceCount == 0) return str;
    // Now that the count has been determined, multiply spaceCount *= 2,
    // add that number to length to get the number of array indeces needed,
    // and work backwards through the array, replacing as you go.
    int newLength = length + (spaceCount * 2);
    int oldIdx = length - 1;
    for (int i = newLength - 1; i > 0; i--) {
        if (str[oldIdx] == ' ') {
            // replace with %20
            str[i] = '0';
            str[i-1] = '2';
            str[i-2] = '%';
            i = i - 2;
        } else {
            // replace with existing char
            str[i] = str[oldIdx];
        }
        oldIdx--;
        if (oldIdx == i) break;
    }
    return str;
}

void printArray(char* array, int length) {
    cout << "'";
    for (int i = 0; i < length; i++) {
        cout << array[i];
    }
    cout << "'" << endl;
    return;
}

int main() {
    char* test1 = new char[10]{'h', 'i', ' ', 't', 'h', 'e', 'r', 'e', ' ', ' '};
    printArray(test1, 10);
    test1 = urlify(test1, 8);
    printArray(test1, 10);
    char* test2 = new char[24]{'c', 'a', 'n', ' ', 'I', ' ', 'g', 'e', 't', ' ', 'a', ' ', 'h', 'e', 'a', 'l', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printArray(test2, 24);
    test2 = urlify(test2, 16);
    printArray(test2, 24);
    delete test1;
    delete test2;
    return 0;
}
