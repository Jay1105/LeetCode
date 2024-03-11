class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        if (nums.size() == 0)
            return ans;
        
        string temp;
        int idx1 = 0, idx2 = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
                idx2 = i;
            else
            {
                if (idx1 < idx2)
                {
                    temp = to_string(nums[idx1]) + "->" + to_string(nums[idx2]);
                    ans.push_back(temp);
                }
                else
                    ans.push_back(to_string(nums[idx1]));
                idx1 = i, idx2 = i;
            }
        }
        
        if (idx1 < idx2)
        {
            temp = to_string(nums[idx1]) + "->" + to_string(nums[idx2]);
            ans.push_back(temp);
        }
        else
        {
            temp = to_string(nums[idx1]);
            ans.push_back(temp);
        }
        
        return ans;
    }
};