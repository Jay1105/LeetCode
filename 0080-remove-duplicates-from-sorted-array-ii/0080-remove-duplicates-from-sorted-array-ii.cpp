class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        
        map<int, int>::iterator it;
        int index = 0;
        
        for (it = freq.begin(); it != freq.end(); it++)
        {
            if (it->second == 1)
            {
                nums[index++] = it->first;
            }
            else
            {
                nums[index++] = it->first;
                nums[index++] = it->first;
            }
        }
        return index;
    }
};