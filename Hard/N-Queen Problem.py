class Solution:
    def nQueen(self, n):
        def dfs(i):
            if i == n:
                res.append([row.index("Q") + 1 for row in board])
                return
            for j in range(n):
                if col[j] + dg[i + j] + udg[n - i + j] == 0:
                    board[i][j] = "Q"
                    col[j] = dg[i + j] = udg[n - i + j] = 1
                    dfs(i + 1)
                    col[j] = dg[i + j] = udg[n - i + j] = 0
                    board[i][j] = "."

        res = []
        board = [["."] * n for _ in range(n)]
        col = [0] * n
        dg = [0] * (n << 1)
        udg = [0] * (n << 1)
        dfs(0)
        return res

# Link to the problem: https://www.geeksforgeeks.org/problems/n-queen-problem/1/
