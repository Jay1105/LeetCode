class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int num = mat.size() * (mat[0].size());
        
        if (r * c != num)
        {
            return mat;
        }
        else
        {
            vector<vector<int>> ans(r, vector<int> (c));
            vector<int> help;
            for (int i = 0; i < mat.size(); i++)
            {
                for (int j = 0; j < mat[i].size(); j++)
                {
                    help.push_back(mat[i][j]);
                }
            }
            
            int cnt = 0;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    ans[i][j] = help[cnt];
                    cnt++;
                }
            }
            
            return ans;
        }
    }
};