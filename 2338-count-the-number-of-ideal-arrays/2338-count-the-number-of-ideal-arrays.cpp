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
        for(ll i = 1; i <= n; i++)  inv_fact[i] = inv(fact[i]);

        auto C = [&](ll n, ll r) -> long long
        {
            if(r > n || r < 0 || n < 0)   return 0LL;
            ll ans = fact[n];
            ans *= inv_fact[r], ans %= MOD;
            ans *= inv_fact[n - r], ans %= MOD;
            return ans;
        };

        vector<vector<ll>> cnt(M + 1, vector<ll>(32, 0LL));
        vector<ll> count(32);
        vector<vector<ll>> div(M + 1);
        
        for(ll i = 1; i <= M; i++)
        {
            for(ll j = 2 * i; j <= M; j += i)   div[j].push_back(i);
        }

        cnt[1][1] = 1;
        count[1] = 1;
        for(ll i = 2; i <= M; i++)
        {
            cnt[i][1] = 1;
            for(auto x : div[i])
            {
                for(ll j = 0; j < 31; j++)  cnt[i][j + 1] += cnt[x][j], cnt[i][j + 1] %= MOD;
            }
            for(ll j = 1; j < 32; j++)  
            {
                count[j] += cnt[i][j];
                count[j] %= MOD;
            }
        }

        ll ans = 0;
        for(ll i = 1; i <= min(n, 31); i++)
        {
            ans += ((count[i] * C(n - 1, i - 1)) % MOD), ans %= MOD;
        }
        
        return ans;
    }
};