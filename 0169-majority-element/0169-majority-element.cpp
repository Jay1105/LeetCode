class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        
        int res = 0;
        map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second > n / 2)
            {
                res = it->first;
                break;
            }
        }
        
        return res;
    }
};