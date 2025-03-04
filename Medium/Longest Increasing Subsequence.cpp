#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int lis(vector<int>& arr) 
        {
            vector<int> dp; // This will store the smallest tail for increasing subsequences
            
            for (int num : arr) 
            {
                // Use binary search to find the position of num in dp
                auto it = lower_bound(dp.begin(), dp.end(), num);
              
                if (it == dp.end()) 
                {
                    // If num is greater than all elements in dp, append it
                    dp.push_back(num);
                } 
                
                else 
                {
                    // Otherwise, replace the found position with num
                    *it = num;
                }
            }
            
            // The size of dp will be the length of the longest increasing subsequence
            return dp.size();
        }
};

// Driver code
int main() 
{
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) 
    {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
      
        while (ss >> num)
        {
            arr.push_back(num);
        }

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/longest-increasing-subsequence/1/
