class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> res(rows, vector<int>(cols));
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int alive = 0;
                
                if (i - 1 >= 0)
                    alive += board[i - 1][j];
                if (j - 1 >= 0)
                    alive += board[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0)
                    alive += board[i - 1][j - 1];
                
                if (i - 1 >= 0 && j + 1 < cols)
                    alive += board[i - 1][j + 1];
                if (i + 1 < rows && j - 1 >= 0)
                    alive += board[i + 1][j - 1];
                
                if (j + 1 < cols)
                    alive += board[i][j + 1];
                if (i + 1 < rows)
                    alive += board[i + 1][j];
                if (i + 1 < rows && j + 1 < cols)
                    alive += board[i + 1][j + 1];
                
                if (board[i][j] == 0 && alive == 3)
                    res[i][j] = 1;
                else if (board[i][j] == 1 && alive < 2)
                    res[i][j] = 0;
                else if (board[i][j] == 1 && alive > 3)
                    res[i][j] = 0;
                else
                    res[i][j] = board[i][j];
            }
        }
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                board[i][j] = res[i][j];
        }
    }
};