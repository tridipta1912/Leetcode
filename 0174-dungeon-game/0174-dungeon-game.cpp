class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n = dungeon.size();
        int m = dungeon[0].size();
        auto find = [&](int x)
        {
            vector<vector<long long>> dp(n, vector<long long>(m, -1e10));
            dp[0][0] = x;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    dp[i][j] += dungeon[i][j];
                    if(dp[i][j] <= 0)   dp[i][j] = -1e10;
                    if(i + 1 < n)   dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                    if(j + 1 < m)   dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
                }
            }
            
            return (dp[n - 1][m - 1] >= 0);
        };

        int L = 1;
        int R = 1e9;
        int ans = 1e9;
        while(L <= R)
        {
            int M = L + (R - L) / 2;
            if(find(M))
            {
                ans = M;
                R = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }

        return ans;
    }
};