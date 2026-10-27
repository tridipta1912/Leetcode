class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = dp[i + 1][j] + 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int minn = (1e9);
                for(int k = j; k < m; k++)
                {
                    if(minn == 0)   break;
                    minn = min(minn, dp[i][k]);
                    ans = max(ans, (k - j + 1) * minn);
                }
            }
        }

        return ans;
    }
};