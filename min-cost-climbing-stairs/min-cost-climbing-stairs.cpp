class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        using ll = long long;
        vector<ll> dp(cost.size());
        for(ll i = 0; i < cost.size(); i++)
        {
            if(i <= 1)  dp[i] = cost[i];
            else        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp.back(), dp[cost.size() - 2]);
    }
};