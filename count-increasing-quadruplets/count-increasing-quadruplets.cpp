class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        using ll = long long;
        ll n = nums.size();
        vector<vector<ll>> freq(2, vector<ll>(n + 1));

        auto update = [&](ll idx, ll x, ll val)
        {
            for(ll i = x; i <= n; i += i & (-i))    freq[idx][i] += val;
        };

        auto query = [&](ll idx, ll x)
        {
            ll sum = 0;
            for(ll i = x; i >= 1; i -= i & (-i))    sum += freq[idx][i];
            return sum;
        };

        ll ans = 0;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = i + 1; j < n; j++)
            {
                update(1, nums[j], 1);
            }
            for(ll j = i + 1; j < n; j++)
            {
                update(1, nums[j], -1);
                if(nums[j] < nums[i]) ans += query(0, nums[j] - 1) * ((query(1, n) - query(1, nums[i])));
            }
            update(0, nums[i], 1);
        }
        return ans;
    }
};