#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool isSubsetSum(vector<int>& arr, int sum) 
        {
            int n = arr.size();
                // Create a DP table with (n+1) x (sum+1)
                vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
                
                // Base case: A sum of 0 can always be formed with an empty subset
                for (int i = 0; i <= n; i++) 
                {
                    dp[i][0] = true;
                }
                
                // Fill the DP table
                for (int i = 1; i <= n; i++) 
                {
                    for (int j = 1; j <= sum; j++) 
                    {
                        if (arr[i - 1] <= j) 
                        {
                            // Include the current element or exclude it
                            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                        } 
                        
                        else 
                        {
                            // Exclude the current element
                            dp[i][j] = dp[i - 1][j];
                        }
                    }
            }
            
            // The answer will be in the bottom-right cell of the DP table
            return dp[n][sum];
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
        if (ob.isSubsetSum(arr, sum))
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
