class Solution {
public:
    vector<vector<string>> partition(string s) {
        using ll = long long;
        ll n = s.length();
        ll M = (1LL << (n - 1)) - 1;
        
        vector<vector<string>> ans;
        unordered_set<string> st;
        unordered_set<string> nst;
        auto check = [&](string &x)
        {
            if(st.count(x)) return true;
            if(nst.count(x))    return false;
            bool b = true;
            for(int i = 0; i < (x.length() / 2); i++)   b &= (x[i] == x[x.length() - 1 - i]);
            if(b)   st.insert(x);
            if(!b)  nst.insert(x);
            return b;
        };

        for(int mask = 0; mask <= M; mask++)
        {
            vector<string> st;
            string str = "";
            str += s[0];
            st.push_back(str);
            for(int i = 0; i < (n - 1); i++)
            {
                if(mask & (1LL << i))
                {
                    string str = "";
                    str += s[i + 1];
                    st.push_back(str);
                }
                else
                {
                    st[st.size() - 1] += s[i + 1];
                }
            }
            bool b = true;
            for(auto v : st)    b &= check(v);
            if(b)   ans.push_back(st);   
        }
        return ans;
    }
};