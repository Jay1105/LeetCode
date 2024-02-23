class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        
        int low = 0;
        int high = numbers.size() - 1;
        
        bool flag = false;
        while (low < high)
        {
            int mid = numbers[low] + numbers[high];
            
            if (mid == target)
            {
                flag = true;
                break;
            }
            else if (mid > target)
                high--;
            else
                low++;
        }
        
        ans[0] = ++low;
        ans[1] = ++high;
        
        return ans;
    }
};