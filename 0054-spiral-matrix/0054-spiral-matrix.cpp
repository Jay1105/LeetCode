class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int rowStart = 0, colStart = 0;
        int rowEnd = matrix.size() - 1, colEnd = matrix[0].size() - 1;
        
        while (true)
        {
            for (int i = colStart; i <= colEnd; i++)
                ans.push_back(matrix[rowStart][i]);
            rowStart++;
            
            if (rowStart > rowEnd)
                break;
            
            for (int i = rowStart; i <= rowEnd; i++)
                ans.push_back(matrix[i][colEnd]);
            colEnd--;
            
            if (colEnd < colStart)
                break;
            
            for (int i = colEnd; i >= colStart; i--)
                ans.push_back(matrix[rowEnd][i]);
            rowEnd--;
            
            if (rowEnd < rowStart)
                break;
            
            for (int i = rowEnd; i >= rowStart; i--)
                ans.push_back(matrix[i][colStart]);
            colStart++;
            
            if (colStart > colEnd)
                break;
        }
        
        return ans;
    }
};