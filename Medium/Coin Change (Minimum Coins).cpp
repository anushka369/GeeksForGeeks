#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int minCoins(vector<int> &coins, int sum) 
        {
            // Create a DP array to store the minimum number of coins for each sum
            vector<int> dp(sum + 1, INT_MAX);
            
            // Base case: No coins are needed to make the sum of 0
            dp[0] = 0;
    
            // Iterate over each coin
            for (int coin : coins) 
            {
                // Update the dp array for all sums that can be formed with this coin
                for (int j = coin; j <= sum; j++) 
                {
                    if (dp[j - coin] != INT_MAX) 
                    {   // Check if the previous sum can be formed
                        dp[j] = min(dp[j], dp[j - coin] + 1);
                    }
                }
            }
    
            // If dp[sum] is still INT_MAX, it means we cannot form that sum
            return dp[sum] == INT_MAX ? -1 : dp[sum];
        }
};

// Driver Code
int main() 
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
  
    while (t--) 
    {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
      
        vector<int> arr;
        string input;
        getline(cin, input);      
        stringstream ss(input);
        int number;
      
        while (ss >> number) 
        {
            arr.push_back(number);
        }
      
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/number-of-coins/1
