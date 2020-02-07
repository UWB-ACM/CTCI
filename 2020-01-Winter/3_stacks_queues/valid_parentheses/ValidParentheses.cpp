  #include <iostream>
  #include <stack>
  
  using namespace std;
  
  bool isValid(string s);
  
  int main() {
    string test0 = "()"; // Output: true
    string test1 = "()[]{}"; //Output: true
    string test2 = "(]"; // Output: false
    string test3 = "{[]}"; // Output: true
    string test4 = "";      // Output: true
    string test5 = "abc[]"; // Output: false, per problem statement
    cout << "test0 = " << test0 << ". Valid?: " << isValid(test0) << endl;
    cout << "test1 = " << test1 << ". Valid?: " << isValid(test1) << endl;
    cout << "test2 = " << test2 << ". Valid?: " << isValid(test2) << endl;
    cout << "test3 = " << test3 << ". Valid?: " << isValid(test3) << endl;
    cout << "test4 = " << test4 << ". Valid?: " << isValid(test4) << endl;
    cout << "test5 = " << test5 << ". Valid?: " << isValid(test5) << endl;
  }
  
  bool isValid(string s) {
      stack<char> st;
      
      for(int i=0;i<s.length();i++)
      {
          if(s[i] == '(' || s[i] == '{' || s[i] == '[')
              st.push(s[i]);
          // Can't be empty at this point...
          if(st.empty())
              return false;
          if(s[i] == ')')
          {
              int x = st.top();
              st.pop();
              if(x != '(')
                  return false;
          }
          else if(s[i] == '}')
          {
              int x = st.top();
              st.pop();
              if(x != '{')
                  return false;
          }
          else if(s[i] == ']')
          {
              int x = st.top();
              st.pop();
              if(x != '[')
                  return false;
          }
      }    
     return st.empty();
  }
