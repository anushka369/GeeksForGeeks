#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int maxLength(string& s) 
        {
            stack<int> stk;
            stk.push(-1); // Base index for valid substring calculation
            int maxLength = 0;
    
            for (int i = 0; i < s.size(); i++) 
            {
                if (s[i] == '(') 
                {
                    stk.push(i); // Push the index of '('
                } 
                
                else 
                {
                    stk.pop(); // Pop the last '(' index
    
                    if (stk.empty()) 
                    {
                        // If stack is empty, push the current index as a base
                        stk.push(i);
                    }
                    
                    else 
                    {
                        // Calculate the length of the valid substring
                        maxLength = max(maxLength, i - stk.top());
                    }
                }
            }
    
            return maxLength;
        }
};

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
        cout << "~" << "\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1/
