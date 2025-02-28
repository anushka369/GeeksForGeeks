#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
      int evaluate (vector<string>& arr) 
      {
          stack <int>st;
          for (string&i : arr)
          {
              if (i == "+" || i == "*" || i == "-" || i == "/")
              {
                  int b = st.top(); 
                  st.pop();
                
                  int a = st.top();
                  st.pop();
                  int result;
                
                  if (i == "+") 
                  {
                      result = a + b;
                  }
                    
                  else if (i == "-") 
                  {
                      result = a - b;
                  }
                    
                  else if (i == "*")
                  {
                      result = a * b;
                  }
                    
                  else if (i == "/")
                  {
                      result = a / b;
                  }
                
                  st.push(result);
              }
                
              else 
              {
                  st.push(stoi(i));
              }
          }
          return st.top();
      }
};

int main() 
{
    string str;
    getline(cin, str);
    int t = stoi(str);
  
    while (t--) 
    {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
      
        while (ss >> str) 
        {
            arr.push_back(str);
        }
      
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}

// Link to the problem: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1/
