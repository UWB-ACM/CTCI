#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
       // create integers that represent strings length
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int remain = 0;
        string ans;
        // loops through while any condition is true
        while(n1 >= 0 || n2 >= 0 || remain) {
        int d1;
        int d2;
        // checks if values are left in num1
            if (n1 >= 0){
            // if so- turn d1 into int diff of string ASCII and '0'
                d1 = num1[n1--] - '0';
                } else {
                d1 = 0;
            }
            // Ternary equivalent
            // int d1 = (n1 >= 0) ? num1[n1--] - '0' : 0;
            if (n2 >= 0){
                int d2 = num2[n2--] - '0';
                } else {
                int d2 = 0;
            }
            // Ternary equivalent
            // int d2 = (n2 >= 0) ? num2[n2--] - '0' : 0;
            
            int sum = d1 + d2 + remain;
            // remain is 0 in integer division if value is less than 10
            remain = sum/10;
            ans += '0' + (sum % 10); 
        }
        // reverse the string to form appropriate return value
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution myString;
    string retString;
    retString = myString.addStrings("0", "0");
    assert("0" == retString);
    retString = myString.addStrings("9", "999");
    assert("1008" == retString);
    retString = myString.addStrings("1", "0");
    assert("1" == retString);
    retString = myString.addStrings("1", "9999");
    assert("10000" == retString);
    retString = myString.addStrings("0", "9999");
    assert("9999" == retString);
    return 0;
}