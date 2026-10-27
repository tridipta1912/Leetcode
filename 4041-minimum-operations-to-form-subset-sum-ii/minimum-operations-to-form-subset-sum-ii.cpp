class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        using ll = int;
        constexpr ll INF = 1e9;
        vector<ll> dp(sum + 1, INF);
        dp[0] = 0;
        ll n = nums.size();
        for(ll i = 0; i < n; i++)
        {
            unordered_map<ll, ll> to_add;
            ll cur = 0;
            for(ll x = nums[i]; x > 0; x /= 2)
            {
                ll ncur = 0;
                for(ll y = x; y <= sum; y *= 2)
                {
                    if(to_add.find(y) != to_add.end()) 
                    {
                        break;
                    }
                    to_add[y] = (cur + ncur);
                    ncur++;
                }
                cur++;
            }
            to_add[0] = 0;
            vector<ll> ndp = dp;
            for (ll x = 0; x <= sum; x++) 
            {
                if (dp[x] == INF) continue;
                for (auto [nx, cost] : to_add) 
                {
                    if (x + nx > sum) continue;

                    ndp[x + nx] = min(ndp[x + nx], dp[x] + cost);
                }
            }

            swap(ndp, dp);
        }
        if(dp[sum] == INF) return -1;
        return dp[sum];
    }
};