class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        int tot = 0;
        for(int len = 1; len <= n; len++)
        {
            for(int i = 0; i + len < n; i++)
            {
                int j = i + len;
                if(j)   dp[i][j] = max(dp[i][j], piles[j] - dp[i][j - 1]);
                if(i + 1 < n)   dp[i][j] = max(dp[i][j], piles[i] - dp[i + 1][j]);
            }
        }
        return (2 * dp[0][n - 1] > tot);
    }
};