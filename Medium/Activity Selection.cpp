#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>&a, const pair<int,int>&b) 
{
    return a.first < b.first; // Sort in ascending order
}

class Solution 
{
    public:
        int activitySelection(vector<int> &start, vector<int> &finish) 
        {
            vector <pair <int, int>> v;
          
            for (int i = 0; i < start.size(); i++)
            {
                v.push_back(make_pair(finish[i], start[i]));
            }
          
            sort(v.begin(), v.end(), cmp);
            int deadLine = -1, count = 0;
          
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].second > deadLine)
                {
                    deadLine = v[i].first;
                    count++;
                }
            }
          
            return count;
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
      
        while (ss >> num)
        {
            start.push_back(num);
        }
      
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
      
        while (ss >> num)
        {
            finish.push_back(num);
        }

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
  
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/activity-selection/1/
