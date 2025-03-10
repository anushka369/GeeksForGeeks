#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        // Function to compute the edit distance between two strings
        int editDistance(string& s1, string& s2) 
        {
            int m = s1.length();
            int n = s2.length();
            
            // Create a DP table
            vector<vector<int>> dp(m + 1, vector<int>(n + 1));
            
            // Initialize base cases
            for (int i = 0; i <= m; i++) 
            {
                dp[i][0] = i; // Deleting all characters from s1
            }
        
            for (int j = 0; j <= n; j++) 
            {
                dp[0][j] = j; // Inserting all characters of s2
            }
            
            // Fill the DP table
            for (int i = 1; i <= m; i++) 
            {
                for (int j = 1; j <= n; j++) 
                {
                    if (s1[i - 1] == s2[j - 1]) 
                    {
                        dp[i][j] = dp[i - 1][j - 1]; // No operation needed
                    } 
                    
                    else
                    {
                        dp[i][j] = min({dp[i - 1][j] + 1,    // Remove
                                        dp[i][j - 1] + 1,    // Insert
                                        dp[i - 1][j - 1] + 1 // Replace
                                       });
                    }
                }
            }
            
            // The answer is in the bottom-right cell
            return dp[m][n];
        }
};

// Driver Code
int main()
{
    int T;
    cin >> T;
    cin.ignore();
  
    while (T--) 
    {
        string s1;
        getline(cin, s1);
      
        string s2;
        getline(cin, s2);
      
        Solution ob;
        int ans = ob.editDistance(s1, s2);
      
        cout << ans << "\n";
        cout << "~" << endl;
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/edit-distance/1/
