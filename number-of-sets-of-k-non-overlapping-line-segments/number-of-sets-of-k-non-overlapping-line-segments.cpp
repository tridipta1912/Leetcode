class Solution {
public:
    int numberOfSets(int n, int k) {
        using ll = long long;
        vector<array<ll, 2>> dp(k + 1, {0, 0});
        const ll MOD = 1e9 + 7;
        for(ll i = 1; i <= n; i++)
        {
            vector<array<ll, 2>> ndp(k + 1, {0, 0});
            for(ll j = 1; j <= k; j++)
            {
                ndp[j][0] += dp[j][0]; ndp[j][0] %= MOD;
                ndp[j][0] += ndp[j - 1][1]; ndp[j][0] %= MOD;
                if(j == 1)  ndp[j][0] += 1, ndp[j][0] %= MOD;

                ndp[j][1] += dp[j][1]; ndp[j][1] %= MOD;
                ndp[j][1] += dp[j][0]; ndp[j][1] %= MOD;
            }
            swap(dp, ndp);
        }
        return dp[k][1];
    }
};