#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int robLinear(vector<int>& arr) 
        {
            int n = arr.size();
            if (n == 0)
            {
                return 0;
            }
          
            if (n == 1) 
            {
                return arr[0];
            }
            
            vector<int> dp(n, 0);
            dp[0] = arr[0];
            dp[1] = max(arr[0], arr[1]);
            
            for (int i = 2; i < n; i++) 
            {
                dp[i] = max(dp[i-1], arr[i] + dp[i-2]);
            }
            
            return dp[n-1];
        }
        
        int maxValue(vector<int>& arr) 
{
            int n = arr.size();
            if (n == 1) 
            {
                return arr[0];
            }
            
            // Case 1: Exclude the last house
            vector<int> arr1(arr.begin(), arr.end() - 1);
            int max1 = robLinear(arr1);
            
            // Case 2: Exclude the first house
            vector<int> arr2(arr.begin() + 1, arr.end());
            int max2 = robLinear(arr2);
            
            return max(max1, max2);
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
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) 
        {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/house-robber-ii/1/
