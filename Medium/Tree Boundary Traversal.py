'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''

class Solution:
    def boundaryTraversal(self, root):
        if not root:
            return []
        
        result = [root.data]
        
        # Left Boundary
        self.leftBoundary(root.left, result)
        
        # Leaf Nodes
        self.leafNodes(root.left, result)
        self.leafNodes(root.right, result)
        
        # Right Boundary
        self.rightBoundary(root.right, result)
        
        return result
        
    def leftBoundary(self, node, result):
        if not node or (not node.left and not node.right):
            return 
        
        result.append(node.data)
        
        if node.left:
            self.leftBoundary(node.left, result)
        else:
            self.leftBoundary(node.right, result)
    
    def leafNodes(self, node, result):
        if not node:
            return
        
        if not node.left and not node.right:
            result.append(node.data)
            return
        
        self.leafNodes(node.left, result)
        self.leafNodes(node.right, result)
        
    def rightBoundary(self, node, result):
        if not node or (not node.left and not node.right):
            return
        
        if node.right:
            self.rightBoundary(node.right, result)
        else:
            self.rightBoundary(node.left, result)
            
        result.append(node.data)

# Link to the problem: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/
