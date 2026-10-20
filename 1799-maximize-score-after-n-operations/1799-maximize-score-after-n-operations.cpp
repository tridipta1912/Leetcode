class Solution {
public:
    int maxScore(vector<int>& nums) {
        using ll = int;
        ll n = nums.size();
        ll m = 1 << n;

        vector<unordered_map<ll, ll>> G(n);
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
                for(ll j = i + 1; j < n; j++)
                {
                    if(((msk >> i) & 1) == 0 && ((msk >> j) & 1) == 0)
                    {
                        dp[msk | (1 << i) | (1 << j)] = max(dp[msk] + op * G[i][j], dp[msk | (1 << i) | (1 << j)]);
                    }
                }
            }
        }

        return dp.back();
    }
};