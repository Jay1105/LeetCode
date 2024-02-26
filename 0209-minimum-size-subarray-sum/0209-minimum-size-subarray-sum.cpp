class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int res = 0;
        int tp = 0;
        
        int low = 0, high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int sum = 0;
            int mx = 0;
            for (int i = 0; i < n; i++)
            {
                if (i < mid)
                {
                    sum += nums[i];
                    mx = sum;
                }
                else
                {
                    sum = sum - nums[i - mid] + nums[i];
                    mx = max(mx, sum);
                }
                if (mx >= target)
                    break;
            }
            if (mx >= target)
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
};