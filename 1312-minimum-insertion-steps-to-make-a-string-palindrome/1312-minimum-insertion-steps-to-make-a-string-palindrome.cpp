class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = 0;
        }

        for(int len = 1; len < n; len++)
        {
            for(int i = 0; i + len < n; i++)
            {
                int j = i + len;
                if(s[i] != s[j])    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                else    
                {
                    if(j - i <= 1) dp[i][j] = 0;
                    else dp[i][j] = min(dp[i + 1][j - 1], dp[i][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};