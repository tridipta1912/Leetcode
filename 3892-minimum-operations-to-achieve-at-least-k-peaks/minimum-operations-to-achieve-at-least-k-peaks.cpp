class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        using ll = int;
        constexpr ll INF = 1e9;
        if(k == 0)  return 0;
        if(k == a.size())  return -1;
        if(a.size() == 2)
        {
            return (a[0] == a[1]);
        }
        auto find = [&](vector<ll> &nums, bool b1 = false, bool b2 = false)
        {
            ll n = nums.size();
            vector<vector<ll>> dp(n + 2, vector<ll>(k + 1, INF));

            for(auto &x : dp)   x[0] = 0;
            for(ll i = 0; i < n; i++)
            {
                ll maxx = max(nums[(i + 1) % n], nums[(i - 1 + n) % n]);
                ll diff = max(maxx - nums[i] + 1, 0);
                for(ll j = 1; j <= k; j++)
                {
                    dp[i + 2][j] = dp[i + 1][j];
                    if(b1 && i == 0)    continue;
                    if(b2 && i == n - 1)    continue;
                    dp[i + 2][j] = min(dp[i][j - 1] + diff, dp[i + 2][j]);
                }
            }
            cout << dp[n + 1][k] << endl;
            return dp[n + 1][k];
        };

        ll ans = INF;

        ans = min(ans, find(a, 0, 1));
        ans = min(ans, find(a, 1, 0));
        ans = min(ans, find(a, 1, 1));
        return ((ans == INF) ? -1 : ans);
    }
};