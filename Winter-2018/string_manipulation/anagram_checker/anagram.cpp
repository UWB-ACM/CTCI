#include <iostream>
#include <map>
#include <string>

using namespace std;

// method definition for solution
bool is_anagram(string s1, string s2) {
    /*
     * Simple solution:
     * Construct a map for each string, with the letter as 
     * item 'first' and the frequency of letter occurences 
     * as item 'second'.
     *
     * Compare the resulting maps for equality.
     */
    
    // create map of first string
    map<char, int> map1;
    for (int i = 0; i < s1.length(); i++) {
        try {
            int current = map1.at(s1[i]);
            map1[s1[i]] = current + 1;
        } catch (out_of_range exc) {
            map1[s1[i]] = 1;
        }
    }
    // create map of second string
    map<char, int> map2;
    for (int i = 0; i < s2.length(); i++) {
        try {
            int current = map2.at(s2[i]);
            map2[s2[i]] = current + 1;
        } catch (out_of_range exc) {
            map2[s2[i]] = 1;
        }
    }
    // compare maps; return true when maps are equal
    return map1 == map2;
}

int main() {
    // Test anagram solution
    cout << "Anagrams? 'banana' and 'aaannb': " << (is_anagram("banana", "aaannb") ? "true" : "false") << endl;
    cout << "Anagrams? 'debit card' and 'bad credit': " << (is_anagram("debit card", "bad credit") ? "true" : "false") << endl;
    cout << "Anagrams? 'fancy' and 'crafty': " << (is_anagram("fancy", "crafty") ? "true" : "false") << endl;
    cout << "Anagrams? 'schoolmaster' and 'the classroom': " << (is_anagram("schoolmaster", "the classroom") ? "true" : "false") << endl;
    return 0;
}


