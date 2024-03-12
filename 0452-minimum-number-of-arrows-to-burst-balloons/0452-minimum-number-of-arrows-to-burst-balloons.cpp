class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int i = 0; i < n; i++)
            pq.push(make_pair(points[i][0], points[i][1]));
        
        pair<int, int> temp = pq.top();
        pq.pop();

        int ans = n;
        int idx1 = temp.first, idx2 = temp.second;
        pair<int, int> temp2;

        while (!pq.empty())
        {
            temp2 = pq.top();
            if (temp2.first <= idx2)
            {
                ans--;
                idx1 = temp2.first;
                idx2 = min(idx2, temp2.second);
            }
            else
            {
                idx1 = temp2.first;
                idx2 = temp2.second;
            }
            pq.pop();
        }
        return ans;
    }
};
