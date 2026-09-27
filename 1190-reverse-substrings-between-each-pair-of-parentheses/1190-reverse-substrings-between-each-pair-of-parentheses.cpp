class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> st;
        st.emplace_back();
        for(auto x : s)
        {
            if(x == '(')  st.emplace_back();
            else if (x == ')')
            {
                string rev = st.back();
                st.pop_back();
                reverse(rev.begin(), rev.end());
                if(!st.empty()) st.back() += rev;
                else
                {
                    st.push_back(rev);
                }
            }
            else if(x >= 'a' && x <= 'z')
            {
                st.back() += x;
            }
        }
        return st.back();
    }
};