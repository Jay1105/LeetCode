class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int t = needle.size();
        
        if (t > n)
            return -1;
        if (t == n && haystack == needle)
            return 0;
        
        bool flag = false;
        int idx = -1;
        for (int i = 0; i <= n - t; i++)
        {
            if (haystack.substr(i, t) == needle)
            {
                idx = i;
                flag = true;
                break;
            }
        }
        
        return idx;
    }
};