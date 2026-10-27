
class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        using ll = long long;
        constexpr ll N = 1e4 + 5;
        constexpr ll M = N + 31;
        constexpr ll MOD = 1e9 + 7;

        vector<ll> spf;
        vector<ll> primes;
        vector<bool> composite(31624, false);

        for (ll i = 2; i < 31624; i++) {
            if (!composite[i]) {
                primes.push_back(i);
                for (ll j = i * i; j < 31624; j += i)
                    composite[j] = true;
            }
        }

        auto binpow = [&](ll a, ll b)
        {
            ll ans = 1;
            while(b)
            {
                if(b & 1)   ans *= a, ans %= MOD;
                a *= a, a %= MOD;
                b /= 2;
            }
            return ans;
        };

        vector<ll> fact(M + 1, 1);
        vector<ll> invfact(M + 1, 1);

        for(ll i = 2; i <= M; i++)  fact[i] = fact[i - 1] * i, fact[i] %= MOD;
        invfact[M] = binpow(fact[M], MOD - 2);
        for(ll i = M - 1; i >= 0; i--)  invfact[i] = invfact[i + 1] * (i + 1), invfact[i] %= MOD;

        auto C = [&](ll n, ll k)
        {
            if(n <= 0 || k < 0 || n < k)    return 0LL;
            ll ans = fact[n];
            ans *= invfact[k], ans %= MOD;
            ans *= invfact[n - k], ans %= MOD;
            return ans;
        };

        vector<int> ans;
        for(auto x : queries)
        {
            ll n = x[0], k = x[1];
            ll ways = 1;

            for(ll r : primes)
            {
                if(r * r > k)  break;
                if(k % r == 0)
                {
                    ll cnt = 0;
                    while(k % r == 0)
                    {
                        k /= r;
                        cnt++;
                    }
                    ways *= C(cnt + n - 1, n - 1);
                    ways %= MOD;
                }
            }

            if(k > 1)
            {
                ways *= C(n, n - 1);
                ways %= MOD;
            }

            ans.push_back(static_cast<int>(ways));
        }
        return ans;
    }
};
