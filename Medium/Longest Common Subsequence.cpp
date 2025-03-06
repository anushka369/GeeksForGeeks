#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int lcs(string &s1, string &s2) 
        {
            int m = s1.size();
            int n = s2.size();
            
            // Create a 2D array to store lengths of longest common subsequence.
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            
            // Build the dp array
            for (int i = 1; i <= m; i++) 
            {
                for (int j = 1; j <= n; j++) 
                {
                    if (s1[i - 1] == s2[j - 1]) 
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } 
                    
                    else 
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            
            // The length of the longest common subsequence is in dp[m][n]
            return dp[m][n];
        }
};

int main() 
{
    int t;
    cin >> t;
  
    while (t--) 
    {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/longest-common-subsequence/1/
