class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        reverse(s.begin(), s.end());
        dp[n][1] = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            for(auto x : digits)
            {
                dp[i][0] += dp[i + 1][0];
                string y = string(1, s[i]);
                if(x == y)   dp[i][1] += dp[i + 1][1];
                else if (x < y)
                {
                    dp[i][0] += dp[i + 1][1];
                }
            }
            if(i && digits[0] != "0")   dp[i][0]++;
        }

        return (dp[0][0] + dp[0][1]);
    }
};