class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        map<string, int> vis;
        vector<pair<int, int> > zeros;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                    zeros.push_back(make_pair(i, j));
            }
        }
        
        for (int i = 0; i < zeros.size(); i++)
        {
            int row = zeros[i].first;
            int col = zeros[i].second;
            
            for (int k = 0; k < m; k++)
                matrix[row][k] = 0;
            for (int k = 0; k < n; k++)
                matrix[k][col] = 0;
        }
    }
};