class Solution {
public:
    int kadane (vector<int> nums)
    {
        int mx = INT_MIN;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            mx = max(mx, sum);
            
            if (sum < 0)
                sum = 0;
        }
        
        return mx;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int nonWrapSum = kadane(nums);
        
        int totalSum = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                cnt++;
            
            totalSum += nums[i];
            nums[i] = -nums[i];
        }
        
        
        int wrapSum = INT_MIN;
        
        if (cnt < nums.size())
            wrapSum = totalSum + kadane(nums);
        
        return max(nonWrapSum, wrapSum);
    }
};