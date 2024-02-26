class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        map<pair<int, int>, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int st = i + 1;
            int en = nums.size() - 1;
            
            while (st < en)
            {
                int sum = nums[i] + nums[st] + nums[en];
                if (sum == 0)
                {
                    pair<int, int> p = {nums[i], nums[st]};
                    if (!mp[p])
                    {
                        ans.push_back({nums[i], nums[st], nums[en]});
                        mp[p] = 1;
                    }
                    st++, en--;
                }
                else if (sum > 0)
                    en--;
                else
                    st++;
            }
        }
        
        return ans;
    }
};