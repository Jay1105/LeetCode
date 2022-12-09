class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        bool f1 = 1;
        for (int i = 0; i < t.size(); i++)
        {
            if (--mp[t[i]] < 0)
            {
                f1 = 0;
                break;
            }
        }
        
        bool f2 = 1;
        for (auto it : mp)
        {
            if (it.second != 0)
            {
                f2 = 0;
                break;
            }
        }
        
        if (f1 && f2)
            return true;
        else
            return false;
    }
};