class Solution {
public:
    int distinctSubseqII(string s) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        ll n = s.length();
        ll ans = 0, prev = 1;
        vector<ll> lst(26, 0);
        for(ll i = 1; i <= n; i++)
        {
            ans += prev;
            ans %= MOD;
            ans -= lst[s[i - 1] - 'a'];
            ans = (ans % MOD + MOD) % MOD;
            ans += prev, ans %= MOD;
            lst[s[i - 1] - 'a'] = prev;
            prev = ans;
            ans = 0;
        }
        return (int)((prev - 1 + MOD) % MOD);
    }
};