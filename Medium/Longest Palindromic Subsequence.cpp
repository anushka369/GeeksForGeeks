#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int longestPalinSubseq(string &s) 
        {
            int n = s.size();
            // Create a 2D DP array
            vector<vector<int>> dp(n, vector<int>(n, 0));
    
            // Every single character is a palindrome of length 1
            for (int i = 0; i < n; i++) 
            {
                dp[i][i] = 1;
            }
    
            // Fill the DP table
            for (int length = 2; length <= n; length++) 
            {   // length of the substring
                for (int i = 0; i < n - length + 1; i++) 
                {
                    int j = i + length - 1; // Ending index of the substring
                    if (s[i] == s[j]) 
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2; // Characters match
                    } 
                    
                    else 
                    {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // Characters do not match
                    }
                }
            }
    
            // The result is in the top right corner of the DP table
            return dp[0][n - 1];
        }
};

int32_t main() 
{
    int t;
    cin >> t;
  
    while (t--) 
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~" << "\n";
    }
}

// Link to the problem: https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence/1/
