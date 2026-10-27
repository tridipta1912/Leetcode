class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        using ll = int;
        constexpr ll INF = 1e9;
        unordered_map<ll, ll> dp;
        dp[0] = 0;
        ll n = nums.size();
        for(ll i = 0; i < n; i++)
        {
            unordered_map<ll, ll> to_add;
            ll cur = 0;
            for(ll x = nums[i]; x > 0; x /= 2)
            {
                to_add[x] = cur++;
            }
            cur = 0;
            for(ll x = nums[i]; x <= sum; x *= 2)
            {
                to_add[x] = cur++;
            }
            to_add[0] = 0;
            unordered_map<ll, ll> ndp = to_add;
            for(auto [x, y] : dp)
            {
                if(ndp.find(x) == ndp.end()) ndp[x] = y;
                ndp[x] = min(ndp[x], y);
                for(auto [nx, ny] : to_add)
                    {
                        if(nx + x <= sum) 
                        {
                            if(ndp.find(nx + x) == ndp.end()) ndp[x + nx] = y + ny;
                            ndp[x + nx] = min(ndp[x + nx], y + ny);
                        }
                    }
            }
            swap(ndp, dp);
        }
        if(dp.find(sum) == dp.end()) return -1;
        return dp[sum];
    }
};