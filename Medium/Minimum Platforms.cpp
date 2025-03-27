#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        // Function to find the minimum number of platforms required at the railway station such that no train waits.
        int findPlatform(vector<int>& arr, vector<int>& dep)
        {
            // Sort both the arrival and departure arrays
            sort(arr.begin(), arr.end());
            sort(dep.begin(), dep.end());
            
            int n = arr.size();
            int plat_needed = 1;  // At least one platform is needed
            int result = 1;       // To store the result
            int i = 1;            // Pointer for arrival
            int j = 0;            // Pointer for departure
            
            // Traverse through all trains
            while (i < n && j < n) 
            {
                // If next train arrives before the last one departs
                if (arr[i] <= dep[j]) 
                {
                    plat_needed++;
                    i++;
                }
                  
                // If next train departs before the next one arrives
                else 
                {
                    plat_needed--;
                    j++;
                }
              
                // Update result if needed
                result = max(result, plat_needed);
            }
            
            return result;
        }
};

// Driver code
int main() 
{
    int t;
    cin >> t;
    cin.ignore();
  
    while (t--) 
    {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;      
        while (ss >> number) 
        {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) 
        {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);
      
        cout << endl;
        cout << "~\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/minimum-platforms/1/
