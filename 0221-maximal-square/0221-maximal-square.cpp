class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!i || !j)    dp[i][j] += (grid[i][j] == '1');
                else
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                    if(grid[i][j] == '1')   dp[i][j]++;
                    else    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j] * dp[i][j]);
            }
        }

        return ans;
    }
};