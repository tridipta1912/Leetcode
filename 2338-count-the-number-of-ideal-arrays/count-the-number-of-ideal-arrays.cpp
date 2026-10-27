class Solution {
public:
    int idealArrays(int n, int M) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;

        auto binpow = [&](ll a, ll b)
        {
            ll cur = 1;
            while(b)
            {
                if((b & 1)) cur *= a, cur %= MOD;
                b >>= 1;
                a *= a;
                a %= MOD;
            }
            return cur;
        };

        auto inv = [&](ll x)
        {
            return binpow(x, MOD - 2);
        };

        vector<ll> fact(n + 1, 1LL), inv_fact(n + 1, 1LL);
        for(ll i = 2; i <= n; i++)  fact[i] = (fact[i - 1] * i), fact[i] %= MOD;
        inv_fact[n] = inv(fact[n]);
        for(ll i = n - 1; i >= 0; i--)  inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;

        auto C = [&](ll n, ll r) -> long long
        {
            if(r > n || r < 0 || n < 0)   return 0LL;
            ll ans = fact[n];
            ans *= inv_fact[r], ans %= MOD;
            ans *= inv_fact[n - r], ans %= MOD;
            return ans;
        };

        vector<vector<ll>> cnt(M + 1, vector<ll>(1, 0LL));
        array<ll, 15> count;
        fill(begin(count), end(count), 0LL);
        
        cnt[1].emplace_back(0);
        cnt[1][1] = 1;
        
        for(ll i = 1; i <= M; i++)
        {
            for(ll j = 2 * i; j <= M; j += i)   
            {
                if(cnt[j].size() <= 1) cnt[j].emplace_back(0LL);
                cnt[j][1] = 1;
                for(ll r = 0; r < cnt[i].size(); r++)  
                {
                    while(cnt[j].size() <= r + 1) cnt[j].emplace_back(0LL);
                    cnt[j][r + 1] += cnt[i][r], cnt[j][r + 1] %= MOD;
                }
            }
            for(ll j = 1; j < cnt[i].size(); j++)  
            {
                count[j] += cnt[i][j];
                count[j] %= MOD;
            }
        }

        ll ans = 0;
        for(ll i = 1; i <= min(n, 14); i++)
        {
            ans += ((count[i] * C(n - 1, i - 1)) % MOD), ans %= MOD;
        }
        
        return ans;
    }
};