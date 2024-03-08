class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        if (nums.size() == 0)
            return 0;
        
        map<int, int>::iterator it;
        int curr = 1;
        int res = 1;
        int prev = mp.begin()->first;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            if (it == mp.begin())
                continue;
            
            if (it->first - prev == 1)
                curr += 1;
            else
                curr = 1;
            res = max(res, curr);
            prev = it->first;
        }
        return res;
    }
};