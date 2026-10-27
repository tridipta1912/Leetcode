class Solution {
public:
    int numSquares(int n) 
    {
        int k = sqrt(n) + 1;
        vector<int> dp(n + 1, 1e9);
        
        dp[0] = 0;
        for(int i = 0; i <= n; i++)
        {
            if(dp[i] == 1e9)    continue;
            for(int j = 0; j <= k; j++)
            {
                if((i + j * j) <= n) dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};