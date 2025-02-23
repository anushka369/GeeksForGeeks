#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<int> calculateSpan(vector<int>& arr) 
        {
            int n = arr.size();
            vector<int> span(n); // To store the span values
            stack<int> stk; // Stack to store indices
    
            for (int i = 0; i < n; i++) 
            {
                // Pop elements from the stack while the current price is greater than or equal to
                // the price at the index stored at the top of the stack
                while (!stk.empty() && arr[i] >= arr[stk.top()]) 
                {
                    stk.pop();
                }
    
                // If the stack is empty, it means the current price is greater than all previous prices
                if (stk.empty()) 
                {
                    span[i] = i + 1; // Span is the current index + 1
                } 
                
                else 
                {
                    // Otherwise, the span is the difference between the current index and the index at the top of the stack
                    span[i] = i - stk.top();
                }
    
                // Push the current index onto the stack
                stk.push(i);
            }    
            return span; // Return the span values
        }
};

int main() 
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
  
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
      
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
      
        for (int i = 0; i < ans.size(); i++) 
        {
            cout << ans[i] << " ";
        }
      
        cout << endl;
        cout << "~" << endl;
    }

    return 0;


// Link to the problem: https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/
