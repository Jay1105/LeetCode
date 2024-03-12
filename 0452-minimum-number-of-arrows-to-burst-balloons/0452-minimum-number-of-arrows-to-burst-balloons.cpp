class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int m = 2;
        
        sort(points.begin(), points.end(), [&](vector<int> a, vector<int>b)
             {
                 return a[0] < b[0];
             });
        
        int idx1 = points[0][0], idx2 = points[0][1];
        int ans = n;

        for (int i = 1; i < n; i++)
        {
            if (points[i][0] <= idx2)
            {
                ans--;
                idx1 = points[i][0];
                idx2 = min(idx2, points[i][1]);
            }
            else
            {
                idx1 = points[i][0];
                idx2 = points[i][1];
                continue;
            }
        }
        return ans;
    }
};