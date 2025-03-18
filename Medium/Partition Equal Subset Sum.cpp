#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool equalPartition(vector<int>& arr) 
        {
            int sum = accumulate(arr.begin(), arr.end(), 0);
    
            // If the sum is odd, it cannot be partitioned into two equal subsets
            if (sum % 2 != 0)
            {    
                return false;
            }
    
            int target = sum / 2;
            int n = arr.size();
            
            // DP array to check if a subset sum of 'target' is possible
            vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    
            // A sum of 0 is always possible with an empty subset
            for (int i = 0; i <= n; i++) 
            {
                dp[i][0] = true;
            }
    
            // Fill the DP table
            for (int i = 1; i <= n; i++) 
            {
                for (int j = 1; j <= target; j++) 
                {
                    if (arr[i - 1] <= j) 
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                    } 
                      
                    else 
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
    
            return dp[n][target];
        }
};

// Driver Code
int main() 
{
    int t;
    cin >> t;
    cin.ignore();
  
    while (t--) 
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
      
        while (ss >> number) 
        {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
        {
            cout << "true" << endl;
        }
          
        else
        {
            cout << "false" << endl;
        }
      
        cout << "~" << endl;
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/subset-sum-problem/1/
