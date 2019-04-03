#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

// checks to see if string has balanced parentheses
bool isBalanced(string sample) {
    stack<char> braces;
    for (int i = 0; i < sample.length(); i++) {
        if (sample[i] == '{' || sample[i] == '(' || sample[i] == '[') {
            braces.push(sample[i]);
        } else if (sample[i] == '}' || sample[i] == ')' || sample[i] == ']') {
            if (braces.size() == 0) {
                return false;
            }
            char lastChar = braces.top();
            braces.pop();
            if (sample[i] == '}' && lastChar != '{') {
                return false;
            } else if (sample[i] == ']' && lastChar != '[') {
                return false;
            } else if (sample[i] == ')' && lastChar != '(') {
                return false;
            }
        }
    }
    if (braces.size() > 0) {
        return false;
    }
    return true;
}

// driver function
int main() {
    string testStrings[5]{"{{}", "()()()", "][", "if(snow){no_school}else_if(sick){stay_home}", "({}[]{(([][]))})"};
    bool results[5]{0, 1, 0, 1, 1};
    for (int i = 0; i < 5; i++) {
        cout << "result: " << (isBalanced(testStrings[i]) ? "true; " : "false; ");
        cout << "string: " << testStrings[i] << endl;
        assert(isBalanced(testStrings[i]) == results[i]);
    }
    return 0;
}
