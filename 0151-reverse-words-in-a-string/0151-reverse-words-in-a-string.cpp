class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        
        stack<string> st;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (temp == "" && s[i] == ' ')
                continue;
            else if (temp != "" && s[i] == ' ')
            {
                st.push(temp);
                temp = "";
            }
            else
                temp += s[i];
        }
        if (temp != "")
            st.push(temp);
        
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
            
            if (!st.empty())
                ans += ' ';
        }
        
        return ans;
    }
};