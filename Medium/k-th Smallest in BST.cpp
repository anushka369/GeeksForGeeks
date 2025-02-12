/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution 
{
    public:
        void inorder(Node* root, int &k, int &ans)
        {
            if (!root) return ;
            inorder(root -> left, k, ans);
            k--;
          
            if (k == 0)
            {
                ans = root -> data;
                return ;
            }
            inorder(root -> right, k, ans);
        }
    
        int kthSmallest(Node *root, int k) 
        {
            int ans = -1;
            inorder(root, k, ans);
            return ans;
        }
};

// Link to the problem: https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1/
