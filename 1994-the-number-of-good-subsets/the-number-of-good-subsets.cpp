class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        using ll = int;
        constexpr ll primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        constexpr ll M = (1 << 10);
        constexpr ll MOD = 1e9 + 7;

        vector<long long> dp(M);
        dp[0] = 1;

        for(auto &x : nums)
        {
            bool can = true;
            ll val = 0;
            for(ll i = 0; i < 10; i++)
            {
                if(x % primes[i] == 0)  x /= primes[i], val |= (1 << i);
                if(x % primes[i] == 0)  can = false;
            }
            if(!can) continue;
            for(ll i = 0; i < M; i++)
            {
                if((i & val) == 0)  dp[i | val] += dp[i], dp[i | val] %= MOD;
            }
        }

        long long ans = 0;
        for(ll i = 1; i < M; i++)   ans += dp[i], ans %= MOD;
        return static_cast<int>(ans);
    }
};