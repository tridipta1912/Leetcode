class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int len = 1; len <= n; len++)
        {
            for(int i = 0; i + len - 1 < n; i++)
            {
                if(len == 1)    
                {
                    dp[i][i] = 1;
                    continue;
                }
                int j = i + len - 1;
                if(s[i] == s[j])    dp[i][j] = dp[i + 1][j - 1] + 2;
                if(i + 1 < n) dp[i][j] = max(dp[i][j], dp[i + 1][j]);
                if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};