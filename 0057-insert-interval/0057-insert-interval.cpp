class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n = intervals.size();
        vector<vector<int>> res;

        if (n == 0)
        {
            res.push_back(newInterval);
            return res;
        }
        
        int idx = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (intervals[i + 1][0] > newInterval[0])
                break;
            idx = i + 1;
        }

        for (int i = 0; i < idx; i++)
            res.push_back(intervals[i]);
        
        int a, b;
        if (newInterval[0] <= intervals[idx][0])
        {
            a = newInterval[0], b = newInterval[1];
            if (b >= intervals[idx][0] && intervals[idx][1] >= a)
            {
                a = min(a, intervals[idx][0]);
                b = max(b, intervals[idx][1]);
            }
            else
            {
                res.insert(res.end(), {a, b});
                a = intervals[idx][0], b = intervals[idx][1];
            }
        }
        else
        {
            a = intervals[idx][0], b = intervals[idx][1];
            if (b >= newInterval[0] && newInterval[1] >= a)
            {
                a = min(a, newInterval[0]);
                b = max(b, newInterval[1]);
            }
            else
            {
                res.insert(res.end(), {a, b});
                a = newInterval[0], b = newInterval[1];
            }
        }       

        for (int i = idx + 1; i < n; i++)
        {
            if (b >= intervals[i][0] && intervals[i][1] >= a)
            {
                a = min(a, intervals[i][0]);
                b = max(b, intervals[i][1]);
            }
            else
            {
                res.insert(res.end(), {a, b});
                a = intervals[i][0], b = intervals[i][1];
            }
        }
        res.insert(res.end(), {a, b});
        return res;
    }
};