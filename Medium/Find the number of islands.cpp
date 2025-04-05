#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) 
        {
            // Check for out of bounds or if the cell is water
            if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 'W')
            {
                return;
            }
            
            // Mark the cell as visited by changing 'L' to 'W'
            grid[i][j] = 'W';
            
            // Explore all 8 possible directions
            for (int x = -1; x <= 1; x++) 
            {
                for (int y = -1; y <= 1; y++) 
                {
                    if (x != 0 || y != 0) 
                    {   // Skip the current cell
                        dfs(grid, i + x, j + y, n, m);
                    }
                }
            }
        }
        
        int countIslands(vector<vector<char>>& grid) 
        {
            int n = grid.size();
            int m = grid[0].size();
            int islandCount = 0;
            
            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < m; j++) 
                {
                    if (grid[i][j] == 'L') 
                    {
                        // Found an unvisited land cell, start DFS
                        dfs(grid, i, j, n, m);
                        islandCount++;
                    }
                }
            }
            
            return islandCount;
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
        vector<vector<char>> grid(n, vector<char>(m, '#'));
      
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                cin >> grid[i][j];
            }
        }
      
        Solution obj;
        int ans = obj.countIslands(grid);
      
        cout << ans << '\n';
        cout << "~" << "\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1/
