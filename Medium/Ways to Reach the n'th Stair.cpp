#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int countWays(int n) 
        {
            // Base cases
            if (n == 1) 
            {
                return 1;
            }
          
            if (n == 2) 
            {
                return 2;
            }
    
            // Create an array to store the number of ways to reach each stair
            int dp[n + 1];
          
            dp[1] = 1; // 1 way to reach the 1st stair
            dp[2] = 2; // 2 ways to reach the 2nd stair
    
            // Fill the dp array using the recurrence relation
            for (int i = 3; i <= n; i++) 
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
    
            // The answer for n stairs will be in dp[n]
            return dp[n];
        }
};

// Driver Code
int main() 
{
    // taking total testcases
    int t;
    cin >> t;
  
    while (t--) 
    {
        // taking stair count
        int m;
        cin >> m;
      
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
        cout << "~" << "\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/1/
