#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int countPS(string &s) 
        {
            int n = s.size();
            int count = 0;
    
            // Function to count palindromes centered around left and right
            auto countPalindromes = [&](int left, int right) 
            {
                int localCount = 0;
                while (left >= 0 && right < n && s[left] == s[right]) 
                {
                    // We only count palindromes of length >= 2
                    if (right - left + 1 >= 2) 
                    {
                        localCount++;
                    }
                  
                    left--;
                    right++;
                }
              
                return localCount;
            };
    
            // Check for palindromes centered at each character and each pair of characters
            for (int i = 0; i < n; i++) 
            {
                // Odd length palindromes (single character center)
                count += countPalindromes(i, i);
              
                // Even length palindromes (two character center)
                count += countPalindromes(i, i + 1);
            }
    
            return count;
        }
};

// Driver Code
int main() 
{
    int t;
    cin >> t;
  
    while (t--) 
    {
        string s;
        cin >> s;
      
        Solution ob;
        cout << ob.countPS(s) << endl;
      
        cout << "~\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string/1/
