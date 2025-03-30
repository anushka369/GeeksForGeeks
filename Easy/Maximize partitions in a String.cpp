#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int maxPartitions(string &s) 
        {
            // Step 1: Track the last occurrence of each character
            vector<int> last(26, -1);
            for (int i = 0; i < s.size(); i++) 
            {
                last[s[i] - 'a'] = i;
            }
    
            int partitions = 0;
            int lastPartitionEnd = 0;
    
            // Step 2: Iterate through the string
            for (int i = 0; i < s.size(); i++) 
            {
                lastPartitionEnd = max(lastPartitionEnd, last[s[i] - 'a']);
                
                // Step 3: When we reach the end of a partition
                if (i == lastPartitionEnd) 
                {
                    partitions++;  // Increment the partition count
                }
            }
    
            return partitions;
        }
};


// Driver Code
int main() 
{
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) 
    {
        string s;
        cin >> s;
      
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
      
        cout << "~" << endl;
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1/
