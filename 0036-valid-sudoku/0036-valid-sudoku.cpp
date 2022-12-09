class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool f1 = 1;
        vector<int> a(10, 0);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f1 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
            for (int i = 0; i < 10; i++)
                a[i] = 0;
        }
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;

        bool f2 = 1;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    if (a[board[j][i] - '0'])
                    {
                        f2 = 0;
                        break;
                    }
                    a[board[j][i] - '0'] = 1;
                }
            }
            for (int i = 0; i < 10; i++)
                a[i] = 0;
        }
        
        bool f3 = 1;
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f3 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
        }
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f3 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
        }
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f3 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
        }
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 3; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f3 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
        }
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 3; i < 6; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f3 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
        }
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 3; i < 6; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f3 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
        }
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 6; i < 9; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f3 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
        }
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 6; i < 9; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f3 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
        }
        
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 6; i < 9; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (a[board[i][j] - '0'])
                    {
                        f3 = 0;
                        break;
                    }
                    a[board[i][j] - '0'] = 1;
                }
            }
        }
        
        if (f1 && f2 && f3)
            return true;
        else
            return false;
    }
};