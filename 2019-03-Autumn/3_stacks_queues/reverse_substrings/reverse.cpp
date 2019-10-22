#include <stack>
#include <sstream>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        // Create a stack to store the index position of all open parentheses.
        stack<int> open; 
        for (int i = 0; i < s.length(); i++) {
            // We have reached a new subset for reversal.
            // Add this index to the stack.
            if (s[i] == '(') {
                open.push(i);
            // We have finished traversing a subset to be reversed; 
            // now, reverse it.
            } else if (s[i] == ')') {
                int start = open.top();
                open.pop();
                // Use utility function to reverse found subset.
                // NOTE: here, we leave out the parentheses.

                string result = reverseString(s.substr(start + 1, i - start - 1));
                // We then modify the string in-place (replacing 
                // parentheses grouping with reversed inner string),
                // and update our index value to account for the removed 
                // characters.
                s.replace(start, i - start + 1, result);
                i -= 2;
            }
        }
        return s;
    }
    
private:
    string reverseString(string r) {
        stringstream s;
        for (int i = r.length() - 1; i >= 0; i--) {
            s << r[i];
        }
        return s.str();
    }
};

int main() {
    Solution s;
    string inputs[] = {"(abcd)", "(u(love)i)", "(ed(et(oc))el)", 
                       "ab(gf(cde))hij(lk)mno", "", "hello", 
                       "hap(k((ul(go))c)yp)y"};
    string output[] = {"dcba", "iloveu", "leetcode", "abcdefghijklmno", 
                       "", "hello", "happygolucky"};
    for (int i = 0; i < 7; i++) {
        string r = s.reverseParentheses(inputs[i]);
        cout << "Input: " << inputs[i] << "\tOutput: " << r << endl;
        assert(r == output[i]);
    }
    return 0;
}
