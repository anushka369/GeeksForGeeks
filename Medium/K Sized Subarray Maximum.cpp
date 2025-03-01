#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<int> maxOfSubarrays(vector<int>& arr, int k) 
        {
            vector<int> result; // To store the maximums of each subarray
            deque<int> dq; // Deque to store indices of array elements
    
            for (int i = 0; i < arr.size(); i++) 
            {
                // Remove indices that are out of the current window
                if (!dq.empty() && dq.front() < i - k + 1) 
                {
                    dq.pop_front();
                }
    
                // Remove elements from the back of the deque while the current element is greater
                while (!dq.empty() && arr[dq.back()] < arr[i]) 
                {
                    dq.pop_back();
                }
    
                // Add the current index to the deque
                dq.push_back(i);
    
                // If we have processed at least k elements, add the maximum to the result
                if (i >= k - 1) 
                {
                    result.push_back(arr[dq.front()]); // The front of the deque is the maximum for the current window
                }
            }
    
            return result; // Return the result vector
        }
};

int main() 
{
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) 
    {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
      
        while (ss >> value) 
        {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
      
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
      
        cout << endl;
        cout << "~" << "\n";
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/1/
