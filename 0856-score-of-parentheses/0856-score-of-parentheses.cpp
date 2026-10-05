class Solution {
public:
    int scoreOfParentheses(string s) {
        using ll = long long;
        ll n = s.length();
        vector<int> pref(n);
        for(ll i = 0; i < n; i++)
        {
            pref[i] += ((s[i] == '(') ? 1 : -1);
            if(i)   pref[i] += pref[i - 1];
        }
        
        vector<vector<ll>> dp(n, vector<ll>(n, -1));
        for(ll len = 2; len <= n; len += 2)
        {
            for(ll i = 0; i + len <= n; i++)
            {
                ll j = i + len - 1;
                if(s[i] == '(' && s[j] == ')')
                {
                    if(len == 2)    dp[i][j] = 1;
                    else
                    {
                        if(dp[i + 1][j - 1] != -1)
                        {
                            dp[i][j] = (2 * dp[i + 1][j - 1]);
                        }
                        else
                        {
                            for(ll k = i; k < j; k++)
                            {
                                if(dp[i][k] != -1 && dp[k + 1][j] != -1)
                                {
                                    dp[i][j] = dp[i][k] + dp[k + 1][j];
                                }
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};