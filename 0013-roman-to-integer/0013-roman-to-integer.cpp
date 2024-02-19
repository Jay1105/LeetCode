class Solution {
public:
    map<char, int> priority;
    
    Solution()
    {
        priority['I'] = 1;
        priority['V'] = 5;
        priority['X'] = 10;
        priority['L'] = 50;
        priority['C'] = 100;
        priority['D'] = 500;
        priority['M'] = 1000;
    }

    int romanToInt(string s) {
        int ans = 0;
        
        bool flag = true;
        for (int i = 1; i < s.size(); i++)
        {
            if (priority[s[i]] > priority[s[i - 1]])
            {
                if (i == s.size() - 1)
                    flag = false;

                int diff = priority[s[i]] - priority[s[i - 1]];
                ans += diff;
                i++;
            }
            else
                ans += priority[s[i - 1]];
        }
        
        if (flag)
            ans += priority[s[s.size() - 1]];
        
        return ans;
    }
};