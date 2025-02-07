'''
# Node class
class Node:
    def __init__(self,val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    def buildTree(self, inorder, preorder):
        # A dictionary to store the index of each value in inorder for quick access
        inorder_index_map = {value: index for index, value in enumerate(inorder)}
        
        # Recursive function to build the tree
        def build(pre_start, pre_end, in_start, in_end):
            if pre_start > pre_end or in_start > in_end:
                return None
            
            # The first element in the preorder slice is the root
            root_value = preorder[pre_start]
            root = Node(root_value)
            
            # Find the index of the root in the inorder array
            root_index = inorder_index_map[root_value]
            
            # Calculate the size of the left subtree
            left_subtree_size = root_index - in_start
            
            # Recursively build the left and right subtrees
            root.left = build(pre_start + 1, pre_start + left_subtree_size, in_start, root_index - 1)
            root.right = build(pre_start + left_subtree_size + 1, pre_end, root_index + 1, in_end)
            
            return root
        
        # Start the recursive building process
        return build(0, len(preorder) - 1, 0, len(inorder) - 1)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

class Node:

    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None


def printPostorder(n):
    if n is None:
        return
    printPostorder(n.left)
    printPostorder(n.right)
    print(n.data, end=' ')


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        inorder = [int(x) for x in input().split()]
        preorder = [int(x) for x in input().split()]

        root = Solution().buildTree(inorder, preorder)
        printPostorder(root)
        print()

# } Driver Code Ends

# Link to the problem: https://www.geeksforgeeks.org/problems/construct-tree-1/1/
