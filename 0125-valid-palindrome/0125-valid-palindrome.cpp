class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]))
                t += s[i];
        }
        
        for (auto &x: t)
            x = tolower(x);
        
        bool flag = true;
        int n = t.size();
        
        for (int i = 0; i < n / 2; i++)
        {
            if (t[i] != t[n - i - 1])
                flag = false;
        }
        
        if (flag)
            return true;
        else
            return false;
    }
};