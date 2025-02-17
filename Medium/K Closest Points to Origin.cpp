#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
        {
            // Max-heap to store the k closest points
            priority_queue<pair<int, vector<int>>> maxHeap;
    
            for (const auto& point : points) 
            {
                int distance = point[0] * point[0] + point[1] * point[1]; // Squared distance
    
                // Push the current point into the max-heap
                maxHeap.push({distance, point});
    
                // If the heap size exceeds k, remove the farthest point
                if (maxHeap.size() > k) 
                {
                    maxHeap.pop();
                }
            }
    
            // Prepare the result vector
            vector<vector<int>> result;
            while (!maxHeap.empty()) 
            {
                result.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
    
            return result;
        }
};

int main() 
{
    int t;
    cin >> t;
  
    while (t--)
    {
        int k;
        cin >> k;
        int n;
        cin >> n;
      
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) 
        {
            cin >> points[i][0] >> points[i][1];
        }
      
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
      
        for (const vector<int>& point : ans) 
        {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1/
