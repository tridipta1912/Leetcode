class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        using ll = long long;
        ll n = types.size();
        vector<ll> dp(target + 1, 0LL);
        dp[0] = 1;
        constexpr ll MOD = 1e9 + 7;

        for(auto x : types)
        {
            ll count = x[0], marks = x[1];
            for(ll i = target; i >= 0; i--)
            {
                for(ll j = 1; j <= count; j++)
                {
                    if(i - marks * j >= 0)  dp[i] += dp[i - marks * j], dp[i] %= MOD;
                }
            }   
        }

        return dp.back();
    }
};