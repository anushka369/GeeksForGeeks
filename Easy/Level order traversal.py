"""
class Node:
    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None
"""

class Solution:
    def levelOrder(self, root):
        ans = []
        
        if root is None:
            return ans
        q = deque([root])
        
        while q:
            t = []
            for _ in range(len(q)):
                node = q.popleft()
                t.append(node.data)
                
                if node.left:
                    q.append(node.left)
                    
                if node.right:
                    q.append(node.right)
            ans.append(t)
        return ans

# Link to the problem: https://www.geeksforgeeks.org/problems/level-order-traversal/1/
