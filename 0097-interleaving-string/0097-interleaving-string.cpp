class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if(s1.length() + s2.length() != s3.length())    return false;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                int ptr = i + j;
                if(dp[i][j])
                {
                    if(i < n && s3[ptr] == s1[i])   dp[i + 1][j] = 1;
                    if(j < m && s3[ptr] == s2[j])   dp[i][j + 1] = 1;
                }
            }
        }
        return dp[n][m];
    }
};