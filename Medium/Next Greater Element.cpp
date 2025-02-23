#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<int> nextLargerElement(vector<int>& arr) 
        {
            int n = arr.size();
            vector<int> result(n, -1); // Initialize result array with -1
            stack<int> stk; // Stack to store indices
    
            for (int i = 0; i < n; i++) 
            {
                // While stack is not empty and the current element is greater than
                // the element at the index stored at the top of the stack
                while (!stk.empty() && arr[i] > arr[stk.top()]) 
                {
                    result[stk.top()] = arr[i]; // Set the next greater element
                    stk.pop(); // Remove the index from the stack
                }
              
                stk.push(i); // Push the current index onto the stack
            }
    
            return result; // Return the result array
        }
};

int main() 
{
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
  
    while (t--) 
    {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
      
        while (ss >> num)
        {
            a.push_back(num); // Read the array elements from input string
        }

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) 
        {
            if (i != 0)
            {
                cout << " ";
            }
            
            cout << result[i];
        }
      
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1/
