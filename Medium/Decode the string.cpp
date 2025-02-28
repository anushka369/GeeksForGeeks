#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        string decodedString(string &s) 
        {
            stack<int> countStack;  // Stack to store repeat counts
            stack<string> stringStack;  // Stack to store intermediate results
            string currentString = ""; // Stores the current decoded string
            int currentNum = 0;  // Stores the current number before '['
            
            for (char c : s) 
            {
                if (isdigit(c)) 
                {
                    // If it's a digit, update the currentNum
                    currentNum = currentNum * 10 + (c - '0');
                } 
                  
                else if (c == '[') 
                {
                    // Push the currentNum and currentString onto stacks
                    countStack.push(currentNum);
                    stringStack.push(currentString);
                  
                    // Reset currentNum and currentString
                    currentNum = 0;
                    currentString = "";
                } 
                  
                else if (c == ']') 
                {
                    // When ']' is found, pop from both stacks
                    int repeatCount = countStack.top(); countStack.pop();
                    string previousString = stringStack.top(); stringStack.pop();
                  
                    // Repeat the currentString and append to previousString
                    string temp = "";
                    for (int i = 0; i < repeatCount; i++) 
                    {
                        temp += currentString;
                    }
                  
                    currentString = previousString + temp;
                } 
                  
                else 
                {
                    // Normal characters, append to currentString
                    currentString += c;
                }
            }
          
            return currentString;
        }
};

int main()
{
    int t;
    cin >> t;
  
    while (t--) 
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
        cout << "~" << "\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/decode-the-string/
