class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        using ll = long long;
        ll n = s.length();
        set<string> st(wordDict.begin(), wordDict.end());

        vector<ll> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            string str = "";
            for(int j = i - 1; j >= 0; j--)
            {
                str += s[j];
                string x = str;
                reverse(x.begin(), x.end());
                if(dp[j] && st.count(x))  dp[i] = true;
            }
        }

        return dp[n];
    }
};