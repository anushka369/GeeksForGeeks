#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution 
{
    public:
        int solve(vector<int>& arr, int n)
        {
            if (n == 1) 
            {
                return arr[0];
            }
          
            if (n == 2) 
            {
                return max(arr[0], arr[1]);
            }
          
            int prev = arr[0];
            int sprev = 0;
            int ans = 0;
          
            for(int i = 1; i < n; i++)
            {
                ans = max(prev, sprev + arr[i]);
                sprev = prev;
                prev = ans;
            }
          
            return ans;            
        }

        int findMaxSum(vector<int>& arr) 
        {
            int n = arr.size();
            return solve(arr, n);            
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/stickler-theif/1/
