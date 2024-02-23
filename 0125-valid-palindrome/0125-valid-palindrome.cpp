class Solution {
public:
    bool isAlphaNumeric (char temp)
    {
        if (temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z' || temp >= '0' && temp <= '9')
            return true;
        return false;
    }

    bool isPalindrome(string s) {
        string t = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (isAlphaNumeric(s[i]))
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