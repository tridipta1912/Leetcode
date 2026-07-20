class Solution {
public:
    int findIntegers(int n) {
        string s = "";
        while(n)
        {
            s += to_string(n % 2);
            n /= 2;
        }
        n = s.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(n + 1, 0)));
        dp[n][1][0] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '1') 
            {
                dp[i][1][1] += dp[i + 1][1][0];
                dp[i][0][0] += (dp[i + 1][1][0] + dp[i + 1][1][1] + dp[i + 1][0][1] + dp[i + 1][0][0]);
                dp[i][0][1] += dp[i + 1][0][0];
            }
            else            
            {
                dp[i][1][0] += (dp[i + 1][1][0] + dp[i + 1][1][1]);
                dp[i][0][0] += (dp[i + 1][0][1] + dp[i + 1][0][0]);
                dp[i][0][1] += dp[i + 1][0][0];
            }
        }

        return (dp[0][0][0] + dp[0][1][0] + dp[0][0][1] + dp[0][1][1]);
    }
};