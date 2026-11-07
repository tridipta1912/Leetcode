class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        using ll = long long;
        constexpr ll INF = 1e18;
        ll n = nums.size();

        vector<ll> a(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        ll m = a.size();

        vector<ll> bit(m + 1, 0), sum(m + 1, 0);

        auto update = [&](vector<ll>& b, ll idx, ll val)
        {
            for(; idx <= m; idx += idx & -idx)
                b[idx] += val;
        };

        auto query = [&](vector<ll>& b, ll idx)
        {
            ll res = 0;
            for(; idx > 0; idx -= idx & -idx)
                res += b[idx];
            return res;
        };

        vector<ll> median(n, -INF), cost(n, INF);

        for(ll i = 0; i < n; i++)
        {
            ll id = lower_bound(a.begin(), a.end(), nums[i]) - a.begin() + 1;

            update(bit, id, 1);
            update(sum, id, nums[i]);

            if(i >= x)
            {
                ll old = lower_bound(a.begin(), a.end(), nums[i - x]) - a.begin() + 1;
                update(bit, old, -1);
                update(sum, old, -nums[i - x]);
            }

            if(i >= x - 1)
            {
                ll l = 1, r = m;

                while(l < r)
                {
                    ll mid = (l + r) / 2;

                    if(query(bit, mid) >= (x + 1) / 2)
                        r = mid;
                    else
                        l = mid + 1;
                }

                median[i] = a[l - 1];

                ll cntLo = query(bit, l);
                ll sumLo = query(sum, l);
                ll totalSum = query(sum, m);

                cost[i] = median[i] * cntLo - sumLo
                        + (totalSum - sumLo)
                        - median[i] * (x - cntLo);
            }
        }

        vector<ll> minn(k + 1, INF);
        vector<vector<ll>> dp(n, vector<ll>(k + 1, INF));

        minn[0] = 0;

        for(ll i = 0; i < n; i++)
        {
            if(i >= x)
            {
                for(ll j = 0; j <= k; j++)
                    minn[j] = min(minn[j], dp[i - x][j]);
            }

            if(i >= x - 1)
            {
                for(ll j = 1; j <= k; j++)
                {
                    dp[i][j] = min(minn[j], minn[j - 1] + cost[i]);
                }
            }
        }

        ll ans = INF;

        for(ll i = 0; i < n; i++)
            ans = min(ans, dp[i][k]);

        return ans;
    }
};
