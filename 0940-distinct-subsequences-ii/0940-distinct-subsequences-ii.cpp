class Solution {
public:
    int distinctSubseqII(string s) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        ll n = s.length();
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = i - 1; j >= 0; j--)
            {
                dp[i] += dp[j];
                dp[i] %= MOD;
                if(j && s[j - 1] == s[i - 1])   break;
            }
        }
        ll ans = 0;
        for(ll i = 1; i <= n; i++)  ans += dp[i], ans %= MOD;
        return (int)(ans);
    }
};