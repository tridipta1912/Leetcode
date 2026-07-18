class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        using ll = unsigned long long;
        vector<ll> dp(amount + 1, 0);
        dp[0] = 1LL;
        for(int i = 0; i < coins.size(); i++)
        {
            for(int w = coins[i]; w <= amount; w++) dp[w] += dp[w - coins[i]];
        }
        return (int)dp[amount];
    }
};