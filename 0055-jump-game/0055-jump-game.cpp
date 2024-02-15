class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int zi = -1;
        
        if (n == 1)
            return true;
        
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                zi = i;
                break;
            }
        }
        
        if (zi == -1)
            return true;
        
        int k = 1;
        bool ans = false;
        for (int i = zi - 1; i >= 0; i--, k++)
        {
            if (nums[i] > k)
                ans = true;
            else if (ans == true && nums[i] == 0)
            {
                ans = false;
                zi = i;
                k = 0;
            }
        }
        
        return ans;
    }
};