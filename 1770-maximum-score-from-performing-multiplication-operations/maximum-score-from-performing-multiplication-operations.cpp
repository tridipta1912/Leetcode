class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        using ll = long long;
        ll m = multipliers.size();
        ll n = nums.size();
        constexpr ll INF = 1e18;
        vector<vector<ll>> dp(m + 1, vector<ll>(m + 1, -INF));

        ll ans = -INF;
        dp[0][0] = 0;
        for(ll len = 1; len <= m; len++)
        {
            for(ll i = 0; i <= len; i++)
            {
                ll j = len - i;
                ll ni = i - 1;
                ll nj = n - j - 1;
                if(i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + multipliers[len - 1] * nums[i - 1]);

                if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + multipliers[len - 1] * nums[n - j]);

                if(len == m)    ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};