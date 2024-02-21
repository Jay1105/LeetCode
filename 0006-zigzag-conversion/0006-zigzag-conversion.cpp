class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char> > v(numRows);
        
        int k = 0;
        bool flag = true;
        
        if (numRows == 1)
            return s;

        for (int i = 0; i < s.size(); i++)
        {
            if (flag)
            {
                v[k].push_back(s[i]);
                k++;
                if (k == numRows)
                {
                    k = numRows - 2;
                    flag = false;
                }
            }
            else
            {
                v[k].push_back(s[i]);
                k--;
                if (k == -1)
                {
                    k = 1;
                    flag = true;
                }
            }
        }
        
        string ans = "";
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < v[i].size(); j++)
                ans += v[i][j];
        }
        return ans;
    }
};