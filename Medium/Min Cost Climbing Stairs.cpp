#include <bits/stdc++.h>
using namespace std;

// Back-end complete function Template for C++
class Solution 
{
    public:
        int minCostClimbingStairs(vector<int>& cost) 
        {
            int n = cost.size();
            
            // Base cases
            if (n == 2) 
            {
                return min(cost[0], cost[1]);
            }
            
            int first = cost[0];
            int second = cost[1];
            
            for (int i = 2; i < n; i++) 
            {
                int current = cost[i] + min(first, second);
                first = second;
                second = current;
            }
            
            return min(first, second);
        }
};

// Driver Code
int main() 
{
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) 
    {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
      
        while (ss >> num) 
        {
            arr.push_back(num);
        }
      
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1/
