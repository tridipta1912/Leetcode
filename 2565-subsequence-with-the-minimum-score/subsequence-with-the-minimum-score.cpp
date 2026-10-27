class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> pref(m, -1), suff(m, -1);
        int ans = m, ptr = 0;
        for(int i = 0; i < n; i++)
        {
            if(ptr < m && t[ptr] == s[i])
            {
                ans = min(ans, m - 1 - ptr);
                pref[ptr++] = i;
            }
        }
        ptr = m - 1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(ptr >= 0 && t[ptr] == s[i])
            {
                ans = min(ans, ptr);
                suff[ptr--] = i;
            }
        }
        queue<array<int, 2>> q;
        for(int i = 0; i < m; i++)  if(suff[i] != -1)   q.push({suff[i], i});
        q.push({n, m});

        for(int i = 0; i < m; i++)
        {
            if(pref[i] == -1)   break;
            
            while(q.front()[1] <= i)   q.pop();
            while(q.front()[0] <= pref[i]) q.pop();

            ans = min(ans, q.front()[1] - i - 1);
        }

        return ans;
    }
};