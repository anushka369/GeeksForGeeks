#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int getMaxArea(vector<int> &arr) 
        {
            stack<int> stk; // Stack to store indices
            int maxArea = 0; // Variable to store the maximum area
            int n = arr.size();
    
            for (int i = 0; i < n; i++) 
            {
                // While the current bar is lower than the bar at the index stored at the top of the stack
                while (!stk.empty() && arr[i] < arr[stk.top()]) 
                {
                    int height = arr[stk.top()]; // Height of the bar
                    stk.pop(); // Pop the index
                    int width;

                    if (stk.empty()) 
                    {
                        width = i; // Width is the current index if stack is empty
                    } 
                    
                    else 
                    {
                        width = i - stk.top() - 1; // Width is the distance to the next smaller bar
                    }
                  
                    maxArea = max(maxArea, height * width); // Calculate area and update maxArea
                }
              
                stk.push(i); // Push the current index onto the stack
            }
    
            // Now pop the remaining bars from the stack
            while (!stk.empty()) 
            {
                int height = arr[stk.top()]; // Height of the bar
                stk.pop(); // Pop the index
                int width;
              
                if (stk.empty()) 
                {
                    width = n; // Width is the size of the array if stack is empty
                } 
                
                else 
                {
                    width = n - stk.top() - 1; // Width is the distance to the next smaller bar
                }
              
                maxArea = max(maxArea, height * width); // Calculate area and update maxArea
            }
    
            return maxArea; // Return the maximum area found
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/1/
