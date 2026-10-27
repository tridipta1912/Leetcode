class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        s = "4" + s;
        ll n = s.length();

        vector<bool> isPrime(10);
        isPrime[2] = true;
        isPrime[3] = true;
        isPrime[5] = true;
        isPrime[7] = true;

        vector<vector<ll>> dp(n, vector<ll>(k + 1, 0LL));
        vector<ll> summ(k + 1);
        dp[0][0] = 1;
        for(ll i = 1; i < n; i++)
        {
            if(i >= minLength)
            {
                ll j = i - minLength;
                ll dig = s[j] - '0';
                ll dig1 = s[j + 1] - '0';
                if(!isPrime[dig] && isPrime[dig1]) for(ll r = 0; r <= k; r++)  summ[r] += dp[j][r], summ[r] %= MOD;
            }      
            if(!isPrime[s[i] - '0']) for(ll j = 1; j <= k; j++)  dp[i][j] += summ[j - 1], dp[i][j] %= MOD;
        }

        return dp.back().back();
    }
};