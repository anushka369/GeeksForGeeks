#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int orangesRotting(vector<vector<int>>& mat) 
        {
            int n = mat.size();
            int m = mat[0].size();
            queue<pair<int, int>> q;
            int freshCount = 0;
    
            // Initialize the queue with all rotten oranges and count fresh oranges
            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < m; j++) 
                {
                    if (mat[i][j] == 2) 
                    {
                        q.push({i, j});
                    } 
                    
                    else if (mat[i][j] == 1) 
                    {
                        freshCount++;
                    }
                }
            }
    
            // Directions for up, down, left, right
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            int time = 0;
    
            // BFS
            while (!q.empty() && freshCount > 0) 
            {
                int size = q.size();
              
                for (int i = 0; i < size; i++) 
                {
                    pair<int, int> current = q.front();
                    q.pop();
                  
                    int x = current.first;
                    int y = current.second;
    
                    // Check all four directions
                    for (auto direction : directions) 
                    {
                        int newX = x + direction.first;
                        int newY = y + direction.second;
    
                        // If the new position is valid and has a fresh orange
                        if (newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] == 1) 
                        {
                            mat[newX][newY] = 2; // Rot the fresh orange
                            freshCount--; // Decrease the count of fresh oranges
                            q.push({newX, newY}); // Add to the queue
                        }
                    }
                }
              
                time++; // Increment time after processing one level
            }
    
            // If there are still fresh oranges left, return -1
            return freshCount == 0 ? time : -1;
        }
};

// Driver Code
int main() 
{
    int tc;
    cin >> tc;
  
    while (tc--) 
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
      
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                cin >> mat[i][j];
            }
        }
      
        Solution obj;
        int ans = obj.orangesRotting(mat);
      
        cout << ans << "\n";
        cout << "~" << "\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/rotten-oranges/1/
