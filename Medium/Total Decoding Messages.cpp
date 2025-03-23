#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int countWays(string &digits) 
        {
            int n = digits.size();
            if (n == 0 || digits[0] == '0') 
            {
                return 0; // Invalid case
            }
            
            vector<int> dp(n + 1, 0);
            dp[0] = 1; // Base case: empty string
            dp[1] = 1; // Base case: first character is valid
            
            for (int i = 2; i <= n; i++) 
            {
                // Check if the current character can be decoded alone
                if (digits[i - 1] != '0') 
                {
                    dp[i] += dp[i - 1];
                }
                
                // Check if the last two characters can be decoded together
                int twoDigit = (digits[i - 2] - '0') * 10 + (digits[i - 1] - '0');
                if (twoDigit >= 10 && twoDigit <= 26) 
                {
                    dp[i] += dp[i - 2];
                }
            }
            
            return dp[n];
        }
};

// Driver code
int main() 
{
    int tc;
    cin >> tc;
    cin.ignore();
  
    while (tc--) 
    {
        string digits;
        getline(cin, digits);
      
        Solution obj;
        int ans = obj.countWays(digits);
      
        cout << ans << "\n";
        cout << "~" << "\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/total-decoding-messages/1/
