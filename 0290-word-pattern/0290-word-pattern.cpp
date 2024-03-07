class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> arr;
        string temp = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                arr.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
        }
        arr.push_back(temp);
        
        map<char, string> mp;
        map<char, string>:: iterator it;
        
        if (pattern.size() != arr.size())
            return false;
                
        for (int i = 0; i < pattern.size(); i++)
        {
            string tt = arr[i];
            if (mp[pattern[i]] == "")
            {
                for (it = mp.begin(); it != mp.end(); it++)
                {
                    if (it->second == tt)
                        return false;
                }
                mp[pattern[i]] = tt;
            }
            else if (mp[pattern[i]] != tt)
                return false;
        }

        return true;
    }
};
