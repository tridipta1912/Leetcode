
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        using ll = long long;
        vector<ll> dp(n + 1, 1e18);
        dp[0] = 0;

        for (ll i = 0; i <= n; i++) 
        {
            ll x = ranges[i];
            if(x == 0)  continue;
            ll L = max(i - x, 0LL);
            ll R = min(i + x, (ll)n);

            ll minn = 1e18;

            for (ll j = L; j <= R; j++) 
            {
                minn = min(minn, dp[j]);
            }

            if (minn != 1e18) dp[R] = min(dp[R], minn + 1);

            if (i) dp[i] = min(dp[i - 1] + 1, dp[i]);
        }

        if (dp[n] == 1e18)
            return -1;

        return dp[n];
    }
};
