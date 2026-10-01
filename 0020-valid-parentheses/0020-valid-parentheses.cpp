class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s)
        {
            if(c == '(')    st.push(0);
            else if (c == ')')
            {
                if(st.empty() || st.top() != 0) return false;
                st.pop();
            }
            if(c == '{')    st.push(1);
            else if (c == '}')
            {
                if(st.empty() || st.top() != 1) return false;
                st.pop();
            }
            if(c == '[')    st.push(2);
            else if (c == ']')
            {
                if(st.empty() || st.top() != 2) return false;
                st.pop();
            }
        }
        return (st.empty());
    }
};