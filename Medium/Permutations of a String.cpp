class Solution 
{
    public:
        vector<string> findPermutation(string &s) 
        {
            vector<string> result;
            sort(s.begin(), s.end());
            backtrack(s, 0, result);
            return result;
        }

    private:
        void backtrack(string &s, int index, vector<string> &result) 
        {
            if (index == s.size()) 
            {
                result.push_back(s); 
                return;
            }
    
            unordered_set<char> used;
            for (int i = index; i < s.size(); i++) 
            {
                if (used.find(s[i]) != used.end()) 
                {
                    continue; 
                }
    
                used.insert(s[i]);
                swap(s[index], s[i]);       
                backtrack(s, index + 1, result);
                swap(s[index], s[i]);
            }
        }
};

// Link to the problem: https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1/
