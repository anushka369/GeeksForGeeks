#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int> &prices) 
        {
            int n = prices.size();
          
            if (n == 0) 
            {
                return 0;
            }
    
            // Variables to store the maximum profit
            int firstBuy = INT_MIN, firstSell = 0;
            int secondBuy = INT_MIN, secondSell = 0;
    
            for (int price : prices) 
            {
                // Update the first buy and sell
                firstBuy = max(firstBuy, -price); // Buy at current price
                firstSell = max(firstSell, firstBuy + price); // Sell at current price
    
                // Update the second buy and sell
                secondBuy = max(secondBuy, firstSell - price); // Buy at current price after first sell
                secondSell = max(secondSell, secondBuy + price); // Sell at current price
            }
    
            // The maximum profit will be the profit from the second sell
            return secondSell;
        }
};

// Driver code
int main() 
{
    int t;
    cin >> t;
    cin.ignore();
  
    while (t--) 
    {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
      
        while (ss >> number) 
        {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);
        cout << res << endl << "~" << endl;
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1/
