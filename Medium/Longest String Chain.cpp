#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int longestStringChain(vector<string>& words) 
        {
            // Sort words by their lengths
            sort(words.begin(), words.end(), [](const string &a, const string &b) 
            {
                return a.length() < b.length();
            });
            
            unordered_map<string, int> dp; // dp[word] = longest chain ending with word
            int maxLength = 1; // At least one word can be a chain by itself
            
            for (const string &word : words) 
            {
                dp[word] = 1; // Initialize the chain length for the current word
                
                // Try to form predecessors by removing one character
                for (int i = 0; i < word.length(); ++i) 
                {
                    string predecessor = word.substr(0, i) + word.substr(i + 1);
                    
                    // If the predecessor exists in dp, we can form a chain
                    if (dp.find(predecessor) != dp.end()) 
                    {
                        dp[word] = max(dp[word], dp[predecessor] + 1);
                    }
                }
                
                // Update the maximum length found
                maxLength = max(maxLength, dp[word]);
            }
            
            return maxLength;
        }
};

int main() 
{
    int t;
    cin >> t;
    cin.ignore();
  
    while (t--) 
    {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
      
        while (ss >> number) 
        {
            words.push_back(number);
        }
      
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~" << "\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/longest-string-chain/1.
