class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        using ll = int;

        ll n = grid.size();
        ll m = grid[0].size();
        ll M = m + n;

        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(M + 1)));

        if(grid[0][0] == ')')   return false;
        dp[0][0][1] = true;
        
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                for(ll k = 0; k <= M; k++)
                {
                    if(dp[i][j][k])
                    {
                        if(i + 1 < n)   
                        {
                            ll nk = k + ((grid[i + 1][j] == '(' ? 1 : -1));
                            if(nk >= 0) dp[i + 1][j][nk] = true;
                        }
                        if(j + 1 < m)   
                        {
                            ll nk = k + ((grid[i][j + 1] == '(' ? 1 : -1));
                            if(nk >= 0) dp[i][j + 1][nk] = true;
                        }
                    }
                }
            }
        }
        return (dp[n - 1][m - 1][0]);
    }
};