class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (!mp[nums[i]].empty())
            {
                int last = mp[nums[i]].back();
                
                if (abs(i - last) <= k)
                    return true;
            }
            mp[nums[i]].push_back(i);
        }
        return false;
    }
};