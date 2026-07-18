class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j + i <= n; j++) 
            {
                dp[i + j] = max(dp[i + j], max(dp[i], i) * j);
            }
        }
        return dp[n];
    }
};