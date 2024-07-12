class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        board[r][c] = 'A';

        if (r > 0 && board[r - 1][c] == 'O')
            dfs(r - 1, c, board);
        if (r < board.size() - 1 && board[r + 1][c] == 'O')
            dfs(r + 1, c, board);
        if (c > 0 && board[r][c - 1] == 'O')
            dfs(r, c - 1, board);
        if (c < board[0].size() - 1 && board[r][c + 1] == 'O')
            dfs(r, c + 1, board);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfs(0, i, board);
            if (board[n - 1][i] == 'O')
                dfs(n - 1, i, board);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};