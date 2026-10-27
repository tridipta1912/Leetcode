class Solution
{
    using ll = long long;

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals)
    {
        int n = intervals.size();

        vector<array<int, 2>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {intervals[i][1], i};

        sort(a.begin(), a.end());

        vector<vector<ll>> dp(n + 1, vector<ll>(5));
        vector<vector<vector<int>>> ans(n + 1, vector<vector<int>>(5));

        for (int i = 1; i <= n; i++)
        {
            int id = a[i - 1][1];
            int l = intervals[id][0];

            int p = lower_bound(a.begin(), a.begin() + i - 1, l,
                [](const array<int, 2>& x, int v)
                {
                    return x[0] < v;
                }) - a.begin();

            for (int k = 0; k <= 4; k++)
            {
                dp[i][k] = dp[i - 1][k];
                ans[i][k] = ans[i - 1][k];

                if (k)
                {
                    ll val = dp[p][k - 1] + intervals[id][2];
                    vector<int> cur = ans[p][k - 1];
                    cur.push_back(id);
                    sort(cur.begin(), cur.end());

                    if (val > dp[i][k] ||
                        (val == dp[i][k] && cur < ans[i][k]))
                    {
                        dp[i][k] = val;
                        ans[i][k] = cur;
                    }
                }
            }
        }

        ll best = 0;
        vector<int> res;

        for (int k = 1; k <= 4; k++)
        {
            if (dp[n][k] > best ||
                (dp[n][k] == best && ans[n][k] < res))
            {
                best = dp[n][k];
                res = ans[n][k];
            }
        }

        return res;
    }
};