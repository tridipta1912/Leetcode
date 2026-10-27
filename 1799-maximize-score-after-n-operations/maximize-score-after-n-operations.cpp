class Solution {
public:
    int maxScore(vector<int>& nums) {
        using ll = int;
        ll n = nums.size();
        ll m = 1 << n;

        vector<vector<ll>> G(n, vector<ll>(n, 0));
        for(ll i = 0; i < n; i++)   for(ll j = i + 1; j < n; j++)   G[i][j] = __gcd(nums[i], nums[j]);

        vector<ll> dp(m, -2e9);
        dp[0] = 0;
        for(ll msk = 0; msk < m; msk++)
        {
            if(dp[msk] == -2e9)  continue;
            ll op = __builtin_popcount(msk);
            op = (op / 2) + 1;
            for(ll i = 0; i < n; i++)
            {
                if(((msk >> i) & 1) == 0)
                {
                    ll nmsk = msk | (1 << i);
                    for(ll j = i + 1; j < n; j++)
                    {
                        if(((msk >> j) & 1) == 0)
                        {
                            ll nsk = nmsk | (1 << j);
                            dp[nsk] = max(dp[nsk], dp[msk] + op * G[i][j]);
                        }
                    }
                }
            }
        }

        return dp.back();
    }
};