class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        int ans = 1;
        for (int i = 0; i < n; i++)
            ans *= nums[i];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                int temp = 1;
                for (int j = 0; j < n; j++)
                {
                    if (j == i)
                        continue;
                    temp *= nums[j];
                }
                res[i] = temp;
            }
            else
                res[i] = ans / nums[i];
        }
        
        return res;
    }
};