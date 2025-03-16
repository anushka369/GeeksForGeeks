#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int minJumps(vector<int>& arr) 
        {
            int n = arr.size();
            if (n <= 1)
            {
                return 0; // No jumps needed if there's only one element
            }
          
            if (arr[0] == 0) 
            {
                return -1; // Can't move anywhere from the first element
            }
    
            int jumps = 0; // Number of jumps made
            int currentEnd = 0; // End of the current jump range
            int farthest = 0; // Farthest point that can be reached
    
            for (int i = 0; i < n - 1; i++) 
            {
                // Update the farthest point that can be reached
                farthest = max(farthest, i + arr[i]);
    
                // If we have come to the end of the current jump range
                if (i == currentEnd) 
                {
                    jumps++; // We need to make a jump
                    currentEnd = farthest; // Update the end of the current jump range
    
                    // If the current end can reach or exceed the last index
                    if (currentEnd >= n - 1) 
                    {
                        return jumps; // Return the number of jumps
                    }
                }
    
                // If we can't move forward anymore
                if (i >= farthest) 
                {
                    return -1; // Can't reach the end
                }
            }
    
            return -1; // In case we exit the loop without reaching the end
        }
};

// Driver Code
int main() 
{
    int t;
    cin >> t;
    cin.ignore();
  
    while (t--) 
    {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) 
        {
            arr.push_back(number);
        }
      
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/minimum-number-of-jumps/1/
