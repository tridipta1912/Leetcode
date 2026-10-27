class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        using ll = long long;
        constexpr int MOD = 1e9 + 7;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<ll>> dp(m, vector<ll>(k, 0));
        dp[0][grid[0][0] % k] = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0) continue;

                vector<ll> curr(k, 0);

                for(int modd = 0; modd < k; modd++)
                {
                    if(i > 0) curr[(modd + grid[i][j]) % k] += dp[j][modd], curr[(modd + grid[i][j]) % k] %= MOD;
                    if(j > 0) curr[(modd + grid[i][j]) % k] += dp[j - 1][modd], curr[(modd + grid[i][j]) % k] %= MOD;
                }

                dp[j] = curr;
            }
        }

        return dp[m - 1][0];
    }
};