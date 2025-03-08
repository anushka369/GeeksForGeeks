#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        string longestPalindrome(string &s) 
        {
            int n = s.size();
            if (n == 0) 
            {  
                return "";
            }
            
            int start = 0;
            int maxLength = 1;
    
            // Function to expand around center
            auto expandAroundCenter = [&](int left, int right) 
            {
                while (left >= 0 && right < n && s[left] == s[right]) 
                {
                    left--;
                    right++;
                }
              
                return right - left - 1; // Length of the palindrome
            };
    
            for (int i = 0; i < n; i++) 
            {
                // Odd length palindromes
                int len1 = expandAroundCenter(i, i);
              
                // Even length palindromes
                int len2 = expandAroundCenter(i, i + 1);
              
                int len = max(len1, len2);                
                if (len > maxLength) 
                {
                    maxLength = len;
                    start = i - (maxLength - 1) / 2; // Calculate the start index
                }
            }
    
            return s.substr(start, maxLength);
        }
};

// Driver code
int main() 
{
    int t;
    cin >> t;
  
    while (t--) 
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~" << "\n";
    }
}

// Link to the problem: https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string/1/
