class Solution {
public:
    int countVowelPermutation(int n) 
    {
        long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(2,vector<long long>(5,0));
        for(long long i = 0; i < 5; i++)  dp[0][i] = 1;

        for(long long i = 1; i < n; i++)
        {
            dp[i % 2][0] = ((dp[(i - 1) % 2][1] + dp[(i - 1) % 2][2]) % MOD + dp[(i - 1) % 2][4]) % MOD;
            dp[i % 2][1] = (dp[(i - 1) % 2][0] + dp[(i - 1) % 2][2]) % MOD;
            dp[i % 2][2] = (dp[(i - 1) % 2][1] + dp[(i - 1) % 2][3]) % MOD;
            dp[i % 2][3] = (dp[(i - 1) % 2][2]) % MOD;
            dp[i % 2][4] = (dp[(i - 1) % 2][2] + dp[(i - 1) % 2][3]) % MOD;
        }

        long long ans = 0;

        for(long long i = 0; i < 5; i++)  ans += dp[(n - 1) % 2][i], ans %= MOD;

        return int(ans);
    }
};