class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        n = s.length();
        reverse(s.begin(), s.end());

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(n + 2, 0)));
        dp[n][1][0] = 1;

        int ans = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int cnt = 0; cnt <= n; cnt++)
            {
                if(s[i] == '1') dp[i][1][cnt + 1] += dp[i + 1][1][cnt];
                else            dp[i][1][cnt] += dp[i + 1][1][cnt];

                for(int j = 0; j < s[i] - '0'; j++)
                {
                    if(j == 1)  dp[i][0][cnt + 1] += dp[i + 1][1][cnt];
                    else
                    {
                        dp[i][0][cnt] += dp[i + 1][1][cnt];
                    }
                }

                dp[i][0][cnt] += dp[i + 1][0][cnt] * 9;
                dp[i][0][cnt + 1] += dp[i + 1][0][cnt];
            }
        }

        for(int cnt = 0; cnt <= n; cnt++)   ans += cnt * (dp[0][0][cnt] + dp[0][1][cnt]);

        return ans;
    }
};