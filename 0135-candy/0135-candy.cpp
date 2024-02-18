class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = n;
        
        int up = 0, down = 0, peak = 0;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                down = 0;
                up += 1;
                res += up;
                peak = up;
            }
            else if (ratings[i] == ratings[i - 1])
            {
                up = 0;
                down = 0;
                peak = 0;
            }
            else
            {
                up = 0;
                down += 1;
                res += down;
                if (peak >= down)
                    res--;
            }
        }
        return res;
    }
};