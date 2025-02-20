#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool isBalanced(string& s) 
        {
            stack<char> stk;
            unordered_map<char, char> bracketMap = 
            {
                {')', '('},
                {'}', '{'},
                {']', '['}
            };
    
            for (char ch : s) 
            {
                // If it's an opening bracket, push onto the stack
                if (ch == '(' || ch == '{' || ch == '[') 
                {
                    stk.push(ch);
                } 
                  
                // If it's a closing bracket
                else if (ch == ')' || ch == '}' || ch == ']') 
                {
                    // Check if the stack is empty or the top doesn't match
                    if (stk.empty() || stk.top() != bracketMap[ch]) 
                    {
                        return false; // Not balanced
                    }
                    stk.pop(); // Pop the matched opening bracket
                }
            }
    
            // If the stack is empty, all brackets were matched
            return stk.empty();
        }
};

int main() 
{
    int t;
    string a;
    cin >> t;
  
    while (t--) 
    {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
        {
            cout << "true" << endl;
        }
          
        else
        {
            cout << "false" << endl;
        }
        cout << "~" << "\n";
    }
}

// Link to the problem: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1/
