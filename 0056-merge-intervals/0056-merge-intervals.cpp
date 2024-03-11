class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int m = intervals[0].size();
        
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b)
             {
                 return a[0] < b[0];
             });
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        int idx1 = intervals[0][0], idx2 = intervals[0][1];
        
        for (int i = 1; i < n; i++)
        {
            if (idx2 >= intervals[i][0] && intervals[i][1] >= idx1)
            {
                idx1 = min(idx1, intervals[i][0]);
                idx2 = max(idx2, intervals[i][1]);
            }
            else
            {
                temp.push_back(idx1);
                temp.push_back(idx2);
                ans.push_back(temp);
                temp.clear();
                
                idx1 = intervals[i][0], idx2 = intervals[i][1];
            }
        }
        temp.push_back(idx1);
        temp.push_back(idx2);
        ans.push_back(temp);
        
        return ans;
    }
};