#include <string>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

string tripletString(int triplet) {
    // Returns strings like:
    // Six Hundred Forty
    // Ninety Seven
    // Three Hundred Thirteen
    stringstream s;
    string small[10]{"", "One ", "Two ", "Three ", "Four ", "Five ", 
                     "Six ", "Seven ", "Eight ", "Nine "};
    string teens[10]{"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", 
                     "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", 
                     "Nineteen "};
    string mults[10]{"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", 
                     "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    // Handle hundreds first
    if (triplet > 99) {
        int val = triplet / 100;
        s << small[val];
        s << "Hundred ";
    }
    // subtract hundreds multiple from triplet value
    triplet -= (triplet / 100) * 100;
    // Handle teens next (1-99)
    // NOTE: special case if 10 <= n <= 19
    if (triplet > 19) {
        s << mults[triplet / 10];
        // Subtract teens value from triplet
        triplet -= (triplet / 10) * 10;
        // s << small[triplet];
    } else if (triplet > 9) {
        s << teens[triplet - 10];
        // Subtract full value from triplet (since single term suffices)
        triplet -= triplet;
    }
    // Handle single digit values last (if n < 10 or n >= 20)
    if (triplet > 0) {
        s << small[triplet];
    }
    return s.str();
}

string englishInteger(int num) {
    stringstream s;
    // Special case: num is 0 (not handled in triplet function)
    if (num == 0) {
        s << "Zero";
        return s.str();
    }
    // Special case: if value is negative, print negative and convert 
    // to positive value for processing
    if (num < 0) {
        s << "Negative ";
        num *= -1;
    }
    // Due to the C/C++ Standard, most compilers only allow a maximum 
    // of ~2bn as an integer value. So, we will use these limits in our 
    // implementation.
    int marker = 1000000000;        // One billion
    string mString = "Billion ";    // Text value
    // Process number set until all increments have been converted to string
    while (num != 0) {
        // Get triplet value
        int val = num / marker;
        // Convert to string if triplet value is non-zero
        if (val > 0) {
            s << tripletString(val);
            s << mString;
        }
        // Subtract processed triplet from number argument
        num = num % marker;
        // Get next marker level down to determine triplet value in 
        // next occurence of while loop
        marker /= 1000;
        // For the next round of triplet values, set the triplet string 
        // to be the next grouping down (eg million -> thousand)
        if (marker == 1000000) mString = "Million ";
        else if (marker == 1000) mString = "Thousand ";
        else if (marker == 1) mString = "";

    }
    return s.str();
}

int main() {
    cout << "The maximum integer value for this environment is: " << endl;
    cout << INT_MAX << endl;
    cout << "-3,841,182 is " << englishInteger(-3841182) << endl;
    cout << "765,800 is " << englishInteger(765800) << endl;
    cout << "765,349,011 is " << englishInteger(765349011) << endl;
    cout << "-89,001,001 is " << englishInteger(-89001001) << endl;
    cout << "1,001,499,819 is " << englishInteger(1001499819) << endl;
    cout << "3,000,999 is " << englishInteger(3000999) << endl;
    cout << "1 is " << englishInteger(1) << endl;
    return 0;
}
