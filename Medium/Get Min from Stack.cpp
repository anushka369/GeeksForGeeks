#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
        stack<int> mainStack; // Stack to store the elements
        stack<int> minStack;  // Stack to store the minimum elements
    
    public:
        Solution() 
        {
            // Constructor
        }
    
        // Add an element to the top of Stack
        void push(int x) 
        {
            mainStack.push(x); // Push the element onto the main stack
            // Push onto the min stack if it's the first element or smaller than the current minimum
            if (minStack.empty() || x <= minStack.top()) 
            {
                minStack.push(x);
            }
        }
    
        // Remove the top element from the Stack
        void pop() 
        {
            if (mainStack.empty()) return; // If the stack is empty, do nothing
            // If the popped element is the minimum, pop it from the min stack as well
            if (mainStack.top() == minStack.top()) 
            {
                minStack.pop();
            }
            mainStack.pop(); // Pop from the main stack
        }
    
        // Returns top element of the Stack
        int peek() 
        {
            if (mainStack.empty()) 
            {
                return -1; // Return -1 if the stack is empty
            }
            return mainStack.top(); // Return the top element
        }
    
        // Finds minimum element of Stack
        int getMin() 
        {
            if (minStack.empty()) 
            {
                return -1; // Return -1 if the min stack is empty
            }
            return minStack.top(); // Return the minimum element
        }
};


//{ Driver Code Starts.

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int q;
        cin >> q;

        Solution ob;

        while (q--) 
        {
            int qt;
            cin >> qt;

            if (qt == 1) 
            {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } 
            
            else if (qt == 2) 
            {
                // pop
                ob.pop();
            } 
            
            else if (qt == 3) 
            {
                // peek
                cout << ob.peek() << " ";
            } 
            
            else if (qt == 4) 
            {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
      
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/
