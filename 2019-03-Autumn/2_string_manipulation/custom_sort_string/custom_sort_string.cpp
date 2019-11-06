#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string customSortString(const string& S, const string& T) {
    int charCounts[26];
    fill(charCounts, charCounts + 26, 0);

    // count char occurrences in T
    for (const char& c: T) charCounts[c - 'a']++;

    ostringstream resStream;
    // append the chars present in S
    for (const char& c: S)
        while (charCounts[c - 'a']-- > 0)
            resStream << c;
    // append the chars for the rest
    for (char c = 'a'; c <= 'z'; c++)
        while (charCounts[c - 'a']-- > 0)
            resStream << c;
            
    return resStream.str();
}

void test1() {
    string S = "cba";
    string T = "abcd";
    cout << "Test1 - S=" << S << " T=" << T << endl;
    cout << "Result: " << customSortString(S, T) << endl;
}

void test2() {
    string S = "cbafg";
    string T = "abcd";
    cout << "Test2 - S=" << S << " T=" << T << endl;
    cout << "Result: " << customSortString(S, T) << endl;
}

void test3() {
    string S = "disqyr";
    string T = "iwyrysqrdj";
    cout << "Test3 - S=" << S << " T=" << T << endl;
    cout << "Result: " << customSortString(S, T) << endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}