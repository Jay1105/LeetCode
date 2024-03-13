class Solution {
public:
    string simplifyPath(string path)
    {
        path = path + '/';
        stack<string> st;
        int n = path.size();
        
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (path[i] == '/')
            {
                if (path.substr(i - cnt, cnt) == "..")
                {
                    if (!st.empty())
                        st.pop();
                }
                else if (cnt == 1)
                {
                    if (path[i - 1] != '.')
                        st.push(path.substr(i - cnt, cnt));
                }
                else if (cnt)
                    st.push(path.substr(i - cnt, cnt));

                cnt = 0;
            }
            else
                cnt += 1;
        }
        
        string ans = "/";
        
        while (!st.empty())
        {
            string temp = st.top();
            temp = "/" + temp;
            st.pop();
            ans = temp + ans;
        }
        
        if (ans.size() > 1)
            ans.erase(ans.size() - 1);

        return ans;
    }
};