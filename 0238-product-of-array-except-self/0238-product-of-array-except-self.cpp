class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        int ans = 1;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                flag++;
            else
                ans *= nums[i];
        }
        
        if (flag > 1)
            ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                res[i] = ans;
            else if (flag > 0)
                res[i] = 0;
            else
                res[i] = ans / nums[i];
        }
        
        return res;
    }
};