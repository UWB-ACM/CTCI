/**
 * Solution for CTCI 6th Ed. Problem 10.3
 * Search In Rotated Array
 *
 * Solution written for UWB ACM Cracking the Coding Interview Workshop
 * April 12, 2019
 */

#include <string>
#include <sstream>
#include <iostream>
#include <cassert>

using namespace std;

// Solution method for CTCI 10.3: Search in Rotated Array
// This implementation is naive, but extremely simple.
int rotatedSearch(int searchItem, int arr[], int size) {
    int result = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchItem) {
            result = i;
            break;
        }
    }
    return result;
}

// Solution method for CTCI 10.3: Search in Rotated Array
// This implementation is optimized so that array searches are 
// terminated as soon as possible.
int rotatedSearchOptimized(int searchItem, int arr[], int size) {
    int result = -1;
    // create a boolean marker to determine if rotation point is found
    bool cycle = false;
    // create a max value marker
    int max;
    // create a placeholder int for total indeces searched
    int idx;
    // iterate over array
    for (int i = 0; i < size; i++) {
        idx = i;
        /*
         * Commented line below is useful for confirming that the 
         * search for the desired item terminates at appropriate 
         * point and the entire array is not iterated over needlessly
         */
        // cout << "Checking index " << i << endl;
        // check if rotation point has been found
        if (i > 0 && arr[i] < arr[i - 1]) {
            cycle = true;
            max = arr[i - 1];
            // if searchItem > max array value, terminate search
            if (searchItem > max) break;
        }
        // if cycle has been passed, check whether value is greater than searchItem
        else if (cycle && arr[i] > searchItem) break;
        // otherwise, check for interval with previous neighbor
        else if (i > 0 && arr[i] > searchItem && arr[i - 1] < searchItem) break;
        // lastly, check whether current index contains searchItem
        if (arr[i] == searchItem) {
            result = i;
            break;
        }
    }
    cout << "Improved solution terminated at index " << idx << endl;
    return result;
}

// Most optimal solution for problem: Binary Search
int rotatedBinarySearch(int arr[], int left, int right, int searchItem) {
    // find the midpoint between the left and right indeces
    int mid = (left + right) / 2;
    // element has been found
    if (searchItem == arr[mid]) return mid;
    // smallest possible increment of the array has been processed
    if (right < left) return -1;

    // We know, because the array is sorted, that the LHS or RHS of
    // the array must be normally ordered.
    // Use the bounds of the normally ordered half to determine which 
    // half should be searched for the desired value.
    if (arr[left] < arr[mid]) {         // LHS is normally ordered
        if (searchItem >= arr[left] && searchItem < arr[mid]) {
            // searchItem is within left-mid range; search this range
            return rotatedBinarySearch(arr, left, mid - 1, searchItem);
        } else {
            // if searchItem is not within ordered LHS range, search RHS
            return rotatedBinarySearch(arr, mid + 1, right, searchItem);
        }
    } else if (arr[mid] < arr[left]) {        // RHS is normally ordered
        if (searchItem > arr[mid] && searchItem <= arr[right]) {
            // searchItem is within mid-right range; search here
            return rotatedBinarySearch(arr, mid + 1, right, searchItem);
        } else {
            // if searchItem is not within ordered RHS range, search LHS
            return rotatedBinarySearch(arr, left, mid - 1, searchItem);
        }
    } else if (arr[left] == arr[mid]) {     // edge case: LHS or RHS is entirely repeated items
        if (arr[mid] != arr[right]) {
            return rotatedBinarySearch(arr, mid + 1, right, searchItem);
        } else {        // both halves should be searched here
            int result = rotatedBinarySearch(arr, left, mid - 1, searchItem);
            if (result == -1) {
                return rotatedBinarySearch(arr, mid + 1, right, searchItem);
            } else {
                return result;
            }
        }
    }
    return -1;
}

string printArray(int arr[], int size) {
    stringstream s;
    s << "Input array: [";
    for (int i = 0; i < size - 1; i++) {
        s << arr[i] << ", ";
    }
    if (size > 0) s << arr[size - 1];
    s << "]";
    return s.str();
}

void trySolution(int arr[], int size, int search, int expected) {
    cout << printArray(arr, size) << endl;
    
    int result = rotatedSearch(search, arr, size);
    cout << "Searched for " << search << "\tFound at " << result << endl;
    assert(result == expected);
    result = rotatedSearchOptimized(search, arr, size);
    assert(result == expected);
    result = rotatedBinarySearch(arr, 0, size - 1, search);
    assert(result == expected);
    cout << endl;
}

int main() {
    int* arr = new int[12]{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    trySolution(arr, 12, 5, 8);
    trySolution(arr, 12, 22, -1);
    trySolution(arr, 12, 0, -1);
    trySolution(arr, 12, 14, 11);
    trySolution(arr, 12, 144, -1);
    delete arr;
    return 0;
}
