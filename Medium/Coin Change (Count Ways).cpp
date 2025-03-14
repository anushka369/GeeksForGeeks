#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int count(vector<int>& coins, int sum) 
        {
            // Create a DP array to store the number of ways to make each sum
            vector<int> dp(sum + 1, 0);
            
            // Base case: There is one way to make the sum 0
            dp[0] = 1;
    
            // Iterate over each coin
            for (int coin : coins) 
            {
                // Update the dp array for all sums that can be formed with this coin
                for (int j = coin; j <= sum; j++) 
                {
                    dp[j] += dp[j - coin];
                }
            }
    
            // The answer is the number of ways to make the target sum
            return dp[sum];
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
      
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/coin-change/1/
