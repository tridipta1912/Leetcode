class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        vector<ll> dp(k);
        dp[0] = 1;
        ll tot = 1, sum = 0;
        for(auto x : nums)
        {
            tot *= 2, tot %= MOD;
            sum += x;
            
            for(ll i = k - 1; i >= x; i--)  dp[i] += dp[i - x], dp[i] %= MOD;
        }

        if(sum < 2 * k) return 0;
        
        for(ll i = 0; i < k; i++)   tot -= (2 * dp[i]), tot = (tot % MOD + MOD) % MOD;
        return tot;
    }
};