#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<double> getMedian(vector<int> &arr) 
        {
            // Max-heap for the lower half
            priority_queue<int> maxHeap;
            // Min-heap for the upper half
            priority_queue<int, vector<int>, greater<int>> minHeap;
            
            vector<double> medians;
    
            for (int num : arr) 
            {
                // Add the new number to the max-heap
                maxHeap.push(num);
    
                // Ensure the largest number in maxHeap is less than or equal to the smallest in minHeap
                if (!minHeap.empty() && maxHeap.top() > minHeap.top()) 
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
    
                // Balance the sizes of the heaps
                if (maxHeap.size() > minHeap.size() + 1) 
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                } 
                
                else if (minHeap.size() > maxHeap.size()) 
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
    
                // Calculate the median
                if (maxHeap.size() > minHeap.size()) 
                {
                    medians.push_back(maxHeap.top());
                } 
                
                else 
                {
                    medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
                }
            }    
            return medians;
        }
};

int main() 
{
    int t;
    cin >> t;
    cin.ignore();
  
    while (t--) 
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
      
        while (ss >> num) 
        {
            nums.push_back(num);
        }
      
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
      
        for (auto &i : ans)
        {
            cout << i << " ";
        }
      
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1/
