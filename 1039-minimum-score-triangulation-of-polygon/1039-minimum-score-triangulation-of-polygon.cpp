class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        using ll = int;
        constexpr ll INF = 1e9;
        ll n = values.size();
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        for(ll len = 3; len <= n; len++)
        {
            for(ll i = 0; i + len - 1 < n; i++)
            {
                ll j = i + len - 1;
                dp[i][j] = INF;
                for(ll k = i + 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};