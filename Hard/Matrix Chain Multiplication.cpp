#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int matrixMultiplication(vector<int> &arr) 
        {
            int n = arr.size();
            vector<vector<int>> dp(n, vector<int>(n, 0));
    
            for (int l = 2; l < n; l++) 
            {   // l is the chain length
                for (int i = 1; i < n - l + 1; i++) 
                {
                    int j = i + l - 1;
                    dp[i][j] = INT_MAX;
                  
                    for (int k = i; k < j; k++) 
                    {
                        int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                      
                        if (cost < dp[i][j]) 
                        {
                            dp[i][j] = cost;
                        }
                    }
                }
            }
    
            return dp[1][n-1];    
        }
};

// Driver Code
int main() 
{
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
  
    while (t--) 
    {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
      
        while (ss >> num)
        {
            a.push_back(num);
        }

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication/1/
