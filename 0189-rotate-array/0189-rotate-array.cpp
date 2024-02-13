class Solution {
public:
    void reverse(vector<int>& nums, int start, int end)
    {
        int mid = (end - start) / 2;
        for (int i = 0; i <= mid; i++)
        {
            int temp = nums[start + i];
            nums[start + i] = nums[end - i];
            nums[end - i] = temp;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        if (k == 0)
            return;
        
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};