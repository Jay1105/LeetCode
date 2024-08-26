class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int tp = digits.size() - 1;
        
        while (tp >= 0 && digits[tp] == 9)
        {
            digits[tp] = 0;
            tp--;
        }
        
        if (tp < 0)
        {
            vector<int> ans;
            ans.push_back(1);
            ans.insert(ans.end(), digits.begin(), digits.end());
            
            return ans;
        }
        
        digits[tp] += 1;

        return digits;
    }
};