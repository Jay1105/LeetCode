class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        int op1, op2;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                
                if (tokens[i] == "+")
                    st.push(op1 + op2);
                else if (tokens[i] == "-")
                    st.push(op1 - op2);
                else if (tokens[i] == "*")
                    st.push(op1 * op2);
                else
                    st.push(op1 / op2);
            }
            else
                st.push(stoi(tokens[i]));
        }
        
        int ans = st.top();
        
        return ans;
    }
};