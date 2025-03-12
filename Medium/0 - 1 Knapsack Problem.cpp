#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        // Function to return max value that can be put in knapsack of capacity W
        int knapsack(int W, vector<int> &val, vector<int> &wt) 
        {
            int n = val.size();
            vector<int> dp(W + 1, 0);
    
            for (int i = 0; i < n; i++) 
            {
                for (int w = W; w >= wt[i]; w--) 
                {
                    dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
                }
            }
    
            return dp[W];
        }
};

// Driver Code
int main() 
{
    int testCases;
    cin >> testCases;
  
    while (testCases--) 
    {
        int W, n;
        cin >> W >> n;        
        vector<int> val(n), wt(n);
      
        for (int i = 0; i < n; i++) 
        {
            cin >> val[i];
        }
      
        for (int i = 0; i < n; i++) 
        {
            cin >> wt[i];
        }

        Solution solution;
        cout << solution.knapsack(W, val, wt) << endl;
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem/1/
