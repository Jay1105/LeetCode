class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        set<string> s;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                char temp = board[i][j];

                string trow = string(1,temp) + " found in row " + to_string(i);
                string tcol = string(1,temp) + " found in col " + to_string(j);
                string tbox = string(1,temp) + " found in box " + to_string(i / 3) + "-" + to_string(j / 3);

                if (!s.insert(trow).second ||
                    !s.insert(tcol).second ||
                    !s.insert(tbox).second)
                        return false;
            }
        }
        return true;
    }
};