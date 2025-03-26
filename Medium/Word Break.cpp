#include <bits/stdc++.h>
using namespace std;

struct Trie 
{
    Trie* arr[26];
    bool isEnd = false;
    
    Trie() 
{
        for (int i = 0; i < 26; i++)
        {
            arr[i] = nullptr;
        }
  
        isEnd = false;
    }
};

Trie* root = new Trie();
void insert (string& str) 
{
    Trie* node = root;
    for (int i = 0; i < str.length(); i++) 
    {
        int idx = str[i] - 'a';
        if (node -> arr[idx] == nullptr)
        {
            node -> arr[idx] = new Trie();
        }
      
        node = node -> arr[idx];
    }
  
    node -> isEnd = true;
}

bool search(string& str) 
{
    Trie* node = root;
    for (int i = 0; i < str.length(); ++i) 
    {
        int idx = str[i] - 'a';
        if (node -> arr[idx] != nullptr)
        {
            node = node -> arr[idx];
        }
    }
  
    return node -> isEnd;
}

class Solution 
{
    public:
        int fun(int i, string &s, set<string> &st, vector<int> &dp)
        {
            if (i == s.size())
            {
                return 1;
            }
          
            if (dp[i] != -1)
            {
                return dp[i];
            }
            
            string temp = "";
            for (int j = i; j < s.size(); j++)
            {
                temp += s[j];
                if (st.find(temp) != st.end())
                {
                    if (fun(j + 1, s, st, dp))
                    {
                        return dp[i] = 1;
                    }
                }
            }
          
            return dp[i] = 0;    
        }
    
    bool wordBreak(string &s, vector<string> &dic) 
    {
        int n = s.size();
        vector<int> dp(n  +  1, -1);
        set<string> st;
        for (auto z : dic)
        {
            st.insert(z);
        }
        
        return fun(0, s, st, dp);
    }
};

// Driver Code
vector<string> inputLine() 
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
  
    while (ss >> str) 
    {
        res.push_back(str);
    }
  
    return res;
}

int main() 
{
    int t;
    cin >> t;
    cin.ignore();
  
    while (t--) 
    {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) 
        {
            cout << "true\n";
        } 
        
        else
        {
            cout << "false\n";
        }
      
        cout << "~" << "\n";
    }
}

// Link to the problem: https://www.geeksforgeeks.org/problems/word-break/1/
