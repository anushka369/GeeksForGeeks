#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        // Function to return Breadth First Traversal of given graph.
        vector<int> bfs(vector<vector<int>> &adj) 
        {
            vector<int> result; // Stores the BFS traversal order
            int V = adj.size(); // Number of vertices
            vector<bool> visited(V, false); // Track visited nodes
            
            queue<int> q; // Queue for BFS
            q.push(0); // Start BFS from vertex 0
            visited[0] = true;
            
            while (!q.empty()) 
            {
                int node = q.front();
                q.pop();
                result.push_back(node);
                
                // Traverse neighbors in the order given in adjacency list
                for (int neighbor : adj[node]) 
                {
                    if (!visited[neighbor]) 
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
          
            return result;
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
        int V;
        cin >> V;
        cin.ignore();
      
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) 
        {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
          
            while (ss >> num) 
            {
                node.push_back(num);
            }
          
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
      
        for (int i = 0; i < ans.size(); i++) 
        {
            cout << ans[i] << " ";
        }
      
        cout << endl;
        cout << "~" << endl;
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/
