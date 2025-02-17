#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<int> kLargest(vector<int>& arr, int k) 
        {
            // Create a min-heap
            priority_queue<int, vector<int>, greater<int>> minHeap;
    
            // Iterate through the array
            for (int num : arr) 
            {
                minHeap.push(num); // Add the current number to the heap
                if (minHeap.size() > k) 
                {
                    minHeap.pop(); // Remove the smallest element if size exceeds k
                }
            }
    
            // Extract elements from the heap into a vector
            vector<int> result;
            while (!minHeap.empty()) 
            {
                result.push_back(minHeap.top());
                minHeap.pop();
            }
    
            // Reverse the result to get it in decreasing order
            reverse(result.begin(), result.end());
            return result;
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
      
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
      
        for (auto it : ans) 
        {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/k-largest-elements4206/1/
