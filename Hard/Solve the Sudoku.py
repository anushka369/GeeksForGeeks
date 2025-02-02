class Solution:    
    def solveSudoku(self, mat):
        def dfs(k):
            nonlocal ok
            if k == len(t):
                ok = True
                return
            i, j = t[k]
            for v in range(9):
                if row[i][v] == col[j][v] == block[i // 3][j // 3][v] == False:
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
                    mat[i][j] = v + 1
                    dfs(k + 1)
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = False
                if ok:
                    return

        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        block = [[[False] * 9 for _ in range(3)] for _ in range(3)]
        t = []
        ok = False
        for i in range(9):
            for j in range(9):
                if mat[i][j] == 0:
                    t.append((i, j))
                else:
                    v = mat[i][j] - 1
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
        dfs(0)

# Link to the problem: https://www.geeksforgeeks.org/problems/solve-the-sudoku/1/
