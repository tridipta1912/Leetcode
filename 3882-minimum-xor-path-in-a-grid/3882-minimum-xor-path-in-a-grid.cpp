class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        using ll = int;
        constexpr ll M = 1 << 10;
        ll n = grid.size();
        ll m = grid[0].size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(M, false)));
        dp[0][0][grid[0][0]] = 1;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                if(i)   
                {
                    for(ll k = 0; k < M; k++)   if(dp[i - 1][j][k]) dp[i][j][grid[i][j] ^ k] = true;
                }
                if(j)   
                {
                    for(ll k = 0; k < M; k++)   if(dp[i][j - 1][k]) dp[i][j][grid[i][j] ^ k] = true;
                }
            }
        }
        for(ll i = 0; i < M; i++)   if(dp[n - 1][m - 1][i]) return i;
        return 0;
    }
};