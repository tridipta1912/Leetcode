class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.length();
        vector<int> pref(n);
        for(int i = 0; i < n; i++)
        {
            pref[i] += (s[i] == '1');
            if(i)   pref[i] += pref[i - 1];
        }
        int cnt0 = count(s.begin(), s.end(), '0');
        int cnt1 = count(s.begin(), s.end(), '1');
        vector<bool> ans;
        for(auto st : strs)
        {
            bool b = true;
            int c0 = count(st.begin(), st.end(), '0');
            int c1 = count(st.begin(), st.end(), '1');
            if(c0 > cnt0 || c1 > cnt1)
            {
                b = false;
            }
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(st[i] == '?')
                {
                    if(cnt0 > c0)        c0++, st[i] = '0';
                    else if(cnt1 > c1)   c1++, st[i] = '1';
                }
                cnt += (st[i] == '1');
                if(cnt > pref[i])
                {
                    b = false;
                }
            }
            ans.push_back(b);
        }
        return ans;
    }
};