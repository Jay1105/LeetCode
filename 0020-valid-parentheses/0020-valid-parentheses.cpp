class Solution {
public:

    bool check(char a, char b)
    {
        if ((a == '[' && b == ']') || (a == '(' && b == ')') || (a == '{' && b == '}'))
            return true;
        else
            return false;
    }

    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if (st.empty() || !check(st.top(), s[i]))
                    return false;
                st.pop();
            }
        }

        if (!st.empty())
            return false;
        return true;
    }
};