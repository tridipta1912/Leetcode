class Solution {
public:
    int distinctSubseqII(string s) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        ll n = s.length();
        vector<ll> dp(n + 1, 0);
        vector<ll> lst(26, 0);
        dp[0] = 1;
        for(ll i = 1; i <= n; i++)
        {
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
            if(lst[s[i - 1] - 'a'] > 0)   dp[i] -= dp[lst[s[i - 1] - 'a'] - 1];
            dp[i] = (dp[i] % MOD + MOD) % MOD;
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
            lst[s[i - 1] - 'a'] = i;
        }
        return (int)((dp.back() - 1 + MOD) % MOD);
    }
};