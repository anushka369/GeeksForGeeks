#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        // Helper function for DFS
        bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) 
        {
            visited[node] = true; // Mark the current node as visited
            
            for (int neighbor : adj[node]) 
            {
                if (!visited[neighbor]) 
                {
                    // If the neighbor is not visited, recurse on it
                    if (dfs(neighbor, node, adj, visited)) 
                    {
                        return true; // Cycle found
                    }
                  
                }
                
                else if (neighbor != parent) 
                {
                    // If the neighbor is visited and is not the parent, we found a cycle
                    return true;
                }
            }
          
            return false; // No cycle found in this path
        }
    
        // Main function to check for cycles in the graph
        bool isCycle(int V, vector<vector<int>>& edges) 
        {
            // Create an adjacency list
            vector<vector<int>> adj(V);
          
            for (const auto& edge : edges) 
            {
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u); // Since the graph is undirected
            }
    
            vector<bool> visited(V, false); // Initialize visited array
            
            // Check for cycles in different components
            for (int i = 0; i < V; i++) 
            {
                if (!visited[i]) 
                {
                    if (dfs(i, -1, adj, visited)) 
                    {
                        return true; // Cycle found
                    }
                }
            }
            
            return false; // No cycle found
        }
};

// Driver Code
int main() 
{
    int tc;
    cin >> tc;
    cin.ignore();
  
    while (tc--) 
    {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
      
        for (int i = 1; i <= E; i++) 
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
        {
            cout << "true\n";
        }
          
        else
        {
            cout << "false\n";
        }

        cout << "~" << "\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/
