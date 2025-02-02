class Solution:
    def isWordExist(self, mat, word):
        def dfs(i, j, k):
            if k == len(word):
                return True
            if not (0 <= i < n and 0 <= j < m and mat[i][j] == word[k]):
                return False
            c = mat[i][j]
            mat[i][j] = "0"
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                if dfs(i + dx, j + dy, k + 1):
                    return True
            mat[i][j] = c
            return False
        
        n, m = len(mat), len(mat[0])
        return any(dfs(i, j, 0) for i in range(n) for j in range(m))

# Link to the problem: https://www.geeksforgeeks.org/problems/word-search/1/
