#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<int> dfs(vector<vector<int>>& adj) 
        {
            // Code here
            
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
      
        vector<vector<int>> adj(V); // Use vector of vectors instead of array of vectors.

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
        vector<int> ans = obj.dfs(adj);
      
        for (int i = 0; i < ans.size(); i++) 
        {
            cout << ans[i] << " ";
        }
      
        cout << endl;
        cout << "~" << endl;
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/
