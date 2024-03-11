class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b)
             {
                 return a[0] < b[0];
             });
        
        vector<vector<int>> ans;
        int idx1 = intervals[0][0], idx2 = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (idx2 >= intervals[i][0] && intervals[i][1] >= idx1)
            {
                idx1 = min(idx1, intervals[i][0]);
                idx2 = max(idx2, intervals[i][1]);
            }
            else
            {
                ans.insert(ans.end(), {idx1, idx2});                
                idx1 = intervals[i][0], idx2 = intervals[i][1];
            }
        }
        ans.insert(ans.end(), {idx1, idx2});    
        
        return ans;
    }
};