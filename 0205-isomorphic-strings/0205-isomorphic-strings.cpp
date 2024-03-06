class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        map<char, char>::iterator it;

        for (int i = 0; i < s.size(); i++)
        {
            if (!mp[s[i]])
            {
                for (it = mp.begin(); it != mp.end(); it++)
                {
                    if (t[i] == it->second)
                        return false;
                }
                mp[s[i]] = t[i];
            }
            else if (mp[s[i]] != t[i])
                return false;
        }
        return true;
    }
};