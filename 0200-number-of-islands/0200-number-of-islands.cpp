class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid) {
        grid[r][c] = '2';
        if (r > 0 && grid[r - 1][c] == '1')
            dfs(r - 1, c, grid);
        if (r < grid.size() - 1 && grid[r + 1][c] == '1')
            dfs(r + 1, c, grid);
        if (c > 0 && grid[r][c - 1] == '1')
            dfs(r, c - 1, grid);
        if (c < grid[0].size() - 1 && grid[r][c + 1] == '1')
            dfs(r, c + 1, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return islands;
    }
};