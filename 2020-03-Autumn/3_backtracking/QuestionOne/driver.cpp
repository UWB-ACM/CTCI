#include <iostream>
#include <vector>
using namespace  std;

//Helper funtion checking if a string is palindrome
bool isPalindrome(string &s, int left, int right) {

    while(left < right){

        if(s[left] != s[right]){

            return false;
        }
        left++;
        right--;
    }
    return true;
}

void dfs(vector<vector<string>>& result, string& s, int start, vector<string>& currList) {
    //If we have reached the end of the string it means we have achieved our goal
    //Push the currList is a valid list of palindromes and return
    if (start >= s.length()) {
        result.push_back(currList);
        return;
    }

    //Generate all possible substrings beginning at index 'start'
    for (int end = start; end < s.length(); end++) {

        //if it is palindrome, add the potential candidate to the 'currList' and
        //Perform a DFS on the rest of the substring
        if (isPalindrome(s, start, end)) {

            //Add the current potential candidate to 'currList'
            currList.push_back(s.substr(start, end - start + 1));

            dfs(result, s, end + 1, currList); //Notice our 'start' index is the next char after the 'end' index

            //Backtrack and remove the recently added potential candidate
            currList.pop_back();
        }
    }

}

vector<vector<string>> partition(string s) {
    //The result to return
    vector<vector<string>> result;

    //Keeps track of the current candidate
    vector<string> currList;

    //for the initial recursive call, we send the vector to return, the string to check for palindromes
    //The starting index, and the list holding current candidates
    dfs(result, s, 0, currList);
    return result;
}

int main() {

    //Approach: Backtracking
    string s = "aab";

    vector<vector<string>> palindromesList = partition(s);

    for (int i = 0; i < palindromesList.size() ; ++i) {
        cout << "[";
        for (int j = 0; j < palindromesList.at(i).size() - 1; ++j) {

            cout << palindromesList[i][j] << ", ";
        }

        cout << palindromesList[i][palindromesList[i].size() - 1]<< "]"<<endl;

        if (i == palindromesList.size()) {
            cout << " ]" <<endl;
        }

    }

    return 0;
}
