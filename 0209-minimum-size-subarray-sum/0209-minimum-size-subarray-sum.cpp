class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int j = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum - nums[j] >= target)
            {
                sum -= nums[j];
                j++;
            }
            if (sum >= target)
                res = min(res, i - j + 1);
        }
        
        int ans = (res == INT_MAX) ? 0 : res;
        return ans;
    }
};
