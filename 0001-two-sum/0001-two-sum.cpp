class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++)
        {
            a[i].first = nums[i];
            a[i].second = i;
        }

        sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b)
        {
            return a.first < b.first;
        });

        int l = 0, r = n - 1, idx1, idx2;

        while (1)
        {
            int sum = a[l].first + a[r].first;

            if (sum == target)
            {
                idx1 = a[l].second, idx2 = a[r].second;
                break;
            }
            else if (target > sum)
                l++;
            else
                r--;
        }

        vector<int> ans;
        ans.push_back(idx1);
        ans.push_back(idx2);

        return ans;
    }
};