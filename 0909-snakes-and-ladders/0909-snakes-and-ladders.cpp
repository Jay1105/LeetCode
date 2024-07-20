class Solution {
public:
    pair<int, int> getPos(int cell, int n)
    {
        int row = (cell - 1) / n;
        int col = (cell - 1) % n;
        
        if (row & 1)
            col = n - 1 - col;
        row = n - 1 - row;
        
        return make_pair(row, col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        queue<int> q;
        vector<int> dist(n*n + 1, -1);
        dist[1] = 0;
        q.push(1);
        
        while (!q.empty())
        {
            int cell = q.front();
            q.pop();
            
            for (int i = cell + 1; i <= min(cell + 6, n*n); i++)
            {
                pair<int, int> pos = getPos(i, n);
                
                int dest = board[pos.first][pos.second] != -1 ? board[pos.first][pos.second] : i;
                
                if (dist[dest] == -1) {
                    dist[dest] = dist[cell] + 1;
                    q.push(dest);
                }
            }
        }
        
        return dist[n*n];
    }
};
