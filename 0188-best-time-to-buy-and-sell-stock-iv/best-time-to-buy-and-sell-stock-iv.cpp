class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        using ll = long long;
        ll n = prices.size();
        const ll INF = (ll)(1e18);
        vector<vector<array<ll, 2>>> dp(n, vector<array<ll, 2>>(k + 1, {0, -INF}));
        //dp[i][j][0] ->Maximum profit after jth transaction at ith index
        //dp[i][j][1] -> Minimum stock u bought after jth transaction
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                if(i > 0) 
                {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j][0]); 
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j][1]); 
                }

                if(j > 0 && i > 0) 
                {
                    dp[i][j][0] = max(dp[i][j][0], prices[i] + dp[i - 1][j][1]);            
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] - prices[i]);       
                }
                if(i == 0 && j > 0) 
                {
                    dp[i][j][1] = max(dp[i][j][1], -(1LL) * prices[i]); 
                }
            }
        }
        ll ans = 0;
        for(int j = 1; j <= k; j++)
        {
            ans = max(ans, dp[n - 1][j][0]);
        }
        return (int)ans;
    }
};