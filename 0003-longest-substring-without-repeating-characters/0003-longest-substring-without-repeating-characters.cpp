class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.size();
        
        if (n < 2)
            return n;
        
        map<char, int> mp;        
        int curr = 0;
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            while (mp[s[i]] == 1)
            {
                curr -= 1;
                mp[s[j]] = 0;
                j++;
            }
            mp[s[i]] = 1;
            curr += 1;
            res = max(res, curr);
        }
        
        return res;
    }
};