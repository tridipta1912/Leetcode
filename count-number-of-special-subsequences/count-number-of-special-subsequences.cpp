class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        using ll = long long;
        const ll MOD = 1e9 + 7;
        array<ll, 3> dp = {0, 0, 0};
        for(auto x : nums)
        {
            if(x == 0)  dp[x] += (dp[x] + 1), dp[x] %= MOD;
            else if(x == 1) dp[x] += (dp[x] + dp[x - 1]), dp[x] %= MOD;
            else if (x == 2) dp[x] += (dp[x] + dp[x - 1]), dp[x] %= MOD;
        }
        return dp[2];
    }
};