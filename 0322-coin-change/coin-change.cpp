class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        using ll = long long;
        vector<ll> dp(amount + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(auto x : coins) if(x <= i)  dp[i] = min(dp[i - x] + 1, dp[i]);
        }
        if(dp[amount] == 1e9)   return -1;
        return (int)dp[amount];
    }
};