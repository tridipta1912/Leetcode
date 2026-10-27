class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.length();
        constexpr int INF = 1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, INF)));
        for(int len = 1; len <= n; len++)
        {
            for(int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                if (len == 1)   dp[i][j][1] = 0;
                else if (len == 2)
                {
                    dp[i][j][1] = 0;   dp[i][j][1] += (s[i] != s[j]);
                }
                else
                {
                    dp[i][j][1] = (s[i] != s[j]) + dp[i + 1][j - 1][1];
                }
            }
        }

    
        for(int r = 2; r <= k; r++)
        {
            for(int len = 1; len <= n; len++)
            {
                for(int i = 0; i + len - 1 < n; i++)
                {
                    int j = i + len - 1;
                    for(int mid = i; mid + 1 <= j; mid++)
                    {
                        dp[i][j][r] = min(dp[i][j][r], dp[i][mid][r - 1] + dp[mid + 1][j][1]);
                        dp[i][j][r] = min(dp[i][j][r], dp[i][mid][1] + dp[mid + 1][j][r - 1]);
                    }
                }
            }
        }

        return dp[0][n - 1][k];
    }
};