class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        using ll = int;
        ll n = stoneValue.size();
        vector<ll> pref(n);
        for(ll i = 0; i < n; i++)
        {
            pref[i] = stoneValue[i];
            if(i)   pref[i] += pref[i - 1];
        }

        auto sum = [&](ll l, ll r)
        {
            ll ans = pref[r];
            if(l)   ans -= pref[l - 1];
            return ans;
        };

        vector<vector<ll>> dp(n, vector<ll>(n, 0));

        for(ll len = 2; len <= n; len++)
        {
            for(ll i = 0; i + len - 1 < n; i++)
            {
                ll j = i + len - 1;
                for(ll k = i; k < j; k++)
                {
                    ll sum1 = sum(i, k);
                    ll sum2 = sum(k + 1, j);
                    if(sum1 <= sum2) dp[i][j] = max(dp[i][j], sum1 + dp[i][k]);
                    if(sum2 <= sum1) dp[i][j] = max(dp[i][j], sum2 + dp[k + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};